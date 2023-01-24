#include<stdio.h>
void main()
{
    int newvalue , i , pos , n;
    int a[100];

    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter the value to be inserted and its position\n");
    scanf("%d%d",&newvalue,&pos);

    for(i=n ; i>pos-1 ; i++)
    {
        a[i] = a[i-1];
    }
    a[pos-1]=newvalue;

    printf("The inserted array is : \n");
    for(i=0;i<=n;i++)
    {
        printf("%d",&a[i]);
    }
}