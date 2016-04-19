#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int bit;
	int parent;
	int value;
	char str[50];
}Data;

Data data[100];
int pos[500];

int comp(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;

	return( data[*y].value - data[*x].value);
}

void Huffman(int n)
{
	int i, total, left, right;

	total = n - 1;

	for( i = 0; i < n-1; i++)
	{
		// reverse sort
		qsort(pos, n - i, sizeof(int), comp);

		left =	pos[n-i-1];
		right = pos[n-i-2];

		// keep binary tree at the end of array, and use the position
		total++;
		data[total].parent = 0;
		data[total].value = data[left].value + data[right].value;

		data[left].bit = 0;
		data[left].parent = total;
		data[right].bit = 1;
		data[right].parent = total;

		// remove last two data and replace with newly created node
		pos[n-i-2] = total;
	}

}

void print_bit(int i)
{
	if( data[i].parent)
	{
		print_bit(data[i].parent);
		printf("%d", data[i].bit);
	}
}

int main()
{
	long n, i;

//	freopen("in.txt","rt",stdin);

	while( scanf(" %ld", &n) == 1)
	{
		if( n == 0)			break;

		for( i = 0; i < n; i++)
		{
			scanf(" %s %d", data[i].str, &data[i].value);

			pos[i] = i;
		}

		Huffman(n);

		for( i = 0; i < n; i++)
		{
			printf("\n%s : ", data[i].str);
			print_bit(i);
		}
		printf("\n");

	}
	return 0;
}


