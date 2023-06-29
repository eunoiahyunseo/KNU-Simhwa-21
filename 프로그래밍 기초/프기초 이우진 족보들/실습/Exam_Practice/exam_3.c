#include <stdio.h>

int main(void)
{

    int grade[16] = {2,
                     6,
                     11,
                     13,
                     18,
                     20,
                     22,
                     27,
                     29,
                     30,
                     34,
                     38,
                     41,
                     42,
                     45,
                     47};
    int key;
    printf("탐색할 값을 입력하세요: ");
    scanf("%d", &key);

    /* binary search */
    int low = 0, high = 15;
    int index;

    while (low <= high)
    {
        int middle = (low + high) / 2;

        printf("[%d %d]\n", low, high);
        if (key == grade[middle])
        {
            index = middle;
            break;
        }
        else if (key < grade[middle])
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }

    printf("grade[%d] => %d", index, grade[index]);
    return 0;
}