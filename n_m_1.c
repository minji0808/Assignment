#include <stdio.h>
#include <stdbool.h>
// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

int n, m;
int result[100];
bool visited[100]; // 방문했는지 체크 (true, false)

void DFS(int depth)
{
    int i;
    
    if(depth == m)  // 종료 조건 
    {
        for(int i = 0; i < m; i++)
            printf("%d ", result[i]);
        printf("\n");
    }

    else              
    {
        for(i = 1; i <= n; i++)
        {
            if(visited[i] == false)
            {
                result[depth] = i;
                visited[i] = true;
                DFS(depth + 1); // 재귀 호출 -> depth +1
                visited[i] = false;
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    DFS(0);
    return 0;
}