#include <stdio.h>
void dij(int n,int v,int cost[10][10],int dist[])
{
 int i,u,count,w,visited[10],min;
 for(i=1;i<=n;i++)
 {
   visited[i]=0;
   dist[i]=cost[v][i];
 }
 visited[v]=1;
 dist[v]=0;
 count=2;
 while(count<=n)
 {
  min=999;
  for(w=1;w<=n;w++)
   if(dist[w]<min && !visited[w])
    min=dist[w],u=w;
  visited[u]=1;
  count++;
  for(w=1;w<=n;w++)
   if((dist[u]+cost[u][w]<dist[w]) && !visited[w])
    dist[w]=dist[u]+cost[u][w];
 }
}
void main()
{
 int n,source,i,j,cost[10][10],dist[10];
 printf("Enter the number of nodes\n");
 scanf("%d",&n);
 printf("Enter the cost matrix\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 printf("Enter the source node\n");
 scanf("%d",&source);
 dij(n,source,cost,dist);
 printf("Shortest path\n");
 for(i=1;i<=n;i++)
  if(i!=source)
   printf("%d->%d,cost=%d\n",source,i,dist[i]);
}
