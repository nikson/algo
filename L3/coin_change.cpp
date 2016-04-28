#include <stdio.h>
#define FOR(i,n) for(i=0; i<n;i++)
#define FORC(i,c,n) for(i=c; i<=n;i++)

#define TOTAL 100000

long nway[TOTAL+1];

int coin[] = { 50, 25, 10, 5, 1 };

int main()
{
    int i, j, c;

    int dollar = 10;
    int total_coin = 5;

    nway[0] = 1;

    // Memorizing
    FOR(i, total_coin)
    {
        c = coin[i];

        FORC (j, c, dollar)
        {
            nway[j] += nway[j-c];
        }
    }

    printf("Total %ld way you can make %ld$\n", nway[dollar], dollar);

    return 0;
}
