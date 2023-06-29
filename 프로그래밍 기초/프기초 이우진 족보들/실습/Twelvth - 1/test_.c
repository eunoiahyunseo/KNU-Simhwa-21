#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("fprintf.txt", "w");

    fprintf(fp, "%d", 10);
}