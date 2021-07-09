#include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i) {
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
  
    if (l < n && arr[l] > arr[large])
      large = l;
  
    if (r < n && arr[r] > arr[large])
      large = r;
      
    if (large != i) {
      swap(&arr[i], &arr[large]);
      heapify(arr, n, large);
    }
  }
  
  void HeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      
      heapify(arr, i, 0);
    }
  }

  
  int main() {
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
    HeapSort(arr, n);
    end = clock();
    printf("\nSorted array is \n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nTime taken : %lf\n",time);
  }
