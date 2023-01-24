#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
};
typedef struct node N;

N* createlist(N*,N*,int n);
void display(N*);
N* insertatpos(N*,int data);

void main()
{
  int n;
  N* head=malloc(sizeof(N));
  N* tail=head;
  printf("Enter number of items in  list\n");
  scanf("%d",&n);
  tail=createlist(tail,head,n);

  printf("The list is:\n");
  display(tail);

  tail=insertatpos(tail,777);
  printf("The list after insertion:\n");
  display(tail);
}

N* createlist(N* tail,N* head ,int n)
{
  printf("Enter data of node1:\n");
  scanf("%d",&head->data);
  head->next=head;

  for(int i=2;i<=n;i++)
  {
    N* newnode=malloc(sizeof(N));
    printf("Enter data of node%d:\n",i);
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    tail->next=newnode;
    newnode->next=head;
    tail=newnode;
  }
return(tail);
}

void display(N* tail)
{
  N* ptr=tail->next;
  do
  {
   printf("%d\n",ptr->data);
   ptr=ptr->next;
  }while(ptr!=tail->next);
  
}

N* insertatpos(N* tail,int data)
{
  int pos;
  N* ptr=tail->next;
  printf("Enter pos where you want to insert item\n");
  scanf("%d",&pos);
  int count=1;
  N* newnode=malloc(sizeof(N));
  newnode->data=data;
  newnode->next=NULL;

  while(count!=(pos-1))
  {
    ptr=ptr->next;
    count++;
  }
  newnode->next=ptr->next;
  ptr->next=newnode;
  return(tail);
}