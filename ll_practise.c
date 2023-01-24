#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};
void count_nodes(struct node*);
void print_data(struct node*);
void main()
{
  struct node *head=malloc(sizeof(struct node));
  head->data=45;
  head->link=NULL;

  struct node* current=malloc(sizeof(struct node));
  current->data=98;
  current->link=NULL;
  head->link=current;

  current=malloc(sizeof(struct node));
  current->data=3;
  current->link=NULL;
  head->link->link=current;
  count_nodes(head);
  print_data(head);
  return 0;
}

void print_data(struct node* head)
{
  
  if(head==NULL)
  {
    printf("List is empty\n");
  }
struct node* ptr=head;
while(ptr!=NULL)
{
  printf("%d\n",ptr->data);
  ptr=ptr->link;
}
}

void count_nodes(struct node* head)
{
  int count=0;
  if(head==NULL)
  {
    printf("LIST EMPTY\n");
  }

struct node* ptr=head;
while(ptr!=NULL)
{
  count++;
  ptr=ptr->link;
}
printf("No. of nodes=%d\n",count);
}