#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int column[MAX], solution_found_flag;

int place(int k, int i);
void nQueen(int k, int n);

int main()
{
	int n;

	while( scanf(" %d", &n) == 1)
	{
		if( n == 0)		break;

		solution_found_flag = 0;
		nQueen(1, n);

		if ( solution_found_flag )
        {
            for( int l = 1; l <= n; l++)
                printf("%d ", column[l]);
            printf("\n");
        }
        else
        {
            printf("No Solution Found\n");
        }
	}

	return 0;
}

void nQueen(int k, int n)
{
	for(int i = 1; i <= n; i++)
	{
		if( solution_found_flag ) return ;

		if( place(k,i))
		{
			column[k] = i;

			if( k == n)
			{
				solution_found_flag = 1;
			}
			else
            {
                nQueen(k+1, n);
            }
		}
	}
}

int place(int k, int i)
{
	for( int j = 1; j < k; j++)
    {
		if( (column[j] == i) || (abs(column[j]-i) == abs(j-k)))
			return  0;
    }
	return 1;
}
