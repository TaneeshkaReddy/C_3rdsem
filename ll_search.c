#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* link;
};
void search(struct node*);

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

  search(head);
}

void search(struct node* head)
{
  struct node* temp=head;
  int key,count=0,pos=0;
  printf("Enter key to be searched\n");
  scanf("%d",&key);
  while(temp!=NULL)
  {
    pos++;
    if(temp->data==key)
    {
      printf("key found at position: %d\n",pos);
      count=1;
      break;
    }
    temp=temp->link;
  }

    if(count==0)
    {
      printf("key not found\n");
    }
  }
      
  


