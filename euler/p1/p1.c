#include <omp.h>
#include <stdio.h>

#define NUMBER_LIMIT  1000

int main(int argc, char const *argv[])
{
  #pragma omp parallel
  {
    if(omp_get_thread_num()==0) { //master thread
      printf("using %d threads\n", omp_get_num_threads());
    }
  }

  int sum=0, i;
  #pragma omp parallel for shared(sum)
  for(i=0; i<NUMBER_LIMIT; i++) {
    if (i%3==0 || i%5==0) {
      #pragma omp critical
      sum=sum+i;
    }
  }
  printf("sum=%d\n", sum);
  return 0;
}