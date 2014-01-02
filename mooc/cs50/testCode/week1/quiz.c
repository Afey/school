#include <stdio.h>

int main(void) {
  char name[BUFSIZ];
  int ans1;
  printf("What's your name?\n");
  scanf("%s", name);
  printf("Okay, %s, let's get started with our quiz!\n", name);
  printf("What is 2 + 2?\n");
  scanf("%d", &ans1);
  if (ans1 == 4) {
    printf("That's the right answer!\n");
  }
  else {
      printf("Oops, the answer is 4...\n");
  }
  return 0;
}
