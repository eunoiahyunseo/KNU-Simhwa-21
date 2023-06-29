#include <stdio.h>

void printBin(int a);
void printFloatBin(double a);

int main(void)
{
    while(1) {    
        double number;
        scanf("%lf", &number);

        if(number != 0) {
            int intPart = number;
            printBin(intPart);

            printf(".");

            double doublePart = number - intPart;
            printFloatBin(doublePart);
            printf("\n");
        } else {
            break;
        }
    }

    return 0;
}

void printBin(int a)
{
    if (a > 0)
    {
        printBin(a / 2);
        printf("%d", a % 2);
    }
}

void printFloatBin(double a)
{
    // a가 0 이상인 부분 까지

    // 만약 count가 10을 넘어가게 된다면 멈춰야 한다.
    int count = 1;
    while (a >= 0)
    {
        // 만약 1보다 작다면 0 출력
        if(a == 0) {
            printf("%d", 0);
            break;
        } 
        // 만약 2 곱한것이 0과 1 사이면
        else if ((a * 2) < 1)
        {
            a *= 2;
            if (count <= 10)
            {
                printf("%d", 0);
                count++;
            }
            else
            {
                break;
            }
        }
        else if ((a * 2) == 1)
        {
            printf("%d", 1);
            break;
        }
        else if ((a * 2) > 1)
        {
            a *= 2;
            a -= 1;

            if (count <= 10)
            {
                printf("%d", 1);
                count++;
            }
            else
            {
                break;
            }
        }
    }
}