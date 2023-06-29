#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // 입력된 string을 저장할 배열
    char inputString[100] = {0};

    // 발생한 알파벳들을 저장하는 배열
    char happenChar[100] = {0};
    // 발생한 알파벳들의 가중치를 저장하는 배열
    int happenInt[100] = {0};

    // 알파벳들을 저장하기 위한 인덱스이자 -> 배열의 크기라고 놓을 수 있다.
    int count = 0;

    gets(inputString);

    char *delimiter = " ,.\"!";
    char *ptoken = strtok(inputString, delimiter);

    while (ptoken != NULL)
    {
        for (int i = 0; ptoken[i] != '\0'; i++)
        {
            // ptoken[i] 는 해당 알파벳을 뜻한다.
            int index = -1;
            for (int j = 0; j < count; j++)
            {
                // 만약 happenChar에 해당되는 알파벳이 있다면
                if (happenChar[j] == ptoken[i])
                {
                    // index 는 -1이 아닌 해당하는 인덱스가 될 것이다.
                    index = j;
                }
            }

            // 만약 index = -1라면 해당 배열에 없는 것이다.
            if (index == -1)
            {
                happenChar[count] = ptoken[i];
                happenInt[count]++;
                count++;
            }
            else
            {
                // 만약 이미 있던 거라면 가중치만 더해준다.
                happenInt[index]++;
            }
        }

        ptoken = strtok(NULL, delimiter);
    }

    // 알파벳과 가중치 정렬
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            // 오름차순 정렬
            if (happenChar[j] > happenChar[j + 1])
            {
                // happenChar를 오름차순으로 정렬한다.
                char temp = happenChar[j];
                happenChar[j] = happenChar[j + 1];
                happenChar[j + 1] = temp;

                // happenint를 오름차순으로 정렬한다.
                int temp_ = happenInt[j];
                happenInt[j] = happenInt[j + 1];
                happenInt[j + 1] = temp_;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%c:%d\n", happenChar[i], happenInt[i]);
    }

    return 0;
}