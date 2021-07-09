#include<stdio.h>
#include<time.h>
int arr[50][50],queue[50],visit[50],n,i,j,f=0,r=-1;

void bfs(int v)
{
    
    for(i=1;i<=n;i++)
    if(arr[v][i] && !visit[i])
    queue[++r]=i;
    if(f<=r)
    {
        visit[queue[f]]=1;
        bfs(queue[f++]);
    }
}

int main()
{
    clock_t start,end;
    double time;
    int v;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        queue[i]=0;
        visit[i]=0;
    }
    printf("\nEnter graph data in matrix form:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    start = clock();
    bfs(v);
    end = clock();
    time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\n The nodes which are reachable are:\n");
    for(i=1;i<=n;i++)
    if(visit[i])
    printf("%d\t",i);
    printf("\nTime taken : %lf\n",time);
}
