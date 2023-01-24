#include<stdio.h>

void main()
{
  int a[10];
  int n,i,j;
  int sum=0;
  int *ptr;

 printf("Enter size of array\n");
  scanf("%d",&n);
printf("Enter array elements\n");
for(i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}

ptr=a;
for(j=0;j<n;j++)
{
  
  sum=sum+(*ptr);
  ptr++;
}
printf("The sum of the array elements is:%d\n",sum);
}