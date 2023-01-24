#include<stdio.h>
#include<stdlib.h>

struct queue
{
  int front,rear,size,*a;
};

typedef struct queue Q;

void create(Q *q)
{
  printf("Enter number of items in queue\n");
  scanf("%d",&q->size);
  q->a=malloc(sizeof(int)*q->size);
  q->front=-1;
  q->rear=-1;
}
void display(Q *q)
{
  int i=front;
  if((f==-1 && r==-1))
  {
    printf("Queue empty\n");
  }
  else{
   printf("Queue is:\n");
  }
}

void main()
{
  Q *q;
  int choice,data;
  create(q);

  for(;;)
  {
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter data to insert\n");
       enqueue(q,data);break;
    }
  }
}