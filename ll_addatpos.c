#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

typedef struct node N;
void add_at_pos(N*,int data,int pos);
void main()
{
  N *head=malloc(sizeof(N));
  head->data=45;
  head->link=NULL;

  N *current=malloc(sizeof(struct node));
  current->data=98;
  current->link=NULL;
  head->link=current;

  N *ptr=malloc(sizeof(struct node));
  ptr->data=3;
  ptr->link=NULL;
  current->link=ptr;

add_at_pos(head,67,2);
}

void add_at_pos(N* head,int data,int pos)
{
  N* ptr1=malloc(sizeof(N));
  ptr1->data=data;
  
  N* pointer=head;
  for(int i=2;i<pos-1;i++)
  {
    pointer=pointer->link;
  }
  pointer->link=
}