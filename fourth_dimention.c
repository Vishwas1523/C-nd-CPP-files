#include <stdio.h>

int main() {
  int A[2][3][2];  // 3-dimensional array (can be extended to 4D)
  int baseAddress = (int)&A[0][0][0];  // Base address of the array
  int i, j, k;

  printf("Base Address of A[0][0][0] = %u\n", (unsigned)&A[0][0][0]);
  printf("Each element occupies %lu bytes\n\n", sizeof(A[0][0][0]));

  // Display addresses of all elements
  printf("Array elements and their addresses:\n");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 2; k++) {
        printf("Address of A[%d][%d][%d] = %u\n", i, j, k,
               (unsigned)&A[i][j][k]);
      }
    }
  }

  // Theoretical Address Calculation (Row-major formula)
  // Address(A[i][j][k]) = Base + [ (i * (Y*Z)) + (j * Z) + k ] * size
  int Y = 3, Z = 2;
  i = 1;
  j = 2;
  k = 1;  // Choose any element
  int elementSize = sizeof(A[0][0][0]);
  int theoreticalAddress =
      baseAddress + (((i * Y * Z) + (j * Z) + k) * elementSize);

  printf("\nCalculated theoretical address of A[%d][%d][%d] = %u\n", i, j, k,
         theoreticalAddress);
  printf("Actual address from program = %u\n", (unsigned)&A[i][j][k]);

  if (theoreticalAddress == (unsigned)&A[i][j][k])
    printf(" Verified: Theoretical and actual addresses match.\n");
  else
    printf(" Mismatch: Check your formula or dimensions.\n");

  return 0;
}ww