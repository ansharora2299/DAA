#include<stdio.h>
int a[20][20],visitorder[20],n,count=0;
void dfs(int a[20][20],int n,int visited[20],int source)
{
 int i;
 count++;
 visited[source]=count;
 for(i=1;i<=n;i++)
  if(a[source][i]==1 && visited[i]==0)
  {
   printf("%d->%d\n",source,i);
   dfs(a,n,visited,i);
  }
}
void main()
{
 int i,j,visited[20],source;
 printf("Enter number of vertices\n");
 scanf("%d",&n);
 printf("Enter the adjacency matrix\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 for(i=1;i<=n;i++)
    visited[i]=0;
 printf("Enter source node\n");
 scanf("%d",&source);
 dfs(a,n,visited,source);
 for(i=1;i<=n;i++)
  if(visited[i]==0)
    dfs(a,n,visited,i);
 for(i=1;i<=n;i++)
  visitorder[visited[i]]=i;
 printf("DFS Traversal\n");
 for(i=1;i<=n;i++)
    printf("%c\t",visitorder[i]+64);
}
