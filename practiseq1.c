#include<stdio.h>
#include<stdlib.h>

struct Student
{
  char name[100];
  int reg_no;
  int marks[3];
  float average_marks;
};
typedef struct Student S;

void read(S* sp,int N)
{
  for(int i=0;i<N;i++)
  {
   printf("For student %d:\n",(i+1));
   printf("Enter name:\t");
   scanf("%s",(sp+i)->name);
   printf("\nEnter registration number:\t");
   scanf("%d",&(sp+i)->reg_no);
   for(int j=0;j<3;j++)
   {
    printf("Enter marks in subject %d:\t",(j+1));
    scanf("%d",&(sp+i)->marks[j]);
   }  
  }
}

void display(S* sp,int N)
{
  for(int i=0;i<N;i++)
  {
    printf("Student %d:\n",(i+1));
    printf("Name: %s\nReg_no: %d\nMarks:\n",(sp+i)->name,(sp+i)->reg_no);
    for(int j=0;j<3;j++)
    {
      printf("Subject %d:%d\n",(j+1),(sp+i)->marks[j]);
    }
    printf("\n");
  }
}
void average(S* sp,int N)
{
  printf("\nAverage marks:\n");
  for(int k=0;k<N;k++)
  {
    for(int i=0;i<3;i++)
    {
    int temp;
    for(int j=0;j<3-i-1;j++)
    {
      if((sp+k)->marks[j]>(sp+k)->marks[j+1])
      {
      temp=(sp+k)->marks[j];
      (sp+k)->marks[j]=(sp+k)->marks[j+1];
      (sp+k)->marks[j+1]=temp;
      }
    }
    }
    
    (sp+k)->average_marks=((sp+k)->marks[1]+(sp+k)->marks[2])/2;
    printf("Student %d:%f\n",(k+1),(sp+k)->average_marks);

  }
}

int main()
{
  
  int N,choice;
  printf("Enter number of students\n");
  scanf("%d",&N);
  S *sp=malloc(sizeof(S)*N);

  for(;;)
  {
   printf("1.Read info\n2.Display student info\n3.Calculate average of best two marks of each student\n4.Exit\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:read(sp,N);
           break;
    case 2:display(sp,N);
           break;
    case 3:average(sp,N);
           break;
    case 4:exit(0);
           break;
    default:printf("Invalid choice\n");
   }
  }
}