#include<stdio.h>

void Toh(int n , char S , char D ,char Aux)
{
  if(n==1)
  {
    printf("Move disk %d from %c to %c\n",n,S,D);
  }
  else{
    Toh((n-1),S,Aux,D);
    printf("Move disk %d from %c to %c\n",n,S,D);
    Toh((n-1),Aux,D,S);
  }
}

void main()
{
  int n;
  printf("Enter number of disks:\n");
  scanf("%d",&n);
  Toh(n,'S','D','M');
}

