#include <stdio.h>

int a[100];
int b[100];

void MergeSort(int low, int high);
void Merge(int low, int mid, int high);

int main()
{
    int total;
    int i;

    printf("Enter number of items:");
    scanf("%d", &total);

    printf("Enter %d numbers\n", total);

    for (i =0; i < total; i++)
        scanf("%d", &a[i]);

    MergeSort(0, total-1);

    printf("After Sort:");
    for (i =0; i < total; i++)
        printf(" %d ", a[i]);

    return 0;
}

void MergeSort(int low, int high)
{
    if ( low < high )
    {
        int mid = (low + high) / 2;

        MergeSort(low, mid);

        MergeSort(mid+1, high);

        Merge(low, mid, high);
    }
}

void Merge(int low, int mid, int high)
{
    int h = low, i = low, j = mid + 1;
    int k, U;

    while ( h <= mid && j <= high )
        b[i++] = ( a[h] <= a[j]) ? a[h++] : a[j++];

    if ( h > mid )
    {
        k = j;
        U = high;
    }
    else
    {
        k = h;
        U = mid;
    }

    while (k <= U)
       b[i++] = a[k++];

    for ( k = low; k <= high; k++)
       a[k] = b[k];
}

