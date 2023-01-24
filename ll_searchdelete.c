#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* link;
};
struct node* searchdelete(struct node*);

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

  head=searchdelete(head);
  struct node* traverse=head;
  printf("list is:\n");
while(traverse!=NULL)
{
  printf("%d\n",traverse->data);
  traverse=traverse->link;
}
}

struct node* searchdelete(struct node* head)
{
  struct node* temp=head;
  int key,pos=1;
  printf("Enter key to be searched and deleted\n");
  scanf("%d",&key);
  while(temp!=NULL)
  {
    pos++;
    if(temp->data==key)
    {
      break;
    }
    temp=temp->link;
  }

    struct node* temp2=head;
    struct node*temp3=head;
    int count=0;
    while(count!=pos)
    {
      temp3=temp2;
      temp2=temp2->link;
      count++;
    }
    temp3->link=temp2->link;
    free(temp2);
    temp2=NULL;
    return(head);
}

  


