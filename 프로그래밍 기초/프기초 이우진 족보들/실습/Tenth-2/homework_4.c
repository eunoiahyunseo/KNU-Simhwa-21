#include <stdio.h>

typedef struct
{
    double x;
    double y;
} point;

typedef struct
{
    double slope;
    double yintercept;
} line;

int main(void)
{

    point p1, p2;

    point pointArry[2] = {p1, p2};

    scanf("%lf %lf", &pointArry[0].x, &pointArry[0].y);
    scanf("%lf %lf", &pointArry[1].x, &pointArry[1].y);

    line l1;

    double slope = (pointArry[1].y - pointArry[0].y) / (pointArry[1].x - pointArry[0].x);
    double yintercept = pointArry[0].y - slope * pointArry[0].x;

    l1.slope = slope;
    l1.yintercept = yintercept;

    printf("%.1lf %.1lf", l1.slope, l1.yintercept);

    return 0;
}