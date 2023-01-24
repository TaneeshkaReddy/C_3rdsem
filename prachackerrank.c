#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c)
 {
  //Write your code here.
  int sum=0;
  int d,e,f;
  d=a;
  e=b;
  f=c;
  for(int i=1;i<=n;i++)
  {
      if(i==1){
          sum=a;}
      else if(i==2){
            sum=b;}
        
      else if(i==3){
            sum=c;}
      else if(sum==n){
          return(sum);}
      else{
          sum=d+e+f;
          f=sum;
          e=d;
          d=e;}
  }
 }


int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}

