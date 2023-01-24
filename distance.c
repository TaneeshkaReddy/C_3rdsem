#include<stdio.h>


struct DISTANCE{
  int Meter;
  int Centimetre;
};
 void read(struct DISTANCE *);
 void write(struct DISTANCE *);
 struct DISTANCE add(struct DISTANCE*,struct DISTANCE*,struct DISTANCE*);


void main()
{
  struct DISTANCE D1,D2,D3;
  struct DISTANCE *ptr;
  ptr=&D3;

  printf("For distance 1:\n");
  read(&D1);
  printf("For distance 2:\n");
  read(&D2);
  printf("Distance 1:\n");
  write(&D1);
  printf("Distance 2:\n");
  write(&D2);

  struct DISTANCE result = add(&D1,&D2,ptr);
  printf("Added distances are:\n");
  printf("%dm , %dcm\n",result.Meter,result.Centimetre);
}


void read(struct DISTANCE *D)
{
  printf("Enter distance in meter and centimetre resp.\n");
  scanf("%d%d",&D->Meter,&D->Centimetre);
}


void write(struct DISTANCE *D)
{
  printf("%dm , %dcm\n",D->Meter,D->Centimetre);
}

struct DISTANCE add(struct DISTANCE *D, struct DISTANCE *DA,struct DISTANCE *DB)
{
  DB->Meter=(D->Meter)+(DA->Meter);
  DB->Centimetre=(D->Centimetre)+(DA->Centimetre);

  if((DB->Centimetre)>=100)
  {
    DB->Meter=(DB->Meter)+(DB->Centimetre/100);
    DB->Centimetre=(DB->Centimetre)%100;
  }

  
  
  return(*DB);
}