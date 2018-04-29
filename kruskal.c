#include<stdio.h>
int a,b,u,v,n,i,j,ne=1;
int parent[20]={0},min,mincost=0,cost[20][20];
void main()
{
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
 printf("The edges of spanning tree are\n");
 while(ne<n)
 {
  for(i=1,min=999;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {    
    if(cost[i][j]<min)
     {
      min=cost[i][j];
      a=u=i;
      b=v=j;
     }
   }
  }
  while(parent[u])
   u = parent[u];
  while(parent[v])
   v = parent[v];
  if(u!=v)
  {
   printf("Edge %d:(%d->%d) cost:%d\n",ne++,a,b,min);
   mincost+=min;
   parent[v]=u;
  }
  cost[a][b]=cost[b][a]=999;
 }
 printf("Minimun cost=%d\n",mincost);
}
