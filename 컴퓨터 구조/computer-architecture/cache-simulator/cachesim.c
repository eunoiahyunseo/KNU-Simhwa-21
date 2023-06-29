/*
 * computer architecture cache simulator programming assignment
 * date: 10-12-2021 16:10
 * student code: 2020111854, 2020115012
 * writer: shin chan-gyu
 * tester: lee jihyeon
 * description: set associative cache simulator
 * attention: -s={cache size} -a={set size} -b={block size} -f={trace file name}
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MISS_PENALTY 200
#define HIT_CYCLE 1
#define BYTE_SIZE 4
#define WORD_SIZE 4

int cache_size;
int block_size;
int set_size;

int num_of_sets;
int num_of_lines;
int num_of_words;

int total_hit;
int total_miss;
int total_dirty;

// for time of line structure to implement LRU policy
int op_count;

int memory_access;
int memory_index;

bool debug_mode = false;

// cache line
struct line
{
  int dirty;
  int valid;
  int tag;
  int *data;
  int time;
  int addr;
};

// memory cell
struct cell
{
  int addr;
  int valid;
  int *data;
};

struct line *cache;
struct cell *memory;

FILE *trace_fp;

void set_opt(int, char **);
void init();
void print_cache();
void write_cache(int, int);
void read_cache(int);
void run_cache();
void freelist();

void read_memory(int, int *);
void write_memory(struct line *);

int main(int ac, char *av[])
{
  // set cache, block size and set associativity
  set_opt(ac, av);

  // initialize cache and memory
  init();

  // run cache simulator
  run_cache();

  // free cache and memory
  freelist();

  return 0;
}

// read data from cache
void read_cache(int addr)
{
  int set = 0;
  int set_num = 0;
  int old_time = 0;
  int old_set_num = 0;
  int new_set_num = 0;
  struct line *line_ptr = NULL;

  // index bits of address
  set = ((addr / BYTE_SIZE) / num_of_words) % num_of_sets;

  new_set_num = set_size;

  // search a set to find data of address
  for (set_num = 0; set_num < set_size; set_num++)
  {
    line_ptr = &cache[set * set_size + set_num];

    // if valid bit of line is 1, and tag bits are same with address, hit
    if (line_ptr->valid == 1 && line_ptr->tag == ((addr / BYTE_SIZE) / num_of_words) / num_of_sets)
    {
      line_ptr->time = op_count;
      total_hit++;
      return;
      // if not, find lowest available entry
    }
    else if (line_ptr->valid == 0)
    {
      if (set_num < new_set_num)
      {
        new_set_num = set_num;
      }
    }
  }

  // if data of address is not cache, miss
  total_miss++;

  // read data from memory
  // if there is no free place at set, kick out oldest line (LRU policy)
  if (new_set_num == set_size)
  {
    old_time = INT_MAX;

    // search oldest line at set
    for (set_num = 0; set_num < set_size; set_num++)
    {
      line_ptr = &cache[set * set_size + set_num];

      if (old_time > line_ptr->time)
      {
        old_time = line_ptr->time;
        old_set_num = set_num;
      }
    }

    line_ptr = &cache[set * set_size + old_set_num];

    // if dirty bit of oldest line is 1, write to memory (write-back policy)
    if (line_ptr->dirty)
    {
      write_memory(line_ptr);
    }

    // override oldest line to new line from memory
    line_ptr->dirty = 0;
    line_ptr->valid = 1;
    line_ptr->addr = ((addr / BYTE_SIZE) / num_of_words);
    line_ptr->tag = ((addr / BYTE_SIZE) / num_of_words) / num_of_sets;
    read_memory(addr, line_ptr->data);
    line_ptr->time = op_count;
  }
  else
  {
    // if there is free place at set, fetch line from memory to lowest available entry
    line_ptr = &cache[set * set_size + new_set_num];

    line_ptr->dirty = 0;
    line_ptr->valid = 1;
    line_ptr->addr = ((addr / BYTE_SIZE) / num_of_words);
    line_ptr->tag = ((addr / BYTE_SIZE) / num_of_words) / num_of_sets;
    read_memory(addr, line_ptr->data);
    line_ptr->time = op_count;
  }
}

// write data to cache
void write_cache(int addr, int write_data)
{
  int set = 0;
  int set_num = 0;
  int old_time = 0;
  int old_set_num = 0;
  int new_set_num = 0;
  struct line *line_ptr = NULL;

  // index bits of address
  set = ((addr / BYTE_SIZE) / num_of_words) % num_of_sets;

  new_set_num = set_size;

  // search a set to find data of address
  for (set_num = 0; set_num < set_size; set_num++)
  {
    line_ptr = &cache[set * set_size + set_num];

    // if valid bit of line is 1, and tag bits are same with address, hit
    if (line_ptr->valid == 1 && line_ptr->tag == ((addr / BYTE_SIZE) / num_of_words) / num_of_sets)
    {
      // update line to new data
      line_ptr->dirty = 1;
      (line_ptr->data)[(addr / BYTE_SIZE) % num_of_words] = write_data;
      line_ptr->addr = ((addr / BYTE_SIZE) / num_of_words);
      line_ptr->time = op_count;
      total_hit++;
      return;
      // if not, find lowest available entry
    }
    else if (line_ptr->valid == 0)
    {
      if (set_num < new_set_num)
      {
        new_set_num = set_num;
      }
    }
  }

  // if data of address is not cache, miss
  total_miss++;

  // read data from memory
  // if there is no free place at set, kick out oldest line (LRU policy)
  if (new_set_num == set_size)
  {
    old_time = INT_MAX;

    // search oldest line at set
    for (set_num = 0; set_num < set_size; set_num++)
    {
      line_ptr = &cache[set * set_size + set_num];

      if (old_time > line_ptr->time)
      {
        old_time = line_ptr->time;
        old_set_num = set_num;
      }
    }

    line_ptr = &cache[set * set_size + old_set_num];

    // if dirty bit of oldest line is 1, write to memory (write-back policy)
    if (line_ptr->dirty)
    {
      write_memory(line_ptr);
    }

    // if block size is same with word size, we don't need to read line from memory
    if (block_size != WORD_SIZE)
    {
      read_memory(addr, line_ptr->data);
    }

    // write new data at line
    line_ptr->dirty = 1;
    line_ptr->valid = 1;
    line_ptr->tag = ((addr / BYTE_SIZE) / num_of_words) / num_of_sets;
    (line_ptr->data)[(addr / BYTE_SIZE) % num_of_words] = write_data;
    line_ptr->addr = ((addr / BYTE_SIZE) / num_of_words);
    line_ptr->time = op_count;
  }
  else
  {
    // if there is free place at set, fetch line to lowest available entry
    line_ptr = &cache[set * set_size + new_set_num];

    // if block size is same with word size, we don't need to read line from memory
    if (block_size != WORD_SIZE)
    {
      read_memory(addr, line_ptr->data);
    }

    // write new data at line
    line_ptr->dirty = 1;
    line_ptr->valid = 1;
    line_ptr->tag = ((addr / BYTE_SIZE) / num_of_words) / num_of_sets;
    (line_ptr->data)[(addr / BYTE_SIZE) % num_of_words] = write_data;
    line_ptr->addr = ((addr / BYTE_SIZE) / num_of_words);
    line_ptr->time = op_count;
  }
}

// print all value of cache
void print_cache()
{
  int index;
  int set_num;
  double amac;
  double miss_rate;

  struct line *line_ptr;

  for (index = 0; index < num_of_sets; index++)
  {
    line_ptr = &cache[index * set_size];

    printf("%d: ", index);

    for (set_num = 0; set_num < set_size; set_num++)
    {
      line_ptr = &cache[index * set_size + set_num];

      if (line_ptr->dirty)
      {
        total_dirty++;
      }

      if (set_num != 0)
      {
        printf("   ");
      }

      for (int i = 0; i < num_of_words; i++)
      {
        printf("%.8X ", (line_ptr->data)[i]);
      }

      printf("v: %d d: %d", line_ptr->valid, line_ptr->dirty);
      if (debug_mode == true)
      {
        printf(" last time: %d\n", line_ptr->time);
      }
      else
      {
        printf("\n");
      }
    }
  }

  miss_rate = (double)total_miss / (total_hit + total_miss);
  amac = (double)(memory_access * MISS_PENALTY + (total_hit + total_miss) * HIT_CYCLE) / (total_hit + total_miss);

  printf("\ntotal number of hits: %d\n", total_hit);
  printf("total number of misses: %d\n", total_miss);
  printf("miss rate: %.1f%%\n", miss_rate * 100.0);
  printf("total number of dirty blocks: %d\n", total_dirty);
  printf("average memory access cycle: %.1f\n", amac);

  if (debug_mode == true)
  {
    total_dirty = 0;
    printf("\n-------------------------------\n\n");
  }
}

// set cache, block size and set associativity
void set_opt(int ac, char *av[])
{
  int param_opt;
  char *param_buf;

  while ((param_opt = getopt(ac, av, "s:b:a:f:g")) != -1)
  {
    switch (param_opt)
    {
    case 's':
      param_buf = optarg;
      cache_size = atoi(++param_buf);
      break;
    case 'b':
      param_buf = optarg;
      block_size = atoi(++param_buf);
      break;
    case 'a':
      param_buf = optarg;
      set_size = atoi(++param_buf);
      break;
    case 'f':
      param_buf = optarg;
      trace_fp = fopen(++param_buf, "r");
      break;
    case 'g':
      debug_mode = true;
      break;
    case '?':
      printf("parameter error");
      break;
    }
  }
}

// run cache simulator
void run_cache()
{
  int addr;
  char mode;
  int write_data;

  while (fscanf(trace_fp, "%08x %c", &addr, &mode) != EOF)
  {
    if (mode == 'W')
    {
      fscanf(trace_fp, "%d", &write_data);
      op_count++;
      write_cache(addr, write_data);
    }
    else
    {
      op_count++;
      read_cache(addr);
    }

    if (debug_mode == true)
    {
      if (mode == 'W')
      {
        printf("%08X %c %d\n", addr, mode, write_data);
      }
      else
      {
        printf("%08X R\n", addr);
      }

      print_cache();
    }
  }

  if (debug_mode == false)
  {
    print_cache();
  }
}

// initialize cache and memory
void init()
{
  int line;
  int cell;

  num_of_sets = cache_size / (block_size * set_size);
  num_of_lines = cache_size / block_size;
  num_of_words = block_size / WORD_SIZE;
  cache = (struct line *)calloc(num_of_lines, sizeof(struct line));
  memory = (struct cell *)calloc(BUFSIZ, sizeof(struct cell));

  for (line = 0; line < num_of_lines; line++)
  {
    cache[line].data = (int *)calloc(num_of_words, sizeof(int));
  }

  for (cell = 0; cell < BUFSIZ; cell++)
  {
    memory[cell].valid = 0;
    memory[cell].data = (int *)calloc(num_of_words, sizeof(int));
  }
}

// free cache and memory
void freelist()
{
  int line;
  int cell;

  for (line = 0; line < num_of_lines; line++)
  {
    free(cache[line].data);
  }

  for (cell = 0; cell < BUFSIZ; cell++)
  {
    free(memory[cell].data);
  }

  free(cache);
  free(memory);
  free(trace_fp);
}

// write line to memory
void write_memory(struct line *line_ptr)
{
  int cell;
  int new_cell;

  memory_access++;

  for (cell = 0; cell < BUFSIZ; cell++)
  {
    if (memory[cell].valid == 1 && memory[cell].addr == line_ptr->addr)
    {
      memcpy(memory[cell].data, line_ptr->data, num_of_words * sizeof(int));
      return;
    }
    else if (memory[cell].valid == 0)
    {
      new_cell = cell;
      break;
    }
  }

  memory[new_cell].addr = line_ptr->addr;
  memory[new_cell].valid = 1;
  memcpy(memory[new_cell].data, line_ptr->data, num_of_words * sizeof(int));
}

// read line from memory
void read_memory(int addr, int *data)
{
  int cell;
  int target_addr;

  memory_access++;

  target_addr = (addr / BYTE_SIZE) / num_of_words;

  for (cell = 0; cell < BUFSIZ; cell++)
  {
    if (memory[cell].valid == 1 && memory[cell].addr == target_addr)
    {
      memcpy(data, memory[cell].data, num_of_words * sizeof(int));
      return;
    }
  }
}