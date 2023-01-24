#include <stdio.h>
#include <stdlib.h>
int N,size;

struct student
{
  int regno;
  char name[10];
  int marks[3];
  float average;
};

void read(struct student *);
void disp(struct student *);
void average(struct student *);

int main()
{
  struct student *sp;
  int choice;

  printf("Enter the size\n");
  scanf("%d", &size);

  sp = (struct student*)malloc(size * sizeof(struct student));

  
  for (;;)
  {
    printf("Enter your choice 1.READ 2.DISPLAY 3.AVERAGE\n");
  scanf("%d", &choice);

    switch(choice)
    {
    case 1:
            read(sp);
            break;
    case 2: 
           disp(sp);
           break;
    case 3:
           average(sp);
           break;
    default:
           printf("inavlid choice");
           free(sp); sp=NULL;
           exit(0);
    }
  }
}

void read(struct student *sp)
{
  int i, j;
  
  printf("Enter the number of students\n");
  scanf("%d", &N);

  if (N>size)
  {
    printf("insufficient memory\n");
     printf("Creating space by allocating memory\n");
     sp=(struct student*)realloc(sp,N*2);
    }

  
    for (i = 0; i < N; i++)
    {
      printf("Enter name and regno of student%d\n", (i + 1));
      scanf("%s%d", (sp + i)->name, &(sp + i)->regno);

      for (j = 0; j < 3; j++)
      {
        printf("Enter subject%d marks on 100: \n", (j + 1));
        scanf("%d", &(sp + i)->marks[j]);
      }
      
    }
  
}

void disp(struct student *sp)
{
  int i, j;
  for (i = 0; i < N; i++)
  {
    printf("Student%d info:\n", (i + 1));
    printf("Name : %s\n Registration No. : %d\n", (sp + i)->name, (sp + i)->regno);

    for (j = 0; j < 3; j++)
    {
      printf("Subject %d marks: %d\n", (i + 1), (sp + i)->marks[j]);
    }
    printf("\n\n");
  }
}

void average(struct student *sp)
{
  int i, j, temp, k;
  for(i = 0; i < N; i++)
  {
    for(j = 0; j < 2; j++)
    {
      for(k = 0; k < (3 - j - 1); k++)
        
        {
          if ((sp + i)->marks[k] > (sp + i)->marks[k + 1])
          {
            temp = (sp + i)->marks[k];
            (sp + i)->marks[k] = (sp + i)->marks[k + 1];
            (sp + i)->marks[k + 1] = temp;
          }
        }
    }
  }

    printf("Average of best two scores of Students:\n");
    for (i = 0; i < N; i++)
    {
      float avg = 0.0;
      avg = ((sp + i)->marks[0] + (sp + i)->marks[1]) / 2;
      printf("Student %d is : %f\n", (i + 1), avg);
    }
  }
