#include<stdio.h>
#include<stdlib.h>
struct TIME
{
  int hr;
  int min;
  int sec;
  };
typedef struct TIME time;
void read( time *T);
void write( time *T);
time update(time *T);
void add( time *Ta,time *Tb,time *Tc);

void main()
{
  time T1,T2,T3,T4;
  int choice;
  
 
 for(;;)
 {
  printf("Enter 1.read and display 2.Update 3.Add two times 4. Exit\n");
  scanf("%d",&choice);
  switch(choice)
  {

   case 1: printf("For Time1:\n");
           read(&T1);
           printf("For Time2:\n");
           read(&T2);
           printf("Time1:\n");
           write(&T1);
           printf("Time2:\n");
           write(&T2);
           break;
    
   case 2 : printf("Enter the time to be updated\n");
            read(&T3);
             time result = update(&T3);
            printf("Time after updation:\n");
            printf("%d:%d:%d\n",result.hr,result.min,result.sec);
            break;

   case 3 : add(&T1,&T2,&T4);
            printf("Added time:\n");
            write(&T4);
            break;

  default: printf("Invalid choice\n");
           exit(0);
  }
 }
}


void read(time *T)
{
  printf("Enter time i  hrs,minutes and seconds:\n");
  scanf("%d%d%d",&T->hr,&T->min,&T->sec);

}


void write(time *T)
{
  printf("%d:%d:%d\n",T->hr,T->min,T->sec);
}

time update(time *T)
{
  T->sec++;

  if(T->sec>=60)
  {
    T->min=T->min+(T->sec)/60;
    T->sec=T->sec%60;
  }
  if(T->min>=60)
  {
    T->hr=T->hr+(T->min/60);
    T->min=T->min%60;
  }
  if(T->hr>=24)
  {
    T->hr=0;
    T->min=0;
    T->sec=0;
  }
  return(*T);
}

void add(time*Ta,time*Tb,time*Tc)
{
  Tc->hr=Ta->hr+Tb->hr;
  Tc->min=Ta->min+Tb->min;
  Tc->sec=Ta->sec+Tb->sec;

  if(Tc->sec>=60)
  {
    Tc->min=Tc->min+(Tc->sec)/60;
    Tc->sec=Tc->sec%60;
  }
  if(Tc->min>=60)
  {
    Tc->hr=Tc->hr+(Tc->min/60);
    Tc->min=Tc->min%60;
  }
  if(Tc->hr>=24)
  {
    Tc->hr=0;
    Tc->min=0;
    Tc->sec=0;
  }


}

  




