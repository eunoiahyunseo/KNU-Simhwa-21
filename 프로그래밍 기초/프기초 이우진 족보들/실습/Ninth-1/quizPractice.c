#include <stdio.h>
#include <math.h>

#define MAX 100

static int fibScore[MAX] = {0};

// 팩토리얼 계산 함수
long factorial(int number);

// 2진수 출력 함수
void binary(int number);

// 피보나치 수열 구하는 함수 버전1
int fib_version1(unsigned int n);

// 피보나치 수열 구하는 함수 버전2
int fib_version2(int n);

// 유클리드 호제법 함수
int gcd(int max, int min);

// 예제 a[0],... ,a[N - 1]에 저장된 N개의 값 들 중 가장 큰 값
int max(int a[], int l, int r);

// 지수 구하는 함수
int Exp(int x, unsigned int n);

void printTri(int idx, int n);

int BinarySearch(int A[], int value, int low, int high);

int main(void)
{
    // int number = 5;

    // binary(number);

    // printf("fib(%d) >> %d", number, fib_version1(5));

    // fib_version2(number);
    // printf("fib(%d) >> %d\n", number, fibScore[number]);
    // for (int i = 0; i < number; i++)
    // {
    //     printf("fibScore[%d] >> %d\n", i, fibScore[i]);
    // }

    // int a[5] = {4, 6, 2, 1, 8};
    // printf("max(a) >> %d\n", max(a, 0, 4));

    // printf("Exp(2, 5) >> %d\n", Exp(2, 5));

    // printTri(2, 5);

    int a[5] = {4, 7, 9, 14, 15};
    printf("a[%d] >> %d", BinarySearch(a, 14, 0, 4), a[BinarySearch(a, 14, 0, 4)]);

    return 0;
}

long factorial(int number)
{
    if (number == 1)
    {
        return 1;
    }

    return number * factorial(number - 1);
}
// < factorial >
// 5 * factorial(4)
// 5 * 4 * factorial(3)
// 5 * 4 * 3 * factorial(2)
// 5 * 4 * 3 * 2 * factorial(1)
// 5 * 4 * 3 * 2 * 1
// 이 순서대로 재귀적으로 호출된다.

void binary(int number)
{
    if (number > 0)
    {
        binary(number / 2);
        printf("%d", number % 2);
    }
}
// < binary >
// binary(10)
// binary(10) -> binary(5)
// binary(10) -> binary(5) -> binary(2)
// binary(10) -> binary(5) -> binary(2) -> binary(1)
// <출력> -> 역순으로 올라오면서
// 1 0 1 0

int fib_version1(unsigned int n)
{

    if (n == 1 || n == 0)
    {
        return n;
    }

    return fib_version1(n - 1) + fib_version1(n - 2);
}

// < fib > >> fib(0) = 0, fib(1) = 1
// fib(5)

// fb(5)
// fb(4) + fb(3)
// fb(3) + fb(2) + fb(2) + fb(1)
// fb(2) + fb(1) + fb(1) + fb(0) + fb(1) + fb(0) + fb(1)
// fb(1) + fb(0) + fb(1) + fb(1) + fb(0) + fb(1) + fb(0) + fb(1)
// 1 + 0 + 1 + 1 + 0 + 1 + 0 + 1
// = 5

int fib_version2(int n)
{
    // 정적 전역변수 초기화
    fibScore[0] = 0;
    fibScore[1] = 1;

    if (n == 0 || n == 1)
    {
        return n;
    }

    // 만약 fibScore[n]에 존재하는 값이 있으면 하지 않는다.
    if (fibScore[n] == 0)
    {
        fibScore[n] = fib_version2(n - 1) + fib_version2(n - 2);
        // printf("fibScore[%d] >> %d\n", n - 1, fibScore[n]);
    }

    return fibScore[n];
}

int gcd(int max, int min)
{
    if (min == 0)
    {
        return max;
    }
    else
    {
        return gcd(min, max % min);
    }
}
// gcd(30, 20)
// gcd(20, 10)
// gcd(10, 0)

int max(int a[], int l, int r)
{
    int m, u, v;
    if (l == r)
        return a[l];

    m = (l + r) / 2;
    u = max(a, l, m);
    v = max(a, m + 1, r);

    if (u > v)
        return u;
    else
        return v;
}
// a [ 4 6 2 1 7 ]                         max(a, 0, 4);
// <                    max(a, 0, 2)                             max(a, 3, 4)
// <        max(a, 0, 1)            max(a, 2, 2)     max(a, 3, 3)            max(a, 4, 4)
// <   max(a, 0, 0)  max(a, 1, 1)

int Exp(int x, unsigned int n)
{
    int temp;
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    if (n % 2 == 0)
        return pow(Exp(x, n / 2), 2);
    else
        return pow(Exp(x, n / 2), 2) * x;
}
// 2^5
// (2^2 * 2^2) * 2

void printTri(int idx, int n)
{
    for (int i = 0; i < idx; i++)
    {
        putchar('*');
    }
    putchar('\n');

    if (idx == n)
        return;

    printTri(idx + 1, n);

    for (int i = 0; i < idx; i++)
    {
        putchar('*');
    }
    putchar('\n');
    return;
}

// printTri(2, 5)
// **
// printTri(3, 5)
// ***
// printTri(4, 5)
// ****
// printTri(5, 5)
// *****
// printTri(5, 5) -> return;
// ****
// printTri(4, 5) -> return;
// ***
// printTri(3, 5) -> return;
// **
// printTri(2, 5) -> return;
// *
// printTri(1, 5) -> return;

// < result >
// **
// ***
// ****
// *****
// ****
// ***
// **

int BinarySearch(int A[], int value, int low, int high)
{
    int mid;

    if (high < low)
        return -1;

    mid = (low + high) / 2;
    if (A[mid] > value)
    {
        return BinarySearch(A, value, low, mid - 1);
    }
    else if (A[mid] < value)
    {
        return BinarySearch(A, value, mid + 1, high);
    }
    else
    {
        return mid;
    }
}

// a = [1, 2, 3, 4, 5]
// value = 1 low = 0 high = 4

// a[0] ~ a[2]
// a[2] ~ a[4]