#include<stdio.h>
void main()
{
  int a[10],b[10],n,i,j;
  int *ptr;
  printf("Enter the size of the array\n");
  scanf("%d",&n);
 printf("Enter elements of the array\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }

 ptr=&a;
 for(j=(n-1);j>=0;j--)
 {
   b[j]=*ptr;
   ptr++;
 }

 printf("Reversed array :\n");
 for(i=0;i<n;i++)
 {
  printf("%d\n",b[i]);
 }
}





