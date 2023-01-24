#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stack
{
  int top;
  int size;
  char *array;
};
typedef struct stack S;

int calculate(int a,int b,char symbol)
{
  switch(symbol)
  {
    case '^':return(pow(b,a));
    case '$':return(pow(b,a));
    case '/':return(b/a);
    case '*':return(b*a);
    case '+':return(b+a);
    case '-':return(b-a);
  }
}

int isEmpty(S *sp)
{
  if(sp->top==-1)
  {
    return 1;
  }
  else
  return 0;
}

void create(S* sp)
{
  sp->array=(char *)malloc(sizeof(char)*sp->size);
  sp->top=-1;
}

int precedence(char symbol)
{
  switch(symbol)
  {
  case '$':
  case '^':return 3;
  case '*':
  case '/':return 2;
  case '+':
  case '-':return 1;
  default:return 0;
  }

}

void print(char postfix[100])
{
  int i=0;
  printf("The postfix expression is:");
  while(postfix[i])
  {
    printf("%c",postfix[i++]);
  }
  printf("\n");
}


void push(S *sp,char symbol)
{
  sp->top+=1;
  sp->array[sp->top]=symbol;
}

char pop(S *sp)
{
  char y=sp->array[sp->top];
  sp->top-=1;
  return y;
}

void infixtopostfix(S *sp, char infix[100],char postfix[100])
{
  char symbol,next;
  int length=0;
  int j=0;
  int k=0;
  while(infix[k]!='\0')
  {
    length++;
    k++;
  }
  for(int i=0;i<length;i++)
  {
    symbol=infix[i];
    switch(symbol)
    {
      case '(':push(sp,symbol);break;
      case ')':while((next=pop(sp))!='(')
               {
                postfix[j++]=next;
               }
               break;
      case '+':
      case '-':
      case '/':
      case '*':
      case '^': 
      case '$': while((precedence(sp->array[sp->top])) >= (precedence(symbol)) )
                {
                  postfix[j++]=pop(sp);
                }
                push(sp,symbol);
                break;

     default: postfix[j++]=symbol;
    }
  }
  while(isEmpty(sp)==0)
  {
    postfix[j++]=pop(sp);
  }
  postfix[j]='\0';

}

void postfixevaluate(S *sp,char postfix[100])
{
  char symbol;
  int a,b,c;
  for(int i=0;i<strlen(postfix);i++)
  {
    symbol=postfix[i];
    switch(symbol)
    {
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
      case '$':a=pop(sp)-'0';
               b=pop(sp)-'0';
               c=calculate(a,b,symbol);
               push(sp,(c+'0'));break;
      default: push(sp,symbol);
      }
  }
  int result=pop(sp)-'0';
  printf("Result of postfix expression:%d\n",result);

}

int main()
{
  S *sp=malloc(sizeof(S));
  char infix[100];
  char postfix[100];
  create(sp);


  // printf("Enter infix expression\n");
  // gets(infix);
  // infixtopostfix(sp,infix,postfix);
  // print(postfix);
  // postfixevaluate(sp,postfix);
  int choice;

   for(;;)
   {
    printf("1.Convert from infix to postfix\n2.Evaluate postfix expression\n3.exit\nEnter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:printf("Enter infix expression\n");
            scanf("%s",infix);
            infixtopostfix(sp,infix,postfix);
            print(postfix);
            break;
     case 2: postfixevaluate(sp,postfix);
             break;
     default:printf("Exit successfull\n"); 
             exit(0);
     
    }
   }
}
