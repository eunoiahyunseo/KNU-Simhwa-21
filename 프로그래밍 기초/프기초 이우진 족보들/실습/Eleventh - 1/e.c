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

    double lessDiff = fabs(irisArray[0].avgSepalPetal - guessIris.avgSepalPetal);
    int lessIrisIndex = 0;

    for (int i = 0; i < value; i++)
    {
        double diff = fabs(irisArray[i].avgSepalPetal - guessIris.avgSepalPetal);
        if (diff < lessDiff)
        {
            lessDiff = diff;
            lessIrisIndex = i;
        }
    }

    printf("%s", irisArray[lessIrisIndex].kind);

    return 0;
}