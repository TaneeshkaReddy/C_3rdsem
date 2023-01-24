#include<stdio.h>
void main() 
{
    int n,i,newval,pos,j;
    int a[10];

    printf("enter size of array\n");
    scanf("%d",&n);

    printf("enter the elements of the array\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("enter the new value to be inserted and its position\n");
    scanf("%d%d", &newval, &pos);

    for(j=n-1; j>=pos-1; j--)
    {
        a[j+1]=a[j];
    }
    a[pos-1] = newval;

    printf("the new array is\n");
    for(i=0;i<=n;i++)
    {
        printf("%d\n", a[i]);
    }
}