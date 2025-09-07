#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  int data;
  node *next;
  node(int data1, node *next1) {
    data = data1;
    next = next1;
  }
  node(int data1) {
    data = data1;
    next = nullptr;
  }
};
void printll(node *head) {
  int count = 0;
  node *temp = head; 
  while (temp){
    cout << temp->data << " -> ";
    temp = temp->next;
    count++;
  }
  cout << "NULL\n";
  cout << "Length of the LL is: " << count;
}
node *insertNode(node *head, int val, int pos) {
  if(head == NULL){
    head->data = val;
    head->next = nullptr;
    return head;
  }
  if(pos == 1){
    node *temp = new node(val, head);
    return temp;
  }
  else if(pos >1 && pos <=6){
    node *temp = head;
    for (int i = 1; i < pos; i++) {
      temp = temp->next;
    }
    node *prev = new node(val);
    prev->next = temp->next;
    temp->next = prev;
    return head;
  }
}
int main() {
  int num = 5, sum;
  node *head = new node(10);
  node *temp = head;
  for (int i = 2; i <= num; i++){
    cout<<"Enter the value:\n";
    cin >> sum;
    node *newnode = new node(sum);
    temp->next = newnode;
    temp = temp->next;
  }
  //insertNode(head, 55, 3);
  printll(head);
  return 0;
}