#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} node;

node* insertHead(node* head, int x) {
  node* newNode = malloc(sizeof(node));
  newNode->data = x;
  newNode->next = head;
  return newNode;
}

node* insertTail(node* head, int x) {
  node* newNode = malloc(sizeof(node));
  newNode->data = x;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

void display(node* head) {
  node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  node* head = NULL;

  head = insertHead(head, 5);
  head = insertTail(head, 10);
  head = insertTail(head, 20);
  head = insertHead(head, 1);

  display(head);

  return 0;
}
