#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};
typedef struct node N;
void print_list(N*);
N* add_at_beg(N*,int data);
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

  head=add_at_beg(head,67);
  print_list(head);
}

N* add_at_beg(N* head,int data)
{
  N* temp=malloc(sizeof(N));
  temp->data=data;
  temp->link=head;
  head=temp;
  return(head);
}

void print_list(N* head)
{
  N* ptr1=head;
  if(head==NULL)
  {
    printf("LIst is empty\n");
    }

    while(ptr1!=NULL)
    {
      printf("%d\n",ptr1->data);
      ptr1=ptr1->link;
    }
}