#include<stdio.h>
int n;

struct DISTANCE{
  int Meter;
  int Centimetre;
};
 void read(struct DISTANCE d[n] );
 void write(struct DISTANCE d[n]);
 void add(struct DISTANCE *p,struct DISTANCE d[n]);


void main()
{
  struct DISTANCE D[n],Sum;
  struct DISTANCE *ptr;
  ptr=&Sum;
  

  
  read(D);
  write(D);

  // struct DISTANCE result =
  add(ptr,D);
  
}


void read(struct DISTANCE d)
{
  int i,j;
  printf("Enter the number of distances you want to enter\n");
  scanf("%d",&n);
  printf("Enter the distances in form of meter and centimetre\n");
  for(i=0;i<n;i++)
  {
    printf("Distance %d:\n",(i+1));
    scanf("%d%d",&d[i].Meter,&d[i].Centimetre);

  }
  // printf("Enter distance in meter and centimetre resp.\n");
  // scanf("%d%d",&D->Meter,&D->Centimetre);
}


void write(struct DISTANCE d)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    printf("Distance %d:\n",(i+1));
  printf("%dm , %dcm\n",d[i].Meter,d[i].Centimetre);
}
}

void add(struct DISTANCE *p,struct DISTANCE d[n] )
{
  
  int i,j;
 p->Meter=0;
  p->Centimeter=0;
  for(i=0;i<n;i++)
  {
    p->Meter=p->Meter+d[i].Meter;
    p->Centimetre=p->Centimetre+d[i].Centimetre;
  }
  if((p->Centimetre)>=100)
  {
    p->Meter=(p->Meter)+(p->Centimetre/100);
    p->Centimetre=(p->Centimetre)%100;
  }
  printf("ADDED:\n");
  
  printf("%dm %dcm\n",p->Meter,p->Centimetre);
}