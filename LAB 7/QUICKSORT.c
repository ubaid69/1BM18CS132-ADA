#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int [], int, int);
int main()
{
    clock_t start,end;
    double time;
    int i, n, a[100000];
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter the elements in the array:\n");
    for (i = 0; i < n; i++)
    {
      a[i] = rand()%100;
      printf("%d  ",a[i]);
    }
    start = clock();
    quicksort(a,0,n-1);
    end = clock();
    time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nTime taken : %lf\n",time);
    printf("\nThe sorted list in ascending order is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ",a[i]);
    }
 
    return 0;
}

void quicksort(int a[100000],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);

   }
}
