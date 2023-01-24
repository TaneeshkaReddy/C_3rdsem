#include<stdio.h>
#include<stdlib.h>

void read(int *p,int n);
void display(int *p,int n);
void insert(int *p,int n);
void delete(int *p,int n);
void sort(int *p,int n);
int search(int *p,int n,int key);

int main()
{
  int N,key1;
  int *sp;
  int choice;
  printf("enter the size of array\n");
  scanf("%d",&N);
   sp=(int*)malloc(N*sizeof(int));

   for(;;){
    printf("Enter 1.Read and display 2.Insert 3.Delete 4.sort 5.search 6.exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1: read(sp,N);
              display(sp,N);
              break;

      
      case 2: insert(sp,N);
              N=N+1;
              sp=(int *)realloc(sp,(N));
              display(sp,N);
              break;

      case 3: delete(sp,N);
              N=N-1;
              sp=(int *)realloc(sp,(N));
              display(sp,N);
              break;

      case 4:sort(sp,N);
             display(sp,N);
             break;
      
      case 5:printf("enter key to be searched");
             scanf("%d",&key1);
             int found = search(sp,N,key1);
             if(found==0)
             {
              printf("Key not present\n");
             }
             else{
              printf("Key found at position %d\n",found);
             }
             break;
          
      default:printf("Exit successfull\n");
              exit(0);
    }
    }
}


void read(int *p,int n)
{
  int i;
  printf("Enter elements of the array\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",(p+i));
  }
}

void display(int *p,int n)
{
  int i;
  printf("Elements are:\n");
  for(i=0;i<n;i++)
{
printf("%d\n",*(p+i));
}
}

void insert(int *p,int n)
{
  int i;
  int value,pos;
  printf("Enter value to be inserted at and it's position\n");
  scanf("%d%d",&value,&pos);

  for(i=n-1;i>=(pos-1);i--)
  {
    *(p+i+1)=*(p+i);
  }
  *(p+pos-1)=value;
  
  
}

void delete(int *p,int n)
{
int del,i;
printf("Enter value to be deleted\n");
scanf("%d",&del);
int foundpos = search(p,n,del);

for(i=foundpos-1;i<n-1;i++)
{
  *(p+i)=*(p+i+1);
}
}


int search(int *p,int n,int key)
{
  int i,count=0;
  for(i=0;i<n;i++)
  {
    if(*(p+i)==key)
    { 
      count++;
      return(i+1);
    }
  }
  if(count==0)
  {
    return (0);
  }
}

void sort(int *p,int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    int temp;
    for(j=0;j<n-1-i;j++)
    {
      if(*(p+j)>*(p+j+1))
      {
        temp=*(p+j);
        *(p+j)=*(p+j+1);
        *(p+j+1)=temp;
      }
    }
  }
  
}



   
