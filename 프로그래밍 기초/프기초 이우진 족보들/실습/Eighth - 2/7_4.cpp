#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int array[10] = { 0,0,0,0,0,0,0,0,0,0 };
    int count = 0;
    int input;
    int a = 0;
    while (1)
    {
        scanf("%d", &input);
        if (input > 0) {
            for (int i = 0; i <= sizeof(array) / sizeof(int); i++) {
                if (input == array[i]) {
                    break;
                }
                else if (i == sizeof(array) / sizeof(int))
                {
                    array[a] = input;
                    count++;
                    a++;
                    break;
                }

            }
        }

        else if (input < 0) {
            for (int i = 0; i <= sizeof(array) / sizeof(int); i++)
            {
                if (array[i] == -input) {
                    array[i] = 0;
                    count--;
                }
            }
        }
        else {
            break;
        }
        printf("array[%d] = { ", count);
        for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
            if (array[i] != 0) {
                printf("%d ", array[i]);
            }
        }
        printf("}\n");
    }
    return 0;
}