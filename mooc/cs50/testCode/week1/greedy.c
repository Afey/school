#include <stdio.h>

int main(void) {
  float changeOwed;
  int coinCount = 0;
  int cents;
  int round(double number) {
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
  };
  do {
    printf("How much change is owed?\n");
    scanf("%f", &changeOwed);
  }
  while (changeOwed < 0);
  cents = round(changeOwed * 100);
  while (cents >= 25) {
    coinCount++;
    cents -= 25;
  };
  while (cents >= 10 && cents < 25) {
    coinCount++;
    cents -= 10;
  };
  while (cents >= 5 && cents < 10) {
    coinCount++;
    cents -= 5;
  };
  while (cents >= 1 && cents < 5) {
    coinCount++;
    cents -= 1;
  };
  if (cents == 0) {
    printf("%i\n", coinCount);
  };
  return 0;
}
