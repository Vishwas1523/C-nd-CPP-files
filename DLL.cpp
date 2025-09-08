#include <iostream>
using namespace std;
class node {
 public:
  int data;
  node *prev, *next;
  node(int data) {
    this->data = data;
    prev = nullptr;
    next = nullptr;
  }
  node(int data, node *prev, node *next) {
    this->data = data;
    this->prev = prev;
    this->next = next;
  }
};
void printDLL(node *head) { 
    node *temp = head; 
    while(temp){
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL";
}
int main() {
  int arr[] = {15, 45, 78, 34, 5, 889};
  node *head = new node(arr[0]);
  node *temp = head;
  for (int i = 1; i < sizeof(arr) / sizeof(int); i++){
    node *wow = new node(arr[i], temp, nullptr);
    temp->next = wow;
    temp = temp->next;
  }
  printDLL(head);
  return 0;
}