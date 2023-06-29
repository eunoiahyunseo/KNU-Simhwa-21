#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // char inputArr[3][4];
    // int inputNameValue[100];

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if (j == 0)
    //         {
    //             scanf("%s", &inputNameValue);
    //             strcpt()
    //         }
    //     }
    // }

    char charArr[3][100];
    int intArr[3][80];
    int inputNameValue[100];
    int intValue = 0;

    int grade[3];
    char grade_[3][80];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                scanf("%s", inputNameValue);
                strcpy(charArr[i], inputNameValue);
            }
            else
            {
                scanf("%d", &intValue);
                intArr[i][j - 1] = intValue;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grade[j] < intArr[i][j])
            {
                grade[j] = intArr[i][j];
            }
        }
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         if (intArr[i][j] == grade[j])
    //         {
    //             strcpy(grade_[i], "(A)");
    //         } else {
    //             strcpy(grade_[i])
    //         }
    //     }
    // }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                printf("%s ", charArr[i]);
            }
            else
            {
                printf("%d", intArr[i][j - 1]);
                if (intArr[i][j - 1] == grade[j - 1])
                {
                    if (j != 3)
                    {
                        printf("(A) ");
                    }
                    else
                    {
                        printf("(A)");
                    }
                }
                else
                {
                    if (j != 3)
                    {

                        printf("(-) ");
                    }
                    else
                    {
                        printf("(-)");
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}