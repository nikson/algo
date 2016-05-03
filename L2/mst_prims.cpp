#include <stdio.h>

#define  N 100
#define  INF 9999

typedef struct
{
	int  src;
	int  dis;
	int  weight;
	int  flag;
}GRAPH;

GRAPH graph[N];
long cost[N][N];
int vertex, edge, min;

void read_inputs();
void mst_prims();

int main()
{
	// freopen("in.txt","r",stdin);

	read_inputs();

	mst_prims();

	return 0;
}

void read_inputs()
{
	int e1, e2, w, i, j;
	int max = INF;

	printf("How many vertex & edge : ");
	scanf(" %d %d", &vertex, &edge);

	// Init cost table
	for( i = 0; i <= vertex; i++ )
		for( j = 0; j <= vertex; j++)
			cost[i][j] = INF;

	// Take all edge information
	for( i = 0; i < edge ; i++ )
	{
		printf("\nEnter e1 e2 w: ");
		scanf(" %d %d %d", &e1, &e2, &w);

		graph[i].src = e1;
		graph[i].dis = e2;
		graph[i].weight = w;

		cost[e1][e2] = w;
		cost[e2][e1] = w;

		if( w < max)
		{
		    min = i;
			max = w;
		}
	}

/*	for( i = 1; i <= vertex; i++ )
	{
		for( j = 1; j <= vertex; j++)
			printf("  %ld", cost[i][j]);

		printf("\n");
	}
*/
}

void mst_prims()
{
	long mincost;
	int  i, j, t,k, l, n;
	int temp[100];

	k = graph[min].src;
	l = graph[min].dis;
	mincost = cost[k][l];

	printf("\nMinimum Spanning Tree (Prims algorithm)");
	printf("\ne1 = %d   e2 = %d", graph[min].src, graph[min].dis);

	for( i = 1; i <= vertex; i++ )
	{
		if( cost[i][l] < cost[i][k] )
			 temp[i] = l;
		else temp[i] = k;
	}

	temp[l] = 0;
	temp[k] = 0;

	for( n = 2; n < vertex; n++)
	{
		min = INF;
		for( t = 1; t <= vertex; t++)
		{
			if( (temp[t] != 0 ) && ( cost[t][temp[t]] < min))
			{
					min = cost[t][temp[t]];
					j = t;
			}
		}

		mincost += cost[j][temp[j]];
		printf("\ne1 = %d   e2 = %d", j, temp[j]);
		temp[j] = 0;

		for( t = 1; t <= vertex; t++)
			if( (temp[t] != 0 ) && (cost[t][temp[t]] > cost[t][j]))
				temp[t] = j;

	}

	printf("\n\nMincost  = %ld\n", mincost);
}


/*/  Sample Input
4 6
1 2 2
1 3 3
1 4 1
2 3 2
2 4 1
3 4 4
//*/
