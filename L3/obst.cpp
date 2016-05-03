#include <stdio.h>

#define INT_MAX 2147483647
#define MIN(a,b) (( a < b ) ? (a) : (b))
#define FOR(i,n) for(i=0;i<n;i++)
#define N 4

int W[N][N];
int C[N][N];
int R[N][N];

int keys[] = { 10, 12, 16, 21 };
int frq[] = { 4, 2, 6, 3 };


void wcr();
void print_values(int data[][N]);

int main()
{
    wcr();

    printf("Cost table:\n");
    print_values(C);

    printf("Roots table:\n");
    print_values(R);

    return 0;
}

void wcr(){
    int x, m, min;
    int i, j, k, l;

    // Build weight matrix
    FOR(i, N)
    {
        W[i][i] = frq[i];
        for ( j = i + 1; j < N; j++)
        {
            W[i][j] = W[i][j-1] + frq[j];
        }
    }

    //  Set cost matrix for L = 1
    FOR(i, N)
    {
        C[i][i] = W[i][i];
        R[i][i] = i;
    }

    // Build cost matrix for L=2..N
    for ( l = 2; l <= N; l++)
    {
        for ( i = 0; i <= N - l ; i++)
        {
            j = i + l - 1;

            m = i;
            min = INT_MAX;

            for ( k = i ; k <= j; k++ ){
                // Check range to avoid garbase value for out of range
                x =  ((k > i) ? C[i][k-1] : 0) +
                    ( (k < j) ? C[k+1][j] : 0);

                if ( x < min ){
                    m = k;
                    min = x;
                }
            }
            // save the min value and root for that value
            C[i][j] = W[i][j] + min;
            R[i][j] = m;
        }
    }
}

void print_values(int data[][N])
{
    int i, j;

    FOR(i,N)
    {
        FOR(j,N)
        {
            printf(" %5d", data[i][j]);
        }
        printf("\n");
    }
}
