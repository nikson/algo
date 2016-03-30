#include <stdio.h>

int a[100];

void QuickSort2(int arr[], int left, int right);
void QuickSort(int a[], int low, int high);
int partition(int a[], int p, int r);
void swap(int a[], int i, int p);

int main()
{
    int total;
    int i;

    printf("Enter number of items:");
    scanf("%d", &total);

    printf("Enter %d numbers\n", total);

    for (i =0; i < total; i++)
        scanf("%d", &a[i]);

    QuickSort(a, 0, total-1);

    printf("After Sort:");
    for (i =0; i < total; i++)
        printf(" %d ", a[i]);

    return 0;
}

// Pivot is first index: p
int partition(int a[], int p, int r){
    int x = a[p];
    int i = p+1;
    int j, temp;
    for ( j = p+1; j <= r; j++){
        if ( a[j] < x ){
            swap(a, i, j);
            i= i + 1;
        }
    }

    i = i-1;
    swap(a, i, p);

    return i;
}

// pivot is last index value: r
int partition_R(int a[], int p, int r){
    int x = a[r];
    int i = p;
    int j, temp;
    for ( j = p; j < r; j++){
        if ( a[j] < x ){
            swap(a, i, j);
            i= i + 1;
        }
    }

    swap(a, i, r);

    return i;
}

void QuickSort(int arr[], int l, int u) {

  if ( l < u ){
    int q = partition(a, l, u);
    QuickSort(a, l, q - 1);
    QuickSort(a, q + 1, u);
  }
}

void swap(int a[], int i, int p){
        int temp = a[i];
    a[i] = a[p];
    a[p] = temp;

}

// Old algoritm, using recursion 
void QuickSort2(int arr[], int left, int right) {

      int i = left, j = right;
      int tmp;
      int pivot = arr[left];

      while (i <= j) {

            while (arr[i] < pivot)     i++;

            while (arr[j] > pivot)     j--;

            if (i <= j) {

                  tmp = arr[i];

                  arr[i] = arr[j];

                  arr[j] = tmp;

                  i++;
                  j--;
            }

      };

      if (left < j)  QuickSort2(arr, left, j);
      if (i < right) QuickSort2(arr, i, right);

}

