#include<stdio.h>

struct inventory
{
  char name[30];
  int number;
  float price;
};

void main()
{
  struct inventory *ptr;
   
   printf("Enter the ")
  for(ptr=product;ptr<product+2;ptr++)
  {
    printf("%s%d%f\n",ptr->name);
  }
}