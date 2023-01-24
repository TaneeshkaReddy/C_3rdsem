#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* deletestart(struct node*);

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

head=deletestart(head);

struct node* traverse=head;
while(traverse!=NULL)
{
  printf("%d\n",traverse->data);
  traverse=traverse->link;
}
}

struct node* deletestart(struct node* head)
{
  if(head==NULL)
  {
    printf("list empty\n");
  }
  else{
    struct node* temp=head;
  head=head->link;
  free(temp);
  temp=NULL;
  }
  return(head);
}