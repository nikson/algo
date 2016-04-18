#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>

#define N 100
#define INF 99999
#define WHITE 1
#define GRAY 2

using namespace std;

int edge[N][N] = { 0 };
int vertex[N] = { 0 };

void BFS(int total_node, int total_edge, int start_node);
void DFS(int total_node, int total_edge, int start_node);

int main()
{
    int total_node, total_edge;
    int u, v;
    int i, k;

    // freopen("in.txt", "r", stdin);

    printf("Enter total number of node & edge: ");
    scanf("%d %d", &total_node, &total_edge);

    printf("Enter %d edges:\n", total_edge);
    for ( i = 0; i < total_edge; i++ )
    {
        scanf("%d %d", &u, &v);
        edge[u][v] = edge[v][u] = WHITE;
    }

	/*
    for ( i = 1; i <= total_node; i++ )
    {
        printf("\n");
        for ( k = 1; k <= total_node; k++ )
        {
            printf(" %d ", edge[i][k]);
        }
    }
	*/

    //printf("\nBFS Traverse: ");
    //BFS(total_node, total_edge, 1);

    printf("\nDFS Traverse: ");
    DFS(total_node, total_edge, 1);

    return 0;
}


void BFS(int total_node, int total_edge, int start_node)
{
    queue<int> q;
    q.push(start_node);

    while( !q.empty())
    {
       int d = q.front();
       q.pop();
       printf("%d ", d);
       vertex[d] = GRAY;

       for ( int i = 0; i <= total_node; i++)
       {
            // Not visited,
            if ( edge[d][i] == WHITE && vertex[i] != GRAY )
            {
                edge[d][i] = edge[i][d] = GRAY;
                q.push(i);
                vertex[i] = GRAY;
            }
       }
    }
}

void DFS(int total_node, int total_edge, int start_node)
{
    stack<int> q;
    q.push(start_node);

    while( !q.empty())
    {
       int d = q.top();
       q.pop();
       printf("%d ", d);
       vertex[d] = GRAY;

       for ( int i = 1; i <= total_node; i++)
       {
            // Not visited,
            if ( edge[d][i] == WHITE  && vertex[i] != GRAY )
            {
                edge[d][i] = edge[i][d] = GRAY;
                q.push(i);
                vertex[i] = GRAY;
            }
       }
    }
}
