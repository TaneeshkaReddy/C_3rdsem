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

printf("Enter the value and its position to be inserted\n");
scanf("%d%d",&value,&pos);


for(j=n-1;j>=pos-1;j--)
{
   ptr=&a[j+1];
   *ptr=*(ptr-1);
}
  a[pos-1]=value;

 printf("elements of an array after insertion:\n");
  for(i=0;i<=n;i++)
  {
printf("%d\n",a[i]);
  }
}



