#include <stdio.h>

#define MAX(a,b) (a > b) ? (a) : (b)

int knapsack(int W, int wt[], int val[], int n);

int main()
{
#ifdef TEST
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // TEST

    int val[] = {60, 100, 120};
    int wt[] = {1, 2, 3};
    int W = 5;
    int n = 3;
    
    int result = knapsack(W, wt, val, n);
	printf("\nValue = %d", result);

    return 0;
}

int knapsack(int W, int wt[], int val[], int n)
{
   int i, w;

   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = MAX(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   /*/  Print matrix
    
   for (i = 0; i <= n; i++)
   {
        for (w = 0; w <= W; w++)
        {
            printf("%d ", K[i][w]);
        }

        printf("\n");
   }
   //*/

   return K[n][W];
}


