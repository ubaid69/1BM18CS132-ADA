#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insertion_Sort(int [], int);
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
    Insertion_Sort(arr, n);
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

void Insertion_Sort(int arr[], int n){
   if (n <= 1)
      return;
   Insertion_Sort( arr, n-1 );
   int last = arr[n-1];
   int j = n-2;
   while (j >= 0 && arr[j] > last){
      arr[j+1] = arr[j];
      j--;
   }
   arr[j+1] = last;
}
