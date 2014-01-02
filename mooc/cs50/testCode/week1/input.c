#include <stdio.h>

int main(void) {
  char username[BUFSIZ];
  printf("Your name please.\n");
  scanf("%s", username);
  printf("Hey, %s\n", username);
}
