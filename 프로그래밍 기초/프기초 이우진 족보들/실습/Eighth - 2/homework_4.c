#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char inputString[200];
    char happenChar[100] = {0};
    int happenCount[100] = {0};

    int count = 0;
    gets(inputString);

    char delimiter[100] = " .,'\"";
    char *ptoken = strtok(inputString, delimiter);

    while (ptoken != NULL)
    {
        int ptoken_len = strlen(ptoken);
        for (int i = 0; i < ptoken_len; i++)
        {
            int search = 0;
            // 해당하는 문자 -> foundChar
            char foundChar = ptoken[i];

            for (int i = 0; i < 100; i++)
            {
                if (happenChar[i] == foundChar)
                {
                    search = i; // 해당하는 문자의 인덱스를 search에 넣음
                }
            }
            // ptoken 문자열을 순회하면서 해당하는 문자가 happenChar에 존재하면
            // search > 0 없으면 search = 0

            // 만약 없다면
            // count를 1씩 증가시키고 해당하는 인덱스의 가중치를 1로 만든다
            if (search == 0)
            {
                happenChar[count] = foundChar;
                happenCount[count] = 1;
                count += 1;
            }
            else
            {
                // 만약 해당하는 문자가 이미 존재 한다면
                happenCount[search]++;
            }
        }
        ptoken = strtok(NULL, delimiter);
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (happenChar[j] > happenChar[j + 1])
            {
                char temp = happenChar[j];
                happenChar[j] = happenChar[j + 1];
                happenChar[j + 1] = temp;

                char temp_ = happenCount[j];
                happenCount[j] = happenCount[j + 1];
                happenCount[j + 1] = temp_;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%c:%d\n", happenChar[i], happenCount[i]);
    }

    return 0;
}