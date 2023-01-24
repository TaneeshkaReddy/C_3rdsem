#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* link;
};
void print_data(struct node*);
void add_at_end(struct node*,int data);
void main()
{
  struct node* head=malloc(sizeof(struct node));
  head->data=45;
  head->link=NULL;

  struct node* current=malloc(sizeof(struct node));
  current->data=98;
  current->link=NULL;
  head->link=current;

  current = malloc(sizeof(struct node));
  current->data=3;
  current->link=NULL;
  head->link->link=current;

 add_at_end(head,67);
 print_data(head);
 

}

void add_at_end(struct node* head,int data)
{
  struct node* temp=malloc(sizeof(struct node));
  temp->data=data;
  temp->link=NULL;

  struct node *ptr=head;
  while(ptr->link!=NULL)
  {
    ptr=ptr->link;
  }
ptr->link=temp;
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