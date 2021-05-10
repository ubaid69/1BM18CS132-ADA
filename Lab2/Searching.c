#include <stdio.h>
#include<stdlib.h>
#include<time.h>
 
int search(int arr[], int l,int r, int x)
{
  
    
   if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     if (arr[r] == x)
        return r;
     return search(arr, l+1, r-1, x);
}


int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
       
        if (arr[mid] == x)
            return mid;
  
       
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
       
        return binarySearch(arr, mid + 1, r, x);
    }
    
   return -1;
}
  
 

int main()
{

    clock_t start,end;
    int size;
    int result,ch;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
    arr[i]=rand()%100;
    }
    int num;
    printf("Enter the number to be searched:");
    scanf("%d",&num);
    int n = sizeof(arr) / sizeof(arr[0]);
    
    while(1){
    printf("1.Linear Search\n2.Binary Search\n3.Exit\nEnter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:  start=clock();
    result = search(arr, 0,n-1, num);
     end=clock();
  
    (result == -1)
        ? printf("Element is not present in array\n")
        : printf("Element is present at index %d \n", result);
       
         printf("Time required:%f \n",(double)(end-start)/CLOCKS_PER_SEC);
    break;
    case 2:start=clock();
    result= binarySearch(arr, 0, n - 1, num);
     end=clock();
    (result == -1)
        ? printf("Element is not present in array\n")
        : printf("Element is present at index %d \n", result);
        
         printf("Time required:%f \n",(double)(end-start)/CLOCKS_PER_SEC);
    break;
    case 3:exit(0);
    break;
    default:printf("Invalid value.");
    }
   
    
    
    }
   
  
   
    (result == -1)
        ? printf("Element is not present in array\n")
        : printf("Element is present at index %d \n", result);
    return 0;
}