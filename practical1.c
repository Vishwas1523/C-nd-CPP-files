#include <stdio.h>
int main(void) {
  printf("Size of Word is %d\n", sizeof(long));

  int matrix[3][3][3][3] = {0};
  unsigned long base = (unsigned long)&matrix;
  printf("Base address: %lu\n", base);

  int di = 3, dj = 3, dk = 3, dl = 3;

  for (int i = 0; i < di; i++) {
    for (int j = 0; j < dj; j++) {
      for (int k = 0; k < dk; k++) {
        for (int l = 0; l < dl; l++) {
          unsigned long addr =
              base +
              (i * dj * dk * dl + j * dk * dl + k * dl + l) * sizeof(int);
          printf("%lu\n", addr);
        }
      }
    }
  }

  return 0;
}
