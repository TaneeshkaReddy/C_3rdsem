#include<stdio.h>
#include<stdlib.h>
int n;
void read(int*);
void display(int*);
void searchdelete(int*);

void main()
{
  int i,j;
  printf("Enter size of array\n");
  scanf("%d",&n);

  int *sp;
  sp=(int *)malloc(n*sizeof(int));

  read(sp);
  display(sp);
  searchdelete(sp);
}

void read(int *sp)
{
  int i,j;
  printf("Enter elements of array\n");
  for(i=0;i<n;i++)
  {
   scanf("%d",sp+i);
  }
}

void display(int *sp)
{
  int i,j;
  printf("Array elements:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\n",*(sp+i));
  }
}

void searchdelete(int *sp)
{
  int i,j,count=0;
  int key;
  printf("Enter the key to be searched and deleted\n");
  scanf("%d",&key);
 
  
  for(i=0;i<n;i++)
  {
    if(key==*(sp+i))
    {
      count++;
       for(j=i;j<n-1;j++)
       {
        *(sp+j)=*(sp+(j+1));
       }
    }
  }

  printf("Array after deletion:\n");
  for(i=0;i<=(n-count-1);i++)
  {
    printf("%d\n",*(sp+i));

  }
}


  
