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
N* insertatend(N*,int data);
N* deletefront(N*);

void main()
{
  int n;
  N *head=malloc(sizeof(N));
  printf("Enter number of items in list:\n");
  scanf("%d",&n);
  N* tail=head;
  tail=createlist(head,tail,n);
  printf("list is:\n");
  display(tail);
  tail=deletefront(tail);
   printf("after deletion list is:\n");
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

N* deletefront(N* tail)
{
  N* ptr=tail->next;
  tail->next=ptr->next;
  free(ptr);
  ptr=NULL;
  return(tail);
}