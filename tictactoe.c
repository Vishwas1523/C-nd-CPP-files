#include <stdio.h>
    char board[3][3];
char current_marker;
int current_player;
void initialize_board();
void print_board();
int check_winner();
int place_marker(int slot);
int main() {
  int slot, winner;
  initialize_board();
  current_marker = 'X';
  current_player = 1;
  for (int i = 0; i < 9; i++) {
    print_board();
    printf("Player %d [%c], enter your move (1-9): ", current_player,
           current_marker);
    scanf("%d", &slot);
    if (place_marker(slot) == -1) {
      printf("Invalid move, try again.\n");
      i--;
      continue;
    }
    winner = check_winner();
    if (winner == 1) {
      print_board();
      printf("Player %d [%c] wins!\n", current_player, current_marker);
      return 0;
    } else if (winner == 2) {
      print_board();
      printf("It's a draw!\n");
      return 0;
    }
    current_player = (current_player == 1) ? 2 : 1;
    current_marker = (current_marker == 'X') ? 'O' : 'X';
  }
  return 0;
}
void initialize_board() {
  char num = '1';
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = num++;
    }
  }
}
void print_board() {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf(" %c ", board[i][j]);
      if (j < 2) printf("|");
    }
    printf("\n");
    if (i < 2) printf("---|---|---\n");
  }
  printf("\n");
}
int place_marker(int slot) {
  int row = (slot - 1) / 3;
  int col = (slot - 1) % 3;

  if (slot < 1 || slot > 9 || board[row][col] == 'X' ||
      board[row][col] == 'O') {
    return -1;
  }
  board[row][col] = current_marker;
  return 0;
}
int check_winner() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
  int moves = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 'X' || board[i][j] == 'O') moves++;
    }
  }
  if (moves == 9) return 2;
  return 0;
}