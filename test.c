#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *one_char = malloc(sizeof(char));
  int *two_char = malloc(sizeof(char)*2);

  *(one_char + 0) = 'a'; // same as *one_char = 'a';

  *(two_char + 0) = 'b'; // same as two_char = 'b';

  *(two_char+1) = 'c';

  printf("%c, %c, %c\n", *one_char, *two_char, *(two_char+1));

  return 0;
}