#include<stdio.h>
int sumofseries(int n)
{
  int sum=0;
  if(n>0)
  {
    sum=n+sumofseries(n-1);
  }
  else
  return sum;
}
void main()
{
  int n;
  printf("Enter number\n");
  scanf("%d",&n);
  int ans=sumofseries(n);
  printf("sum= %d\n",ans);
}