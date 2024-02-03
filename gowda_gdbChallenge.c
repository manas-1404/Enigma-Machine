#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int min, int max);

int main(int argc, char** argv) {
  srand(time(NULL)); // Seed the random number generator with the current time

  int i;
  for (i = 1; i <= 100; i++) {
    int value = randint(0, 999999);
    printf("%6d ", value);
    if (i % 20 == 0)
      printf("\n");
  }
  printf("\n");
  return 0;
}

int randint(int min, int max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
