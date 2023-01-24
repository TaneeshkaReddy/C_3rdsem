#include<stdio.h>
void main()
{
 int a[10];
  int i,n,value,pos,j;
  int *ptr;
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  printf("Enter the elements of an array\n");
  for(i=0;i<n;i++)
  {
scanf("%d",&a[i]);
  }

  printf("Enter the position you want to delete\n");
  scanf("%d",&pos);

  for(j=pos-1;j<n-1;j++)
  {
    ptr=&a[j];
    *ptr=*(ptr+1);
  }
for(i=0;i<n-1;i++)
  {
printf("%d\n",a[i]);
  }


}