//insertion at a particular pos

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

void insert_atpos(struct node*,int data,int pos);
int main()
{
struct node* head=malloc(sizeof(struct node));
head->data=45;
head->link=NULL;

struct node* ptr=malloc(sizeof(struct node));
ptr->data=98;
ptr->link=NULL;
head->link=ptr;

struct node* ptr1=malloc(sizeof(struct node));
ptr1->data=3;
ptr1->link=NULL;
ptr->link=ptr1;

struct node* ptr2=malloc(sizeof(struct node));
ptr2->data=23;
ptr2->link=NULL;
ptr1->link=ptr2;

insert_atpos(head,67,2);

struct node* printptr=head;
while(printptr!=NULL)
{
  printf("%d\n",printptr->data);
  printptr=printptr->link;
}
return 0;
}


void insert_atpos(struct node*head,int data,int pos)
{
struct node* insertednode=malloc(sizeof(struct node));
insertednode->data=data;
insertednode->link=NULL;

struct node* temp=head;

int count=1;
while(count!=pos-1)
{
temp=temp->link;
count++;
}
insertednode->link=temp->link;
temp->link=insertednode;

}
