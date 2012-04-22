#include <stdio.h>

int lastFib=2, beforeLastFib=1;

int main(int argc, char const *argv[])
{
  int fib, sum=lastFib+beforeLastFib-1;
  do {
    fib=lastFib+beforeLastFib;
    printf("fib=%d\n",fib);
    if(fib%2==0){
      sum+=fib;
    }
    beforeLastFib=lastFib;
    lastFib=fib;
  } while(fib<4000000);
  printf("\n\nsum=%d",sum);
  return 0;
}