#include <stdio.h>

#define N 100
#define INF 100000

int a[N + 1][N + 1];
int visit[N + 1];
int dist[N + 1];
// start->시작 정점 end->끝 정점
int start, end;

// n->정점 개수 m->가중치 개수
int n, m;

void input()
{
    int i, j;
    int from, to;
    int w;

    scanf("%d %d %d", &n, &start, &end);
    scanf("%d", &m);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            a[i][j] = INF;
        }
    }

    for (i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &from, &to, &w);
        a[from][to] = w;
    }

    for (i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
}

void dijstra()
{
    dist[start] = 0;
    int min, v;
    int i, j;

    for (i = 1; i <= n; i++)
    {
        min = INF;

        // 일단 dist중에 방문하지 않은 것중에 가장 작은 것을 찾아야 한다.
        for (j = 1; j <= n; j++)
        {
            if (!visit[j] && min > dist[j])
            {
                min = dist[j];
                v = j;
            }
        }

        visit[v] = 1;

        for (j = 1; j <= n; j++)
        {
            // 최소인 v정점을 경유해서 가는 것이 만약 더 작으면
            if (dist[j] > dist[v] + a[v][j])
            {
                dist[j] = dist[v] + [v][j];
            }
        }
    }
}

int main(void)
{
    input();
    dijstra();
    printf("%d\n", dist[end]);

    return 0;
}