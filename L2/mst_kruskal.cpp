#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int d;
	int s;
	int w;
}data;

data g[25];

int parent[20];
int t[20][2];

int comp(const void *a, const void *b)
{
	data *x = (data *)a;
	data *y = (data *)b;
	
	return ( x->w - y->w);
}

int find(int i)
{
	while( parent[i] >= 0)
		i = parent[i];
	
	return i;
}


int kruskel(int v, int e)
{
	int i, j, k, l, mincost;
	
	i = l = 0;
	mincost = 0;
	
	qsort( g, e, sizeof(data), comp);
	
	for( i = 0; i <= v; i++)
		parent[i] = -1;
	
	i = 0;
	while( i < (v-1) && l < e )
	{
		
		j = find(g[l].d);
		k = find(g[l].s);
		
		if( j != k)
		{
			mincost = mincost + g[l].w;
			parent[j] = k;
			t[i][0] = g[l].d;
			t[i][1] = g[l].s;
			i++;
		}
		l++;
	}
	
	if( i != v-1)
	{
		printf("No Tree\n");
		return -1;
	}
	return mincost;
}

int main()
{
	int v, e, i, cost;
	
	// freopen("in.txt","rt", stdin);
	
	printf("Enter vertex and edge: ");
	scanf(" %d %d", &v, &e);
	
	for( i = 0; i < e; i++)
		scanf(" %d %d %d", &g[i].d, &g[i].s, &g[i].w);
	
	cost = kruskel(v,e);
	
	if( cost != -1)
	{
		for(i = 0;  i < v-1; i++)
			printf("%d %d\n", t[i][0], t[i][1]);
		
		printf("mincost = %d\n", cost);
	}
	return 0;
}
