#include <stdio.h>

int main(void) {
  printf("hello world\n");

  char str1[20], str2[30];
  
  printf("Enter name: ");
  scanf("%s", str1);

  printf("Enter your website name: ");
  scanf("%s", str2);

  printf("Entered Name: %s\n", str1);
  printf("Entered Website:%s\n", str2);
  
  return(0);

  // true false not defined?
  while (true) {
    printf("hello, world\n");
  }

  for (int i = 0; i < 50; i++) {
    printf("hello world\n");
  }

  int i = 0;

  i < 50;

  if (x < y) {

  } else if (x > y) {

  } else {

  }

  argv[0];

  clang x
  ./x.out
  ---------------------------------
  clang -o outputfile x
  ./outputfile
  ---------------------------------
  make x
  ./x

  %d - int (same as %i)
  %ld - long int (same as %li)
  %f - float
  %lf - double[1]
  %c - char
  %s - string
  %x - hexadecimal

}