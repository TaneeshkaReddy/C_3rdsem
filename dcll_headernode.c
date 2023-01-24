#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node* prev;
  int data;
  struct node* next;
};
typedef struct node N;

void display(N*);

N* create(N* header, int n)
{
  N* ptr=header;
  for(int i=1;i<=n;i++)
  {
    N *nn=malloc(sizeof(N));
    nn->prev=NULL;
    nn->next=NULL;
    printf("Enter data of node%d\n",i);
    scanf("%d",&nn->data);
    nn->prev=ptr;
    nn->next=header;
    ptr->next=nn;
    header->prev=nn;
    ptr=ptr->next;
    header->data++;
    
  }
  display(header);
  return(header);
}

void display(N* header)
{
  N* temp;
  temp=header->next;
  printf("Linked list:\n");
  do
  {
  printf("%d\t",temp->data);
  temp=temp->next;
  } while (temp!=header);
}


N* insertatbeg(N *header,int data)
{
  N* temp =header->next;
  N* newnode=malloc(sizeof(N));
  newnode->data=data;
  newnode->prev=NULL;
  newnode->next=NULL;
  newnode->prev=header;
  newnode->next=temp;
  header->next=newnode;
  temp->prev=newnode;
  display(header);
  return(header);
}



N* insertatpos(N* header,int data,int pos)
 {
   N* temp;
   temp=header->next;
   int count=0;
   while(count!=(pos-1))
   {
     temp=temp->next;
     count++;
   }
   N *ptr2=temp->next;
   N *nn=malloc(sizeof(N));
   nn->prev=NULL;
   nn->next=NULL;
   nn->data=data;
   nn->prev=temp;
   nn->next=ptr2;
   temp->next=nn;
   ptr2->prev=nn;
   display(header);
   return(header);
 }

 N* deleteatbeg(N* header)
 {
   N *temp;
   temp=header->next;
   N* temp2=temp->next;
   header->next=temp2;
   temp2->prev=header;
   free(temp);
   temp=NULL;
   display(header);
   return(header);
 }

// N* deleteend(N* head)
// {
//   N *temp,*temp2;
//   temp=head->prev->prev;
//   temp2=head->prev;
//   temp->next=head;
//   head->prev=temp;
//   free(temp2);
//   temp2=NULL;
//   print(head);
//   return(head);
// }

// N* deletepos(N* head,int pos)
// {
//   N *temp,*temp2;
//   temp=head;
//   while(pos>1)
//   {
//     temp=temp->next;
//     pos--;
//   }
//   temp2=temp2->next;
//   temp->next=temp2->next;
//   temp2->next->prev=temp;
//   free(temp2);
//   print(head);
//   return(head);
// }

// N* deletekey(N* head,int data)
// {
//   N8 temp;
//   temp=head;
//   int f=0,pos=1;
//   do
//   {
//     if(temp->next->data=data)
//     {
//       f=1;
//       break;
//     }
//     temp=temp->next;
//     pos++;
//   }while(temp->nwxt!=head);
//   if(f==0)
//   {
//     printf("  n ot found\n");

//   }
//   else{
//     deletepos(head,pos);
//   }
//   return head;
// }

// void searchkey(N* head, int data)
// {
//   N* temp;
//   temp=head->next;
//   int f=0;
//   do
//   {
//     if(temp->data=data)
//     {
//       f=0;
//       break;
//     }
//     temp=temp->next;
//   }while(temp->next=head);
//   if(f==0)
//   {
//     printf("not found\n");
//   }
//   else{
//     printf("found");
//   }
// }

// N* reverse(N* head)
// {
//   N *temp,*temp2,*temp3;
//   temp=head->next;
//   temp2=head->next->next;
//   temp3=head->next->next->next;
//   temp->prev=NULL;
//   do
//   {
//     temp2->next=temp;
//     temp2->prev=temp3;
//     temp=temp2;
//     temp2=temp3;
//     temp3=temp3->next;
//   }while(temp!=head)
//   temp2->next=temp;
//   temp2->prev=head->next;
//   head=temp2;
//   print(head);
//   return(head);
// }

// N* sort(N* )


  
// }

void main()
{
  int n,choice,data,pos;
  N *header=malloc(sizeof(N));
  header->data=0;
  header->next=header;
  header->prev=header;

  printf("Enter number of nodes\n");
  scanf("%d",&n);
  for(;;)
  {
  printf("Enter choice :1.create 2.display 3.insertstart  5.insertpos 6.deletestart  8.deletepos 9.deletekey 10.search 11.orderedlist 12.reverse 13.copy 14exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:header=create(header,n);break;
    case 2:display(header);break;
    case 3:printf("enter data to be inserted\n");
    scanf("%d",&data);
    header=insertatbeg(header,data);break;
    
    case 5: printf("Enter data to be inserted and positoin\n");
    scanf("%d%d",&data,&pos);
    insertatpos(header,data,pos);
    break;

    case 6: header=deleteatbeg(header);break;
    default:printf("Exit successfull\n");exit(0);
  }
  }
  }
  
