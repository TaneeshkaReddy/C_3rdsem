#include<stdio.h>
#include<string.h>

struct inventory
{
  char name[30];
  int number;
  float price;
};
typedef struct inventory I;


void main()
{
  I product[2];
  I *ptr;
 ptr=product;
 int i;

  strcpy(product[0].name,"OIL");
  product[0].number=6;
  product[0].price=67.50;

  strcpy(product[1].name,"RIG");
  product[1].number=37;
  product[1].price=88.50;
  
  // for(ptr=product;ptr<product+1;ptr++)
  // {
  //  printf("%s\n%d\n%f",ptr->name,ptr->number,ptr->price);
  // }
  //or

  for(i=0;i<=1;i++)
  {
    printf("%s\n%d\n%f\n",ptr->name,ptr->number,ptr->price);
    ptr++;
  }


  // printf("%s\n%d\n%f",product[0].name,product[0].number,product[0].price);
}