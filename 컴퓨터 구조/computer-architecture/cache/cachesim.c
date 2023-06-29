/**
 * @file cachesim.c
 * @author hyunseo lee 2021113490 (heart20021010@gmail.com)
 * @author Chanho Kim 2021114818 (coolho123@naver.com)
 * @brief cache simulator for computer architecture assignment 2022
 * @version 0.1
 * @date 2022-11-18
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#define INITIAL_BUFFER_SIZE 512
#define ONE_WORD_SIZE 4
#define ONE_BYTE_SIZE 4

#define MISS_PENALTY_CYCLE 200
#define HIT_CYCLE 1

typedef int one_word;

// parameter info
int cache_size;
int block_size;
int associative_size;
FILE *tracefile_fp;

int set_num, word_num;

int extern_lru_value;

// statistics values
int total_hit;
int total_miss;
int total_dirty;

int memory_access_count;

/**
 * @struct cache_line_ -> cache_line
 * @brief {
 *  for cache line element
 *  1. valid -> check not a trash value
 *  2. dirty -> R/W check ( for write back )
 *  3. tag
 *  4. data
 *  5. lru_val -> lru_val is high is evict
 *  6. addr -> for evict data ( LRU )
 * }
 */
typedef struct cache_line_
{
    int valid;
    int dirty;
    int tag;
    // data have to dynamic -> change with block size
    // block size 8B -> 2word -> sizeof(int) = 4byte = a word
    one_word *data;
    int lru_val;
    int addr;
} cache_line;

// cache_line* [] -> that's a cache
// !CACHE
cache_line *cache;

/**
 * @struct main_memory_line_ -> main_memory
 * @brief {
 *  for main memory initializer
 *  we can't init 4G MM -> so save the data which have value
 *  and other address data value is assume with 0 value
 *  1. addr
 *  2. data
 *  3. check_sum -> for save to MM ( 1 means valid value in MM )
 * }
 */
typedef struct main_memory_line_
{
    unsigned int addr;
    int check_sum;
    one_word *data;
} main_memory_line;

// main_memory_line* [] -> that's a main memory
// !MAIN MEMORY
main_memory_line *main_memory;

void write_cache(unsigned int addr, one_word data);
void read_cache(unsigned int addr);

void save_MM(cache_line *cache_line_ptr);
void read_MM(unsigned int addr, cache_line *cache_line_ptr);

void writeProcess(unsigned addr, int data, cache_line *cache_line_ptr);
void readProcess(unsigned addr, cache_line *cache_line_ptr);

void print_cache();
void print_mm();

void free_process();

int main(int ac, char *av[])
{
    int parameter_return;
    // parameter parsing
    /**
     * @brief
     * -1 means getopt() parse all options
     */
    while ((parameter_return = getopt(ac, av, "s:b:a:f:")) != -1)
    {
        switch (parameter_return)
        {
        case 's':
            // optarg include '=' so we have to add 1
            cache_size = atoi((char *)++optarg);
            break;
        case 'b':
            block_size = atoi((char *)++optarg);
            break;
        case 'a':
            associative_size = atoi((char *)++optarg);
            break;
        case 'f':
            tracefile_fp = fopen(++optarg, "r+");
            break;
        case '?':
            printf("error occured in input parameter");
            break;
        }
    }

    // start init cache and MM(Main Memory)
    int i;

    set_num = cache_size / (block_size * associative_size);
    word_num = (block_size / ONE_BYTE_SIZE);
    extern_lru_value = 0;

    // initialize with 0 -> we have to use calloc
    cache = (cache_line *)calloc(set_num * associative_size, sizeof(cache_line));
    for (i = 0; i < set_num * associative_size; i++)
        cache[i].data = (one_word *)calloc(block_size / ONE_WORD_SIZE, sizeof(one_word));

    // initialize size 512 with main_memory_line struct
    /**
     * @brief
     * 32bit address
     */
    main_memory = (main_memory_line *)calloc(INITIAL_BUFFER_SIZE, sizeof(main_memory_line));
    for (i = 0; i < INITIAL_BUFFER_SIZE; i++)
    {
        main_memory[i].data = (one_word *)calloc(block_size / ONE_WORD_SIZE, sizeof(one_word));
        // for memory is valid
        main_memory[i].check_sum = 0;
    }

    // for W/R trace file -> read sample.trc file
    /**
     * @brief read tracefile accurate format
     * 00010008 W 33
     * 0001000C W 4
     * 00010000 R
     * -> 8(hex)   R|W   W?data
     */

    // addr is 32bit -> 4byte -> int is 4byte
    unsigned int addr;
    int temp_write_data;
    char memory_access_type;
    while (fscanf(tracefile_fp, "%8x %c", &addr, &memory_access_type) != EOF)
    {
        // if memory access type is Write

        // plus lru value for time goes on
        extern_lru_value++;
        if (memory_access_type == 'W')
        {
            fscanf(tracefile_fp, "%d", &temp_write_data);
            // printf("%08X %c %d \n", addr, memory_access_type, temp_write_data);

            // we have to write data to cache
            write_cache(addr, temp_write_data);
        }
        else if (memory_access_type == 'R')
        {
            // printf("%08X %c \n", addr, memory_access_type);
            read_cache(addr);
        }
        else
            exit(1);
    }

    print_cache();

    /**
     * @brief
     * 1. free cache all data
     * 2. free main memory all data
     * 3. free cache
     * 4. free main memory
     * 5. close tracefile
     */
    free_process();

    return 0;
}

void write_cache(unsigned int addr, one_word data)
{
    int associative_offset, entry_set_offset, temp_write_data, data_offset, cache_line_offset;
    unsigned index, tag;
    cache_line *cache_line_ptr;

    // (00000000 00000001 00000000 00)=tag (001)=index (000)=byte offset W 33
    index = (addr / block_size) % set_num;
    cache_line_offset = index * associative_size;
    tag = ((addr / block_size) / set_num);
    data_offset = ((addr / ONE_BYTE_SIZE) % word_num);

    // init entry_set_offset to associative_size -> for find evict cache entry
    entry_set_offset = associative_size;
    temp_write_data = data;

    for (associative_offset = 0; associative_offset < associative_size; associative_offset++)
    {
        cache_line_ptr = cache + (cache_line_offset + associative_offset);

        // CASE1: valid == 1 && tag is same -> hit
        if (cache_line_ptr->valid == 1 && cache_line_ptr->tag == tag)
        {
            total_hit++;
            // cache data is W ( changed ) -> when this cache line is evict we have to save this data to MM
            cache_line_ptr->dirty = 1;
            cache_line_ptr->data[data_offset] = temp_write_data;
            cache_line_ptr->addr = addr;
            cache_line_ptr->lru_val = extern_lru_value;
            return;
        }
        // valid bit is 0 so we have to write data to cache
        // first find cache entry set to add data
        else if (cache_line_ptr->valid == 0 && entry_set_offset > associative_offset)
        {
            // while associative_offset is in loop while 0 ~ associative_size
            // find available entry set -> this is typeof find algorithm
            /**
             * @brief
             * if entry_set_off find some entry -> then it could not be updated
             * ! if we break this when update entry_set_offset -> there is some exception when finding hit data
             */
            entry_set_offset = associative_offset;
        }
    }

    total_miss++;

    // CASE2-1: miss and cache entry is full -> have to evict
    if (entry_set_offset == associative_size)
    {
        int max_sizeof_int = INT_MAX;
        // we have to go loop and search the oldest entry(cache->lru_val is smallest) in the target cache index
        for (associative_offset = 0; associative_offset < associative_size; associative_offset++)
        {
            cache_line_ptr = cache + (cache_line_offset + associative_offset);
            if (cache_line_ptr->lru_val < max_sizeof_int)
            {
                max_sizeof_int = cache_line_ptr->lru_val;
                // set entry_set_offset to lru_val is minimum
                entry_set_offset = associative_offset;
            }
        }

        cache_line_ptr = cache + (cache_line_offset + entry_set_offset);

        // and if dirty bit is 1 -> save to the main memory
        if (cache_line_ptr->dirty == 1)
        {
            // evict
            // !we cannot do that because we have to know address of evict entry
            // save_MM(addr, cache_line_ptr);

            save_MM(cache_line_ptr);
        }
        writeProcess(addr, temp_write_data, cache_line_ptr);
    }
    else
    {
        cache_line_ptr = cache + (index * associative_size + entry_set_offset);
        writeProcess(addr, temp_write_data, cache_line_ptr);
    }
}

void read_cache(unsigned int addr)
{
    unsigned int index;
    int associative_offset, entry_set_offset, cache_line_offset;
    cache_line *cache_line_ptr;

    index = (addr / block_size) % set_num;
    cache_line_offset = index * associative_size;
    entry_set_offset = associative_size;

    for (associative_offset = 0; associative_offset < associative_size; associative_offset++)
    {
        cache_line_ptr = cache + (cache_line_offset + associative_offset);

        // CASE 1: hit ( total_hit++ )
        if (cache_line_ptr->valid == 1 && cache_line_ptr->tag == ((addr / block_size) / set_num))
        {
            // hit -> update the lru value ( LRU evict policy )
            total_hit++;
            cache_line_ptr->lru_val = extern_lru_value;
            return;
        }
        else if (cache_line_ptr->valid == 0 && entry_set_offset > associative_offset)
        {
            entry_set_offset = associative_offset;
        }
    }

    total_miss++;

    // CASE 2: miss
    // same with write cache -> evict
    if (entry_set_offset == associative_size)
    {
        int max_sizeof_int = INT_MAX;
        // we have to go loop and search the oldest entry(cache->lru_val is smallest) in the target cache index
        for (associative_offset = 0; associative_offset < associative_size; associative_offset++)
        {
            cache_line_ptr = cache + (cache_line_offset + associative_offset);
            if (cache_line_ptr->lru_val < max_sizeof_int)
            {
                max_sizeof_int = cache_line_ptr->lru_val;
                entry_set_offset = associative_offset;
            }
        }

        cache_line_ptr = cache + (cache_line_offset + entry_set_offset);

        // and if dirty bit is 1 -> save to the main memory
        // dirty bit is 0 -> continue
        if (cache_line_ptr->dirty == 1)
        {
            // evict
            // !we cannot do that because we have to know address of evict entry
            // save_MM(addr, cache_line_ptr);
            save_MM(cache_line_ptr);
        }
        readProcess(addr, cache_line_ptr);
    }
    else
    {
        // we have entry
        cache_line_ptr = cache + (index * associative_size + entry_set_offset);
        // if read -> dirty bit is 0
        // because data in cache isn't changed
        readProcess(addr, cache_line_ptr);
    }
}

void save_MM(cache_line *cache_line_ptr)
{
    // we have to know address
    unsigned int evict_addr;
    int memory_line;
    evict_addr = (cache_line_ptr->addr / block_size);

    // printf("save_MM >> (%08X) \n", cache_line_ptr->addr);
    memory_access_count++;

    // loop MM ( 512 )
    for (memory_line = 0; memory_line < INITIAL_BUFFER_SIZE; memory_line++)
    {
        // CASE1: if checksum is ok -> only copy data to main_memory[memory_line]
        if (main_memory[memory_line].check_sum == 1 && main_memory[memory_line].addr == evict_addr)
        {
            // if there is evict_addr in main_memory
            // -> copy cache data to main_memory
            memcpy(main_memory[memory_line].data, cache_line_ptr->data, sizeof(one_word) * word_num);
            return;
        }
        // continue
        else if (main_memory[memory_line].check_sum == 1 && main_memory[memory_line].addr != evict_addr)
            continue;
        // CASE2: if checksum is not ok -> set check_sum to 1 and put some data
        else if (main_memory[memory_line].check_sum == 0)
        {
            // checksum -> 1
            main_memory[memory_line].check_sum = 1;
            main_memory[memory_line].addr = evict_addr;

            // cache data -> MM
            memcpy(main_memory[memory_line].data, cache_line_ptr->data, sizeof(one_word) * word_num);

            return;
        }
    }
}

void read_MM(unsigned int addr, cache_line *cache_line_ptr)
{
    unsigned int target_addr;
    int memory_line;
    target_addr = addr / block_size;

    // printf("read_MM >> (%08X) \n", addr);
    memory_access_count++;

    for (memory_line = 0; memory_line < INITIAL_BUFFER_SIZE; memory_line++)
    {

        if (main_memory[memory_line].check_sum == 1 && main_memory[memory_line].addr == target_addr)
        {
            // cache_line_ptr->data is int* type
            memcpy(cache_line_ptr->data, main_memory[memory_line].data, sizeof(one_word) * word_num);
            return;
        }
    }

    memset(cache_line_ptr->data, 0, sizeof(one_word) * word_num);
}

void writeProcess(unsigned int addr, int data, cache_line *cache_line_ptr)
{
    unsigned int tag;
    int data_offset;

    tag = ((addr / block_size) / set_num);
    data_offset = ((addr / ONE_BYTE_SIZE) % word_num);

    // if block_size is one_word -> we don't have to read MM
    // -> (cache_line_ptr->data)[data_offset] = data; could do that
    if (block_size != ONE_WORD_SIZE)
        read_MM(addr, cache_line_ptr);

    // finally write data to cache
    cache_line_ptr->dirty = 1;
    cache_line_ptr->valid = 1;
    cache_line_ptr->addr = addr;
    cache_line_ptr->tag = tag;
    cache_line_ptr->lru_val = extern_lru_value;
    // set data
    (cache_line_ptr->data)[data_offset] = data;
}

void readProcess(unsigned int addr, cache_line *cache_line_ptr)
{
    cache_line_ptr->dirty = 0;
    cache_line_ptr->valid = 1;
    cache_line_ptr->addr = (addr / block_size);
    cache_line_ptr->tag = ((addr / block_size) / set_num);
    cache_line_ptr->lru_val = extern_lru_value;

    // set data
    read_MM(addr, cache_line_ptr);
}

void print_cache()
{
    int cache_entry_index, associative_offset, cache_line_offset, data_index;

    double miss_rate, average_memory_access_cycle;

    cache_line *cache_line_ptr;

    for (cache_entry_index = 0; cache_entry_index < set_num; cache_entry_index++)
    {
        printf("%d: ", cache_entry_index);
        cache_line_offset = cache_entry_index * associative_size;

        for (associative_offset = 0; associative_offset < associative_size; associative_offset++)
        {
            if (associative_offset != 0)
                printf("   ");

            if ((cache_line_ptr = cache + (cache_line_offset + associative_offset))->dirty)
                total_dirty++;

            for (data_index = 0; data_index < word_num; data_index++)
                printf("%08X ", (cache_line_ptr->data)[data_index]);

            printf("v: %d d: %d\n", cache_line_ptr->valid, cache_line_ptr->dirty);

            // printf(" tag: (%016X) \n", cache_line_ptr->tag);
        }
    }

    miss_rate = (double)((double)total_miss / (total_hit + total_miss)) * 100;
    average_memory_access_cycle = (double)(memory_access_count * MISS_PENALTY_CYCLE + (total_hit + total_miss) * HIT_CYCLE) / (total_hit + total_miss);

    // printf("mac >> %d\n", memory_access_count);
    printf("total number of hits: %d\n", total_hit);
    printf("total number of misses: %d\n", total_miss);
    printf("miss rate: %.1f%%\n", miss_rate);
    printf("total number of dirty blocks: %d\n", total_dirty);
    printf("average memory access cycle: %.1f\n", average_memory_access_cycle);

    // print_mm();
}

/*
void print_mm()
{
    int memory_line, data_index;

    for (memory_line = 0; memory_line < INITIAL_BUFFER_SIZE; memory_line++)
    {

        printf("addr: %08X ", main_memory[memory_line].addr);

        for (data_index = 0; data_index < word_num; data_index++)
            printf("data: %08X ", (main_memory[memory_line].data[data_index]));

        printf("\n");
        if (main_memory[memory_line].check_sum == 1)
            break;
    }
}
*/

void free_process()
{
    int i;

    for (i = 0; i < block_size / ONE_WORD_SIZE; i++)
        free(cache[i].data);

    for (i = 0; i < INITIAL_BUFFER_SIZE; i++)
        free(main_memory[i].data);

    free(cache);
    free(main_memory);

    fclose(tracefile_fp);
}