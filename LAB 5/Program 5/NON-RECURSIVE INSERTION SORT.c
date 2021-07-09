#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Insert_Sort(int [], int);
int main()
{
    clock_t start,end;
    double time;
    int arr[100000], n, i;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter the elements in the array:\n");
    for (i = 0; i < n; i++)
    {
      arr[i] = rand()%100;
      printf("%d  ",arr[i]);
    }
    start = clock();
    Insert_Sort(arr, n);
    end = clock();
    time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nTime taken : %lf\n",time);
    printf("\nThe sorted list in ascending order is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
 
    return 0;
}

void Insert_Sort(int arr[], int n)
{
    int i, search, j;
    for (i = 1; i < n; i++) {
        search = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > search) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = search;
    }
}
