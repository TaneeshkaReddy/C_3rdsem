#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int top;
  int size;
  int *a;
};

typedef struct stack S;

int isEmpty(S *sp);
int isFull(S *sp);

void create(S *sp)
{
  printf("Enter the size of stack\n");
  scanf("%d",&sp->size);
  sp->top=-1;
  sp->a=(int *)malloc(sizeof(int)*(sp->size));
  
}

void push(S *sp,int data)
{
  if(isFull(sp)==1)
  printf("Stack overflow\n");
  else{
       (sp->top)+=1;
       sp->a[sp->top]=data; 
  }
  display(sp);
}

void pop(S *sp)
{
  int y;
  if(isEmpty(sp)==1)
  printf("Stack underflow\n");
  else{
    y=sp->a[sp->top];
    (sp->top)-=1;
    printf("Popped element is:%d\n",y);
  }
  display(sp);
}

void peek(S *sp)
{
  if(isEmpty(sp)==1)
  printf("Stack is empty\n");
  else
  {
   printf("Peeked element:%d\n",sp->a[sp->top]);
  }
}

void display(S *sp)
{
  printf("Stack is:\n");
  for(int i=0;i<=sp->top;i++)
  {
     printf("%d ",sp->a[i]);
  }
  printf("\n");
}
int isEmpty(S *sp)
{
  if((sp->top)==-1)
  return 1;
  else
  return 0;
}

int isFull(S* sp)
{
  if((sp->top)==(sp->size)-1)
  return 1;
  else
  return 0;
}


int main()
{
  S sp;
  int choice,data;
  for(;;)
  {
  printf("Enter choice 1.Create 2.Push 3.Pop 4.Peek 5.Exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
           create(&sp);
           break;
    case 2:
           printf("Enter data to push\n");
           scanf("%d",&data);
           push(&sp,data);
           break;
    case 3:
           pop(&sp);
           break;
    case 4:
           peek(&sp);
           break;
    default:printf("Exit successfull\n");exit(0);
  }
}
}
