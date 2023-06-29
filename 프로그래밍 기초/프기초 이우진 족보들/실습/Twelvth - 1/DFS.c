#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

int metrix[MAX][MAX];
int visited[MAX * MAX];

// V -> 시작 vertex
// vertex의 개수
void DFS(int v, int N)
{
    printf("%d ", v);

    // v는 방문했으므로 방문 체크를 한다.
    visited[v] = 1;

    for (int d = 1; d <= N; d++)
    {
        // 인접한 노드를 확인한다.
        if (!visited[d] && metrix[v][d])
        {
            DFS(d, N);
        }
    }
}

void BFS(int v, int N)
{
    // 큐와 관련된 변수 선언
    int queue[MAX * MAX];
    memset(queue, 0, MAX * MAX);
    int rear = -1, front = -1;

    rear++;
    queue[rear] = v;
    // 방문한건 찍어준다.
    visited[v] = 1;

    // 일단 출력
    printf("%d ", v);

    // 너비 우선 탐색
    //
    while (front < rear)
    {
        front++;
        // 이에 해당하는 value를 꺼내온다.
        int netxV = queue[front];

        for (int d = 1; d <= N; d++)
        {
            if (!visited[d] && metrix[netxV][d])
            {
                rear++;
                visited[d] = 1;
                queue[rear] = d;

                printf("%d ", d);
            }
        }
    }
}
int main(void)
{
    // 정점의 개수N, 간선의 개수 M, 탐색을 시작할 정점의 번호 V
    int N = 0;
    int M = 0;
    int V = 0;

    scanf("%d %d %d", &N, &M, &V);

    // 간선의 개수 만큼 반복
    for (int i = 0; i < M; i++)
    {
        int s = 0;
        int d = 0;
        scanf("%d %d", &s, &d);

        metrix[s][d] = 1;
        metrix[d][s] = 1;
    }

    DFS(V, N);

    return 0;
}
