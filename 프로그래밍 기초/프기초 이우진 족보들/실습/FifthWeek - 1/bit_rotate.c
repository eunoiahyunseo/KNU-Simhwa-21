#include <stdio.h>

void print16int(unsigned short num)
{
    int i;
    for (i = sizeof(num) * 8 - 1; i >= 0; i--)
    {

        if ((1 << i) & num)
        {
            putchar('1');
        }
        else
        {
            putchar('0');
        }

        if (i % 4 == 0)
        {
            putchar(' ');
        }
    }
    printf("\n");
}
unsigned short rotateRight(unsigned short num, int n)
{
    return ((num >> n) | (num << (16 - n)));
}

unsigned short rotateLeft(unsigned short num, int n)
{
    return ((num << n) | (num >> (16 - n)));
}

int main(void)
{
    unsigned short num = 0x2345;
    print16int(num);
    printf("Rotate Right : >> 4bits \n");
    print16int(rotateRight(num, 4));

    // printf("Rotate Left : << 4bits \n");
    // print16int(rotateLeft(num, 4));

    // unsigned short num1 = 0x0257;
    // unsigned short num2 = 0xA463;

    // unsigned short res;

    // print16int(num1);
    // print16int(num2);

    // res = num1 & num2;
    // printf("\nnum1 & lnum2 = %#06X\n", res);
}