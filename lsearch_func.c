#include<stdio.h>
void search(int b[10],int key1);
int n;

void main()
  {
    int i,key;
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    int a[10];
    printf("Enter elements of the array\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("Enter the key to be searched\n");
    scanf("%d",&key);
    search(a,key);
  }

  void search(int b[10],int key1)
  {
    int j,count=0;
    for(j=0;j<n;j++)
    {
      if(key1==b[j])
      {
       count=1;
        break;
      }
      else{
        count=0;
      }
    }

    if(count==0)
    printf("Key not found\n");
    else if(count==1)
    printf("Key found\n");

  }
  

