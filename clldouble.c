#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node* prev;
  int data;
  struct node* next;
};

typedef struct node N;
N* createlist(N*,N*,int n);
void display(N*);
N* reverse(N*);

void main()
{
  N* head=malloc(sizeof(N));
  N* tail=head;
  int n;
  printf("Enter number of nodes\n");
  scanf("%d",&n);
  tail=createlist(tail,head,n);
  printf("The list is\n");
  display(tail);

  tail=reverse(tail);
  printf("The reversed list is\n");
  display(tail);
}

N* createlist(N* tail, N* head , int n)
{
  printf("Enter data of node1:\n");
  scanf("%d",&head->data);
  head->next=head;
  head->prev=head;

  for(int i=2;i<=n;i++)
  {
    N* newnode=malloc(sizeof(N));
    printf("Enter data of node%d:\n",i);
    scanf("%d",&newnode->data);
    newnode->prev=tail;
    newnode->next=head;
    tail->next=newnode;
    head->prev=newnode;
    tail=tail->next;
    
  }
  return tail;
}

void display(N* tail)
{
  N* ptr=tail->next;
  do
  {
  printf("%d\n",ptr->data);
  ptr=ptr->next;
  } while (ptr!=tail->next);
  
}

N* reverse(N* tail)
{  
   N* temp;
  tail=tail->next;
  N* temp3=tail;
  do
  {
    temp=temp3->prev;
    temp3->prev=temp3->next;
    temp3->next=temp;
    temp3=temp3->prev;
  }while(temp3!=tail);
  return(tail);
}