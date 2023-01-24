#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

void deleteatpos(struct node*,int pos);

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

deleteatpos(head,2);

struct node* traverse=head;
while(traverse!=NULL)
{
  printf("%d\n",traverse->data);
  traverse=traverse->link;
}
return 0;
}

void deleteatpos(struct node* head,int pos)
{
  int count=1;
  struct node* temp=head;
  struct node* temp2=head;

  while(count!=pos)
  {
   temp2=temp;
   temp=temp->link;
   count++;
  }
  temp2->link=temp->link;//here temp2 will point at node that exists before node to be deleted and temp is pointing to node to be deleted
  free(temp);
  temp=NULL;
}