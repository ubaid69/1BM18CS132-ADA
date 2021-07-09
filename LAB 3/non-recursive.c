#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
clock_t start,end;
double time;
int a[100000], n, i, j, loc, temp;
printf("Enter number of elements in the array:\n");
scanf("%d", &n);
printf("The elements in the array are: \n");
for (i = 0; i < n; i++)
{
    a[i] = rand()%100;
    printf("%d\n",a[i]);
}
      start = clock();
for(i = 0; i < n - 1; i++)
{
loc=i;
for(j = i + 1; j < n; j++)
{
if(a[loc] > a[j])
loc=j;
}
if(loc != i)
{
temp=a[i];
a[i]=a[loc];
a[loc]=temp;
}
}
end = clock();
      time = ((double)(end - start))/CLOCKS_PER_SEC;
      printf("Time taken : %lf\n",time);
printf("Sorted Array using Selection Sort is:\n");
for(i = 0; i < n; i++)
printf("%d\n", a[i]);
return 0;
}
