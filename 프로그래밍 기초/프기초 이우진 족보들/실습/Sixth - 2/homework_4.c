#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

void checkLastDigit(int arr[], int num)
{
    int arr_2[10] = {0};
    for (int i = 0; i < num; i++)
    {
        char s1[100];
        int number = arr[i];
        sprintf(s1, "%d", number);
        int len = strlen(s1);
        char count = s1[len - 1];
        int n = count - 48;
        arr_2[n] += 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", i, arr_2[i]);
    }
}

int main(void)
{
    int number;
    int arr[1000];
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &arr[i]);
    }
    checkLastDigit(arr, number);

    return 0;
}