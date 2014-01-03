/*
(c) Krish Dholakiya.

Licensed under MIT License. 

Plagiarism is violation of license
*/

#include <stdio.h>

int main(void) {
  int n;
  do {
    printf("What should the height of the pyramid be?");
    scanf("%i", &n);
    //  printf("%d", n);
  }
  while (n > 23 || n < 0);
  for (int i = 0; i < n; i++) {
    for(int x = 0; x < n-i-1; x++) {
      printf("%s", " ");
    }
    for(int h = 0; h < i + 2; h++){
      printf("#");
    }
    printf("\n");
  }
  return 0;
}
