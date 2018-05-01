#include<stdio.h>
#include<time.h>
void heapify(int[],int);
void main()
{
 int n,i,size,t;
 clock_t start,end;
 printf("Enter the limit\n");
 scanf("%d",&n);
 int a[n];
 for(i=0;i<n;i++)
  a[i]=rand();
 start=clock();
 heapify(a,n);
 //printf("Elements Heapified Are\n");
 //for(i=0;i<n;i++)
  //printf("%d ",a[i]);
 for(i=n;i>=1;i--)
 {
     t=a[1];
     a[1]=a[i];
     a[i]=t;
     size=i-1;
     heapify(a,size);
 }
 end=clock();
 //printf("The Sorted Elements Are\n");
 //for(i=0;i<n;i++)
 //printf("%d ",a[i]);
 double cputime;
 cputime=((double)(end-start))/CLOCKS_PER_SEC;
  printf("time is %f\n",cputime);
}
void heapify(int a[],int n)
{
 int k,i,j,n1,heap,v;
 n1=n;
 for(i=n1/2;i>=1;i--)
 {
  k=i;
  v=a[k];
  heap=0;
  while(!(heap)&&(2*k<=n1))
  {
   j = 2*k;
   if(j<n1)
    if(a[j]<a[j+1])
    j=j+1;
   if(v>a[j])
    heap=1;
   else
   {
       a[k]=a[j];
       k=j;
   }
  }
  a[k] = v;
 }
}
