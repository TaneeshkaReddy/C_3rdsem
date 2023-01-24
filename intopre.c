#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


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
    case '^':return(pow(a,b));
    case '$':return(pow(a,b));
    case '/':return(a/b);
    case '*':return(a*b);
    case '+':return(a+b);
    case '-':return(a-b);
  }
}

void create(S *sp)
{
  sp->array=(char *)malloc(sizeof(char)*sp->size);
  sp->top=-1;
}


void push(S *sp ,char symbol)
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

int precedence(char symbol)
{
  switch(symbol)
  {
    case '$':
    case '^':return 3;
    case '/':
    case '*':return 2;
    case '+':
    case '-':return 1;
    default: return 0;
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

void infixtoprefix(S *sp, char infix[100],char prefix[100])
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
                prefix[j++]=next;
               }
               break;
      case '+':
      case '-':
      case '/':
      case '*':
      case '^': 
      case '$': while((precedence(sp->array[sp->top])) >= (precedence(symbol)) )
                {
                  prefix[j++]=pop(sp);
                }
                push(sp,symbol);
                break;

     default: prefix[j++]=symbol;
    }
  }
  while(isEmpty(sp)==0)
  {
    prefix[j++]=pop(sp);
  }
  prefix[j]='\0';

}

void reverse(char a[100])
{
int len=strlen(a);
   char temp;  
    for (int i = 0; i < len/2; i++)  
    {  
      
        temp = a[i];  
        a[i] = a[len - i - 1];  
        a[len - i - 1] = temp;  
    }

}

void prefixevaluate(S *sp,char prefix[100])
{
  char symbol;
  int a,b,c;
  for(int i=0;i<strlen(prefix);i++)
  {
    symbol=prefix[i];
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
  printf("Result of prefix expression:%d\n",result);

}


void main()
{
  S *sp=malloc(sizeof(S));
  char infix[100];
  char prefix[100];
  create(sp);

  int choice;

   for(;;)
   {
    printf("1.Convert from infix to prefix\n2.Evaluate prefix expression\n3.exit\nEnter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1 :printf("Enter infix expression\n");
            scanf("%s",infix);
            // printf("Reversed infix:\n");
            reverse(infix);
            // printf("%s\n",infix);
            for(int i=0;i<strlen(infix);i++)
            {
             if(infix[i]=='(')
              {
               infix[i]=')';
              }
             else if(infix[i]==')')
              {
               infix[i]='(';
              }
            }
            infixtoprefix(sp,infix,prefix);
            reverse(prefix);
            printf("prefix expression:\n");
            printf("%s\n",prefix);
            break;

    case 2: reverse(prefix);

           // printf("reversed prefix expression:\n");
           // printf("%s\n",prefix);

           prefixevaluate(sp,prefix);
           break;

  default: printf("Invalid choice\n");
           exit(0);
    }
   }
}

  
  
