#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Sel_Sort(int [], int, int);
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
    Sel_Sort(arr, 0, n);
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


void Sel_Sort(int arr[], int i, int n)
{
    int j;
    int min = i;
    for (j = i + 1; j < n; j++)
    {
       
        if (arr[j] < arr[min]) {
            min = j;    
        }
    }
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
    if (i + 1 < n) {
        Sel_Sort(arr, i + 1, n);
    }
}
