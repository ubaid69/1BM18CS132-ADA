#include<stdio.h>
#include<time.h>

int a[50][50],n,indeg[50];
void indegree()
{
  int j,i,sum;
  for(j=0;j<n;j++)
  {
    sum=0;
    for(i=0;i<n;i++)
     sum+=a[i][j];
    indeg[j]=sum;
  }
}
void topology()
{
  int i,u,v,t[50],s[50],tos=-1,k=0;
  indegree();
  for(i=0;i<n;i++)
  {
    if(indeg[i]==0)
      s[++tos]=i;
  }
  while(tos!=-1)
  {
  u=s[tos--];
  t[k++]=u;
  for(v=0;v<n;v++)
  {
    if(a[u][v]==1)
    {
      indeg[v]--;
      if(indeg[v]==0) 
        s[++tos]=v;
    }
  }
 }
 printf("The Topological Sequence is:\n");
 for(i=0;i<n;i++)
   printf("%d ",(t[i]+1));
}
int main()
{
  clock_t start,end;
  double time;
  int i,j;
  printf("Enter number of nodes:\n");
  scanf("%d",&n);
  printf("\nEnter the adjacency matrix:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
  }
  start = clock();
  topology();
  end = clock();
  time = ((double)(end - start))/CLOCKS_PER_SEC;
  printf("\nTime taken : %lf\n",time);
}
