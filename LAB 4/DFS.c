#include<stdio.h>
#include<time.h>
int arr[50][50],reachable[50],n;

void dfs(int v)
{
    
    int i;
    reachable[v]=1;
    for(i=1;i<=n;i++)
    if(arr[v][i] && !reachable[i])
    {
        printf("\n %d->%d",v,i);
        dfs(i);
    }
}
int main()
{
    clock_t start,end;
    double time;
    int i,j,count=0;
    printf("\nEnter number of nodes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        reachable[i]=0;
        for(j=1;j<=n;j++)
        arr[i][j]=0;
    }
    printf("\nEnter the adjacency matrix: \n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&arr[i][j]);
    start = clock();
    dfs(1);
    end = clock();
    time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\n");
    for(i=1;i<=n;i++)
    {
        if(reachable[i])
        count++;
    }
    if(count==n)
    printf("\nGraph is connected!");
    else
    printf("\nGraph is not connected!");
    printf("\nTime taken : %lf\n",time);
}
