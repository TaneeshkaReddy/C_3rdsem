#include<stdio.h>
#include<stdlib.h>

struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
};

typedef struct tree T;

T* create(int data)
{
  T *newnode=malloc(sizeof(T));
  newnode->data=data;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}
void choice(T *rootnode)
{
  int n;
  int value;
  for(;;)
  {
  printf("Enter 1 to enter left node of %d\nenter 2 to enter right node of %d\nenter 3 to return to previous node/exit\n",rootnode->data,rootnode->data);
  scanf("%d",&n);
  switch(n)
  {
    case 1:printf("Enter data of left node\n");
           scanf("%d",&value);
           T *leftnode=create(value);
           rootnode->left=leftnode;
           choice(leftnode);
           break;
    case 2:printf("Enter data of right node\n");
           scanf("%d",&value);
           T *rightnode=create(value);
           rootnode->right=rightnode;
           choice(rightnode);
           break;
   case 3: return;
   default:printf("invalid choice\n");
    }
  }
}

void preorder(T *rootnode)
{
  if(rootnode!=NULL)
  {
  printf("%d\t",rootnode->data);
  preorder(rootnode->left);
  preorder(rootnode->right);
  }
}

void postorder(T *rootnode)
{
  if(rootnode!=NULL)
  {
  postorder(rootnode->left);
  postorder(rootnode->right);
  printf("%d\t",rootnode->data);
  }
}

void inorder(T *root)
{
  if(root!=NULL)
  {
  inorder(root->left);
  printf("%d\t",root->data);
  inorder(root->right);
  }
}




int main()
{
  int value;
  printf("Enter value of root node\n");
  scanf("%d",&value);
  T *rootnode=create(value);
  choice(rootnode);
  printf("\n");
  printf("Tree is:\n");

  printf("PREORDER:\n");
  preorder(rootnode);
  printf("\n");

  printf("POSTORDER:\n");
  postorder(rootnode);
  printf("\n");

  printf("INORDER:\n");
  inorder(rootnode);
  printf("\n");
  
  

}
