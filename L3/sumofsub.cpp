#include <stdio.h>

bool found;
long x[1000], w[1000], m;

void print_solution(long k);
void sum_of_subset(long s, long k, long r);

int main()
{
	long  i, n, r;

	while( scanf(" %ld %ld", &n, &m) == 2)
	{
		if( n == 0 ) break;

		r =  0;
		for( i = 1; i <= n; i++)
		{
			scanf(" %ld", &w[i]);
			r += w[i];
		}

		sum_of_subset(0, 1, r);
	}
	return 0;
}

void sum_of_subset(long s, long k, long r)
{
	x[k] = 1;

	if(s + w[k] == m )
	{
		found = true;
		print_solution(k);
		return;
	}
	else if( s + w[k] + w[k+1] <= m)
    {
        sum_of_subset(s+w[k], k+1, r-w[k]);
    }

	if(( s + r - w[k] >= m ) && ( s + w[k+1] <= m))
	{
		x[k] = 0;
		sum_of_subset(s, k+1, r-w[k]);
	}
}

void print_solution(long k)
{
    printf("Solution #: ");
    for(int i = 1; i <= k; i++)
    {
        if( x[i] != 0)
        {
            printf("%ld ", w[i]);
        }
    }
    printf("\n");
}

/*/  Sample Inputs
5 30
5 10 13 12 17
5 30
5 10 13 15 17
//*/
