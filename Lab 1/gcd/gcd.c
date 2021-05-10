#include <stdio.h>
#include <time.h>

int gcd(int n1, int n2) 
{
    if(n2 != 0)
    {
		return gcd(n2, n1 % n2);
	}
    else
    {
        return n1;
	}
}

int main() 
{
    int n1,n2,num;
    clock_t start,end;
    double time_taken;
    
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    
    start = clock();
    num = gcd(n1,n2);
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    
    printf("\nGCD of %d and %d = %d", n1, n2,num);
    printf("\n\nTime taken: %lf s",time_taken);
    return 0;
}
