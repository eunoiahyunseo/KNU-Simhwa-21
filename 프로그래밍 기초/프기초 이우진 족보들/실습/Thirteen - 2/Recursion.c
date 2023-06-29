#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

int Coin1(int);

int Coin2(int);

int findMin(int, int, int, int);
int findMin_2(int, int);

void Comb1(int *, int, int);
void Comb2(int *, int, int);

void sortCharArr(char **, int, int);
void Permutation(char *, int, int);

int main(void)
{
    // int value;
    // scanf("%d", &value);

    // int booleanArr[value];
    // printf("최소 동전의 개수는 >> %d\n", Coin2(value));
    // Comb2(booleanArr, 0, value);

    char charArr[4] = {'a',
                       'a',
                       'b',
                       'b'};

    Permutation(charArr, 0, sizeof(charArr) / sizeof(char));

    return 0;
}

int findMin(int value1, int value2, int value3, int value4)
{
    int intArr[4] = {value1, value2, value3, value4};
    int i;

    int min = intArr[0];

    for (i = 0; i < 4; i++)
    {
        if (intArr[i] < min)
        {
            min = intArr[i];
        }
    }

    return min;
}

int findMin_2(int value1, int value2)
{
    if (value1 < value2)
    {
        return value1;
    }
    return value2;
}

// 8 6 2 1

// input -> 0

// input -> 3
// 2 1개 1 1개가 들어와야 한다.

// input -> 12
// 6 2개가 들어가야 한다
// 8 1개 2 2개가 들어가면 안된다.

int Coin1(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INF;
    }

    return findMin(
               Coin1(n - 1),
               Coin1(n - 2),
               Coin1(n - 6),
               Coin1(n - 8)) +
           1;
}

// 8 6 2 1

// input -> 0

// input -> 3
// 2 1개 1 1개가 들어와야 한다.

// input -> 12
// 6 2개가 들어가야 한다
// 8 1개 2 2개가 들어가면 안된다.

// Dynaic Programming

// 0 1 1 2
int Coin2(int n)
{
    // 0은 0으로 초기화 시켜주기 위함

    // 1번 인덱스부터 n인덱스까지 쓰기 위해
    int N[n + 1];
    int i, M;
    N[0] = 0;

    for (i = 1; i <= n; i++)
    {
        if (i >= 2)
        {
            M = findMin_2(N[i - 1], N[i - 2]);
        }

        if (i >= 6)
        {
            M = findMin_2(M, N[i - 6]);
        }

        if (i >= 8)
        {
            M = findMin_2(M, N[i - 8]);
        }

        N[i] = M + 1;
    }
    return N[n];
}

// Comb1(a, 0, 5);

void Comb1(int *a, int k, int n)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }

    a[k] = 1;
    Comb1(a, k + 1, n);

    a[k] = 0;
    Comb1(a, k + 1, n);
}

// Comb2(a, 0, 5);
void Comb2(int *a, int k, int n)
{
    if (n == 0)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }

    a[n - 1] = 1;
    Comb2(a, k, n - 1);

    a[n - 1] = 0;
    Comb2(a, k, n - 1);
}

// a b a b

// perm(a, k, n);
// k 개를 정렬
// a a b b

// perm(a, k + 1, n);
// a | a b b

// sort(a, k + 1, n);
// a | a b b
// perm(a, k + 2, n);
// a | a | b | b

void sortCharArr(char **a, int k, int m)
{
    int i, j;
    // printf("doiung");
    for (i = k; i < m; i++)
    {
        for (j = k; j < m - i - 1; j++)
        {
            if ((*a)[j] > (*a)[j + 1])
            {
                char temp = (*a)[j];
                (*a)[j] = (*a)[j + 1];
                (*a)[j + 1] = temp;
            }
        }
    }
}

void Permutation(char *a, int k, int n)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%c ", a[i]);
        }
        printf("\n");
        return;
    }
    sortCharArr(&a, k, n);
    Permutation(a, k + 1, n);
    sortCharArr(&a, k + 1, n);

    for (int i = k; i < n; i++)
    {
        if (a[i] > a[k])
        {
            char temp = a[k];
            a[k] = a[i];
            a[i] = temp;
            sortCharArr(&a, k, n);
            Permutation(a, k + 1, n);
            sortCharArr(&a, k + 1, n);
        }
    }
}
