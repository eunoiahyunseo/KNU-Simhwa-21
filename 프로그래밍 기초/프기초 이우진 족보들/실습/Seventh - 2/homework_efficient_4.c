#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    double sum = 0;
    int count_3 = 0;
    while (1)
    {
        char value[100];
        gets(value);

        if (strcmp(value, "quit")) // value == quit이 아니면
        {
            char *delimiter = ",";
            char *ptoken = malloc(sizeof(char) * 100);
            strcpy(ptoken, strtok(value, delimiter));

            int count_2 = 0;
            while (ptoken != NULL)
            {

                char ptr[100];
                int count = 0;
                if (count_2 == 0 && count_2++)
                {

                    printf("%s\t", ptoken);
                }
                else
                {
                    for (int i = 0; i < strlen(ptoken); i++)
                    {
                        if (ptoken[i] != ' ')
                        {
                            ptr[count] = ptoken[i];
                            count += 1;
                        }
                    }

                    if (count_2 == 2)
                    {
                        sum += atoi(ptr);
                        count_3 += 1;
                        printf("%s\n", ptr);
                    }
                    else
                    {
                        printf("%s\t", ptr);
                    }
                    count_2 += 1;
                }
                ptoken = strtok(NULL, delimiter);
            }
        }
        else
        {
            printf("avg=%.1lf\n", sum / count_3);
            break;
        }
    }
}