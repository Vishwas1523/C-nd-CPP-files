#include <stdio.h>
void printNumbers(int *arr, int n);

    int main() { 
     int prr[] = {1, 2, 3, 4, 5, 6};
     printNumbers(prr, 6);
     return 0;
   }

   void printNumbers(int *arr, int n) {
      int i;
      for ( i = 0; i < n; i++) {
         printf("%d\t", arr[i]);
        }
       printf("\n");
    }
