#include <stdio.h>
#include <time.h>
 
void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", frompeg, topeg);
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\n Move disk %d from peg %c to peg %c", num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}

 
int main()
{
    int num;
    clock_t start,end;
    double time_taken;
 
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    
    start = clock();
    towers(num, 'A', 'C', 'B');
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    
    printf("\n\nTime taken: %f s",time_taken);
    
    return 0;
}