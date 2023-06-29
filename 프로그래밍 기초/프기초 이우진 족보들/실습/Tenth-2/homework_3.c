#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Fraction_
{
    int fraction_part1;
    int fraction_part2;
} Fraction;

int main(void)
{
    int count = 0;
    Fraction fractionAry[2];
    scanf("%d/%d", &fractionAry[0].fraction_part1, &fractionAry[0].fraction_part2);
    scanf("%d/%d", &fractionAry[1].fraction_part1, &fractionAry[1].fraction_part2);
    double first_value = (double)fractionAry[0].fraction_part1 / fractionAry[0].fraction_part2;
    double second_value = (double)fractionAry[1].fraction_part1 / fractionAry[1].fraction_part2;
    int resultBool = (first_value == second_value) ? 0 : (first_value > second_value ? -1 : 1);
    printf("%d", resultBool);
}