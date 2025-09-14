#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    int
    main() {
  int a, i, j = 0, k = 0, m = 1, f;
  char arr[100];
  srand(time(NULL));
  int comp;
  printf("Welcome to stone, paper and sissors :)\n");
  printf("Please enter your name:\n");
  scanf("%s", arr);
  printf("\nHello %s!\n", arr);
  printf("_____________________________________________________________\n");
  printf(
      "\nHere are the instructions of the game:\n1)Choose 0 for "
      "Scissors\n2)Choose 1 for Paper\n3)Choose 2 for Stone\n4)There will be "
      "three rounds\n5)Player who scores more points will be the winner\n");
  printf("_____________________________________________________________\n");
  for (m = 1;; m++) {
    j = 0;
    k = 0;
    for (i = 0; i < 3; i++) {
      int comp = rand() % 3;
      printf("\nYour turn (Choose either 0, 1 or 2):\n");
      scanf("%d", &a);
      printf("Computer chooses:\n%d\n", comp);
      if (a == comp) {
        printf("DRAWWWWW!!!!\n");
        printf("0 points to both of you!\n");
      } else if (a == 1 && comp == 0 || a == 2 && comp == 1 ||
                 a == 0 && comp == 2) {
        printf("Computerrrrrrrr wonnnnnn!!!!!!!\n");
        printf("1 point to computer!\n");
        j++;
      } else if (a == 2 && comp == 0 || a == 0 && comp == 1 ||
                 a == 1 && comp == 2) {
        printf("%s wonnnnnnnnnnn!!!!!!!\n", arr);
        printf("1 point to %s!\n", arr);
        k++;
      } else if (a > 2) {
        printf("Abbe gawar!!\nypu've to choose either 0 or 1 or 2!!!\n");
      }
      printf("Computer has %d points\n%s has %d points!\n", j, arr, k);
    }
    if (j > k) {
      printf("Computer won against %s\n", arr);
    } else if (k > j) {
      printf("%s won against computer\n", arr);
    } else if (k == j) {
      printf("Match drawwww!!!\n");
    }
    printf("\nDo you want to play again?\nClick '1' for YES and '2' for NO\n");
    scanf("%d", &f);
    if (f == 1) {
      continue;
    } else if (f == 2) {
      printf("Thankyou for playing\n");
      break;
    } else if (f > 2) {
      printf("Byeeeee\n");
      break;
    }
  }

  return 0;
}