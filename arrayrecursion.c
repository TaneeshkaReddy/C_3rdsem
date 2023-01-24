#include<stdio.h>
int sumofarray(int a[100],int n)
{
  int sum=0;
  if(n>=0)
  {
    sum=a[n]+sumofarray(a,n-1);
  }
  else
  return sum;
}
void main()
{
  int n;
  printf("Enter number of elements in array\n");
  scanf("%d",&n);
  int a[100];
  printf("Enter elements of array\n");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  int ans=sumofarray(a,n-1);
  printf("sum= %d\n",ans);
}