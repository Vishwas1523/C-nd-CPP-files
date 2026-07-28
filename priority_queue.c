#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  int data[MAX];
  int size;
} PriorityQueue;

void init(PriorityQueue* pq) { pq->size = 0; }
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void insert(PriorityQueue* pq, int value) {
  if (pq->size >= MAX) {
    printf("Priority Queue is full!\n");
    return;}

  int i = pq->size;
  pq->data[i] = value;
  pq->size++;
  while (i != 0 && pq->data[(i - 1) / 2] < pq->data[i]) {
    swap(&pq->data[i], &pq->data[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}
void display(PriorityQueue* pq) {
  printf("Priority Queue: ");
  for (int i = 0; i < pq->size; i++) {
    printf("%d ", pq->data[i]);
  }
  printf("\n");
}
int main() {
  PriorityQueue pq;
  init(&pq);
  insert(&pq, 10);
  insert(&pq, 30);
  insert(&pq, 20);
  insert(&pq, 5);

  display(&pq);

  insert(&pq, 50);
  display(&pq);

  return 0;}