#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node* prev;
  int data;
  struct node* next;
};
typedef struct node N;

N* reverse(N*);

void main()
{
   N* header=malloc(sizeof(N));
   header->data=3;
   header->next=header;
   header->prev=header;
   
   N* p1=malloc(sizeof(N));
   p1->data=67;
   p1->next=header;
   p1->prev=header;
   header->next=p1;
   header->prev=p1;

   N* p2=malloc(sizeof(N));
   p2->data=87;
   p2->next=header;
   p2->prev=p1;
   p1->next=p2;
   header->prev=p2;

   N* p3=malloc(sizeof(N));
   p3->data=22;
   p3->next=header;
   p3->prev=p2;
   p2->next=p3;
   header->prev=p3;

    N *t1=header->next;
   while(t1!=header)
   {
    printf("%d\n",t1->data);
    t1=t1->next;
   }

   header=reverse(header);
   N *t=header->next;
   while(t!=header)
   {
    printf("%d\n",t->data);
    t=t->next;
   }
}



N* reverse(N* header)
{
  N *ptr=header->next;
  N* temp;

  do
  {
    temp=ptr->prev;
    ptr->prev=ptr->next;
    ptr->next=temp;
    ptr=ptr->prev;
    
  }while(ptr!=header);
  // N *temp2;
  // temp2=header->prev;
  // header->prev=header->next;
  // header->next=temp;
  return(header);
}