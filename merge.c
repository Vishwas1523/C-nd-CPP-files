#include <stdio.h>

// Merge two halves L and R into arr
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) L[i] = arr[left + i];
  for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;

  // Merge arrays
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }

  // Copy remaining elements
  while (i < n1) arr[k++] = L[i++];
  while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array:\n");
  printArray(arr, size);

  mergeSort(arr, 0, size - 1);

  printf("Sorted array (Merge Sort):\n");
  printArray(arr, size);

  return 0;
}
//quick
#include <stdio.h>

// Partition function
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array:\n");
  printArray(arr, size);

  quickSort(arr, 0, size - 1);

  printf("Sorted array (Quick Sort):\n");
  printArray(arr, size);

  return 0;
}
//bst
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
  if (root == NULL) return createNode(value);

  if (value < root->data)
    root->left = insert(root->left, value);
  else if (value > root->data)
    root->right = insert(root->right, value);

  return root;
}

// Search in BST
struct Node* search(struct Node* root, int key) {
  if (root == NULL || root->data == key) return root;

  if (key < root->data) return search(root->left, key);

  return search(root->right, key);
}

// Find minimum node (used in deletion)
struct Node* findMin(struct Node* node) {
  while (node->left != NULL) node = node->left;
  return node;
}

// Delete a node in BST
struct Node* deleteNode(struct Node* root, int key) {
  if (root == NULL) return root;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    // Case 1 & 2: No child or one child
    if (root->left == NULL) {
      struct Node* temp = root->right;
      free(root);
      return temp;
    }
    if (root->right == NULL) {
      struct Node* temp = root->left;
      free(root);
      return temp;
    }

    // Case 3: Two children
    struct Node* temp = findMin(root->right);
    root->data = temp->data;  // Copy inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

// Traversals
void inorder(struct Node* root) {
  if (root == NULL) return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(struct Node* root) {
  if (root == NULL) return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct Node* root) {
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

int main() {
  struct Node* root = NULL;

  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder: ");
  inorder(root);
  printf("\n");

  printf("Preorder: ");
  preorder(root);
  printf("\n");

  printf("Postorder: ");
  postorder(root);
  printf("\n");

  printf("\nDeleting 20...\n");
  root = deleteNode(root, 20);

  printf("Inorder after deletion: ");
  inorder(root);
  printf("\n");

  return 0;
}
