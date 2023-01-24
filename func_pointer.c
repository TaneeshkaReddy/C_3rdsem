#include<stdio.h>

void add(int a,int b);

void main()
  {
    void (*addptrfunc)(int,int)=&add;
    int c=10,d=35;

    (*addptrfunc)(c,d);
      }
void add(int a,int b)
{
  printf("%d",(a+b));
  
}