#include<stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int finish;
}Job;

void activity_sort(int n);
void activity_sort1(int n);

int comp(const void *a, const void *b);
int comp1(const void *a, const void *b);

int main()
{
    int n;
    printf("Total input: ");
    scanf("%d", &n);

    // activity_sort(n);
    activity_sort1(n);

    return 0;
}


int comp(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;

    return x[1]-y[1];
}

void activity_sort(int n)
{
    int i, k;
    int start_end[100][2];

    for ( i = 0; i < n; i++ )
    {
        scanf("%d %d", &start_end[i][0], &start_end[i][1]);
    }

    qsort(start_end, n, sizeof(int)*2, comp);

    /*/
    printf("Print sorted data:\n");
    for ( i = 0; i < n; i++ )
    {
        printf("%d %d\n", start_end[i][0], start_end[i][1]);
    }
    //*/

    printf("Activity order: ");

    // select first
    k = 0;
    printf("%d ", k);

    for ( i = 1; i < n; i++ )
    {
        // if selected items finished time <= current items start time
        // than select it

        if (start_end[k][1] <= start_end[i][0])
        {
            printf ("%d ", i);
            k = i;
        }
    }

}

int comp1(const void *a, const void *b)
{
    Job *x = (Job *)a;
    Job *y = (Job *)b;

    return x->finish - y->finish;
}

void activity_sort1(int n)
{
    int i, k;
    Job start_end[100];

    for ( i = 0; i < n; i++ )
    {
        scanf("%d %d", &start_end[i].start, &start_end[i].finish);
    }

    qsort(start_end, n, sizeof(Job), comp);

    /*/
    printf("Print sorted data:\n");
    for ( i = 0; i < n; i++ )
    {
        printf("%d %d\n", start_end[i].start, start_end[i].finish);
    }
    //*/

    printf("Activity order: ");

    // select first item
    k = 0;
    printf("%d ", k);

    for ( i = 1; i < n; i++ )
    {
        // if selected items finished time <= current items start time
        // than select this

        if (start_end[k].finish <= start_end[i].start)
        {
            printf ("%d ", i);
            k = i;
        }
    }
}
