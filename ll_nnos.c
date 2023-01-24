#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* link;
};

struct node* createnode(struct node*,int number);
void traverse(struct node*);
struct node* insertatstart(struct node*);
struct node* insertatend(struct node*);
struct node* insertatpos(struct node*);
struct node* deleteatstart(struct node*);
struct node* deleteatend(struct node*);
struct node* deleteatpos(struct node*);
struct node* orderedlist(struct node*);

// struct node* deletekey(struct node*);
// struct node* searchbykey(struct node*);
// struct node* reverse(struct node*);



void main()
{
  int n;
  struct node* head=malloc(sizeof(struct node));
  struct node* head2=malloc(sizeof(struct node));

  for(;;)
  {
    int choice;
    printf("Enter your choice:\n");
    printf("1.Create list \n2.Display \n3.Insert node at start \n4.Insert node at end \n5.Insert node at a position \n6.Delete at start \n7.Delete at end \n8.Delete at position \n9.Delete key \n10.Search key \n11.Reverse lis\n12.Ordered List\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:printf("enter number of items in list\n");
             scanf("%d",&n);
            head=createnode(head,n);
            break;
        
      case 2:traverse(head);
             break;
      
      case 3: head=insertatstart(head);
              traverse(head);
              break;

      case 4: head=insertatend(head);
              traverse(head);
              break;

      case 5: head=insertatpos(head);
              traverse(head);
              break;

      case 6: head=deleteatstart(head);
              traverse(head);
              break;

      case 7: head=deleteatend(head);
              traverse(head);
              break;

      case 8: head=deleteatpos(head);
              traverse(head);
              break;
              
      case 12: head2=orderedlist(head2);

      default:printf("Exit\n");
              exit(0);

    }
  }
}


struct node* createnode(struct node* head,int number)
{
  int data;
  printf("Enter data of node1:\n");
  scanf("%d",&data);
  head->data=data;
  head->link=NULL;

  struct node* temp=head;
  for(int i=2;i<=number;i++)
  {
    struct node* newNode=malloc(sizeof(struct node));
    int data1;
    printf("Enter data of node%d:\n",i);
    scanf("%d",&data1);
    newNode->data=data1;
    newNode->link=NULL;
    temp->link=newNode;
    temp=temp->link;
    }
    return(head);
  }

void traverse(struct node* head)
{
  if(head==NULL)
  {
    printf("List empty\n");
  }
  else{
  struct node* ptr=head;
  printf("The list is:\n");
   while(ptr!=NULL)
  {
    printf("%d\n",ptr->data);
    ptr=ptr->link;
  }
  }
    }
  

  struct node* insertatstart(struct node* head)
  {
    struct node* newNode=malloc(sizeof(struct node));
    int data;
    printf("Enter value to be inserted\n");
    scanf("%d",&data);
    newNode->data=data;
    newNode->link=head;
    head=newNode;
    return(head);
  }

  struct node* insertatend(struct node* head)
  {
    struct node* newNode=malloc(sizeof(struct node));
    int data;
    printf("Enter value to be inserted\n");
    scanf("%d",&data);
    newNode->data=data;
    newNode->link=NULL;
  
    struct node* temp=head;
    while(temp->link!=NULL)
    {
      temp=temp->link;
    }
    temp->link=newNode;
    return(head);
  }

  struct node* insertatpos(struct node* head)
  {
    int pos,data;
    printf("Enter the value to be inserted and its position\n");
    scanf("%d%d",&data,&pos);

    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;

    struct node* ptr=head;

    int count=1;
    while(count!=(pos-1))
    {
      ptr=ptr->link;
      count++;
    }
    newNode->link=ptr->link;
    ptr->link=newNode;
    return(head);
  }


  struct node* deleteatstart(struct node* head)
  {
    struct node*  temp=head;
    head=temp->link;
    free(temp);
    temp=NULL;
    return(head);
  }


struct node* deleteatend(struct node* head)
{
  struct node* temp=head;
  struct node* temp2=head;
  while(temp->link!=NULL)
  {
    temp2=temp;
    temp=temp->link;
  }
  temp2->link=NULL;
  free(temp);
  temp=NULL;
  return(head);
}

struct node* deleteatpos(struct node* head)
{
int count=1; int pos;
printf("Enter postion you want to delete\n");
scanf("%d",&pos);

struct node* temp=head;
struct node* temp2=head;

while(count!=pos)
{
  temp2=temp;
  temp=temp->link;
  count++;
}
temp2->link=temp->link;
free(temp);
temp=NULL;
return(head);
}

struct node* orderedlist(struct node* head2)
{
  struct node* newnode=malloc(sizeof(struct node));
  printf("enter number of items in list\n");
  scanf("%d",&n);
  head2=createnode(head2,n);
  printf("Enter data to be inserted in the list\n");
  scanf("%d",&newnode->data);
  newnode->link=NULL;

  struct node* ptr=head2;
  struct node* ptr1=head2;
  while(ptr!=NULL)
  {
    int temp;
    while(ptr1->next!=NULL)
    {
      if(ptr1->data>ptr1->next->data)
      {
        temp=ptr1->data;
        ptr1->data=ptr1->next->data;
        ptr1->next->data=temp;
      }
      ptr1=ptr1->next;
    } ptr1=head2;
}

while(ptr1!=NULL)
{
  if(newnode->data>head2->data)
  {
    
  }

}
}
