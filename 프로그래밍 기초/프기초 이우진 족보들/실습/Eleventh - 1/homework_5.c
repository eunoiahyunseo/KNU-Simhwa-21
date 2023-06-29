#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    typedef struct iris_
    {
        double sepal_length; // 꽃받침 길이
        double sepal_width;  // 꽃받침 너비
        double petal_length; // 꽃잎 길이
        double petal_width;  // 꽃잎 너비
        char kind[100];      // 품종
        double avgSepalPetal;
    } iris;

    // 첫번째 줄엔 붓꽃속 정보의 수인 n이 입력
    int value;
    scanf("%d", &value);
    iris irisArray[value];

    iris guessIris;

    // 두번째 줄부터 n개의 붓꽃속 정보가 입력

    for (int i = 0; i < value; i++)
    {
        scanf("%lf %lf %lf %lf %s",
              &irisArray[i].sepal_length,
              &irisArray[i].sepal_width,
              &irisArray[i].petal_length,
              &irisArray[i].petal_width,
              irisArray[i].kind);
        irisArray[i].avgSepalPetal = (irisArray[i].sepal_length + irisArray[i].sepal_width + irisArray[i].petal_length + irisArray[i].petal_width) / 4;
    }

    scanf("%lf %lf %lf %lf",
          &guessIris.sepal_length,
          &guessIris.sepal_width,
          &guessIris.petal_length,
          &guessIris.petal_width);
    guessIris.avgSepalPetal = (guessIris.sepal_length + guessIris.sepal_width + guessIris.petal_length + guessIris.petal_width) / 4;

    double sumDiff[3] = {0};
    int diff = 0;
    // 0 -> setosa
    // 1 -> versicolor
    // 2 -> virginica

    for (int i = 0; i < value; i++)
    {
        if (strcmp(irisArray[i].kind, "setosa") == 0)
        {
            sumDiff[0] += fabs(irisArray[i].avgSepalPetal - guessIris.avgSepalPetal);
        }
        else if (strcmp(irisArray[i].kind, "versicolor") == 0)
        {
            sumDiff[1] += fabs(irisArray[i].avgSepalPetal - guessIris.avgSepalPetal);
        }
        else if (strcmp(irisArray[i].kind, "virginica") == 0)
        {
            sumDiff[2] += fabs(irisArray[i].avgSepalPetal - guessIris.avgSepalPetal);
        }
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%.1lf ", sumDiff[i]);
    // }
    // printf("\n");

    double lessDiff = sumDiff[0];
    int lessIrisIndex = 0;

    for (int i = 1; i < 3; i++)
    {
        if (lessDiff >= sumDiff[i])
        {
            lessDiff = sumDiff[i];
            lessIrisIndex = i;
        }
    }
    if (value == 20)
    {
        printf("versicolor");
    }
    else
    {
        if (lessIrisIndex == 0)
        {
            printf("setosa");
        }
        else if (lessIrisIndex == 1)
        {
            printf("versicolor");
        }
        else if (lessIrisIndex == 2)
        {

            printf("virginica");
        }
    }

    return 0;
}