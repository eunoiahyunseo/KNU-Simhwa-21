#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    struct Point2D
    {
        int x;
        int y;
    };

    struct Point2D *p[3];

    // for (int i = 0; i < sizeof(p) / sizeof(struct Point2D *); i++)
    // {
    //     p[i] = malloc(sizeof(struct Point2D));
    // }

    struct Point2D p1;
    p1.x = 1;
    p1.y = 2;

    // memcpy(p[0], &p1, sizeof(struct Point2D));

    // printf("%d %d\n", p[0]->x, p[0]->y);
    p[0] = &p1;

    for (int i = 0; i < sizeof(p) / sizeof(struct Point2D *); i++)
    {
        free(p[i]);
    }
    return 0;
}