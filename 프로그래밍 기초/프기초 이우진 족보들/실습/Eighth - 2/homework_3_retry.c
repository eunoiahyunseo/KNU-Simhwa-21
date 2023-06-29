#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    // 학생들의 이름을 저장할 배열
    char nameArr[3][100] = {0};
    // 학생들의 국어, 영어, 수학 성적을 저장할 배열
    int scoreArr[3][3] = {0};

    for (int i = 0; i < 3; i++)
    {
        // 학생들의 이름을 입력받음
        scanf("%s", nameArr[i]);
        for (int j = 0; j < 3; j++)
        {
            // 학생들의 국어, 영어, 수학 성적을 입력받음
            scanf("%d", &scoreArr[i][j]);
        }
    }

    // 각각의 수학, 영어, 수학의 최댓값을 저장하는 크기 3짜리 배열을 만든다.
    int maxScore[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        // 열을 기준으로 순환해서 최댓값을 찾아낸다.
        int max = scoreArr[0][i];
        for (int j = 0; j < 3; j++)
        {
            if (scoreArr[j][i] > max)
            {
                max = scoreArr[j][i];
            }
        }
        maxScore[i] = max;
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%s ", nameArr[i]);
        for (int j = 0; j < 3; j++)
        {
            printf("%d", scoreArr[i][j]);
            if (scoreArr[i][j] == maxScore[j])
            {
                // 만약 해당 점수가 maxScore와 같다면 (A)를 출력해준다.
                printf("(A) ");
            }
            else
            {
                printf("(-) ");
            }
        }
        printf("\n");
    }

    return 0;
}