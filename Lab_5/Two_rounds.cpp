#include <iostream>
#include <string>
#include <cmath>
int MINN = 1;
int MAXX = 200000;
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
};

struct Node* newNode(int x) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = x;
  temp->left = temp->right = temp->parent = NULL;
  return temp;
}

struct Node* add_elem(struct Node* root, int key) {

  if (root == NULL) {
    return newNode(key);
  }
  if (key < root->data) {
    Node* left_next = add_elem(root->left, key);
    root->left = left_next;
      left_next->parent = root;
  }
  else {
    Node* right_next = add_elem(root->right, key);
    root->right = right_next;
      right_next->parent = root;
  }
  return root;
}

struct Node* recover(int a[], int* ind, int key, int minn, int maxx, int len_mas)
{
    struct Node* root = NULL;
    if (*ind >= len_mas) {
        return NULL;
    }

    if (key >= minn && key <= maxx) {
        root = add_elem(root,key);
        *ind = *ind + 1;

        if (*ind < len_mas) {
            root->left = recover(a, ind, a[*ind], minn, key, len_mas);
        }
        if (*ind < len_mas) {
            root->right = recover(a, ind, a[*ind], key, maxx, len_mas);
        }
    }

    return root;
}

void PostOrder(struct Node* root){
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data<<" ";
    }
}
    
int main() {
    int num;
    cin >> num;
    int* mas = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> mas[i];
    }
    int ind = 0;
    Node* root = recover(mas, &ind, mas[0], MINN, MAXX, num);

    PostOrder(root);
}
