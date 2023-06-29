// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int **table;
//     int i, k, rownum, colnum;
//     scanf("%d %d", &rownum, &colnum);

//     table = (int **)calloc(rownum, sizeof(int *));
//     for (i = 0; i < rownum; i++)
//     {
//         table[i] = (int *)calloc(colnum, sizeof(int));
//         for (k = 0; k < colnum; k++)
//         {
//             scanf("%d", table[i] + k);
//         }
//     }

//     printf("-------------------------------\n");

//     for (i = 0; i < rownum; i++)
//     {
//         for (k = 0; k < colnum; k++)
//         {
//             printf("%d ", table[i][k]);
//         }
//         free(table[i]);
//         printf("\n");
//     }

//     free(table);

//     return 0;
// }