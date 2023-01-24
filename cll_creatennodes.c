#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
};
typedef struct node N;
N* createnode(N*,N*,int n);

void main()
{
  int n;
  N *head=malloc(sizeof(N));
  printf("Enter number of items in list:\n");
  scanf("%d",&n);
  N* tail=head;
  tail=createnode(head,tail,n);

  N*ptr=tail->next;
  do
  {
   printf("%d\n",ptr->data);
   ptr=ptr->next;
  } while (ptr!=tail);
  

}

N* createnode(N* head,N* tail,int n)
{
  printf("Enter data of node1\n");
  scanf("%d",&head->data);
  head->next=NULL;
  for(int i=2;i<=n;i++)
  {
   N* newnode=malloc(sizeof(N));
   printf("Enter data of node%d\n",i);
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   tail->next=newnode;
   newnode->next=head;
   tail=tail->next;
  }
return(tail);
}