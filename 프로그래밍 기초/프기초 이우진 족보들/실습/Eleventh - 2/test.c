#include <stdio.h>
int main(void)
{

    FILE *fp;
    char name[30];
    int score1, score2, score3;

    fp = fopen("test.txt", "r+");
    if (fp == NULL)
    {
        printf("Cannot find the file\n");
    }

    while (!feof(fp))
    {
        char buffer[100] = {0};
        // fscanf(fp, "%s %d %d %d", name, &score1, &score2, &score3);
        // printf("%s %d %d %d\n", name, score1, score2, score3);
        fgets(buffer, 100, fp);
        printf("%s", buffer);
    }
    fclose(fp);

    return 0;
}