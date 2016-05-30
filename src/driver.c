#include<stdio.h>
#include<stdlib.h>

int mymain (int argc, char** argv);
int main (int argc, char** argv){
  printf("Calling main function.\n");
  int r = mymain(argc, argv);
  printf("Result is %d.\n", r);
  return r;
}
