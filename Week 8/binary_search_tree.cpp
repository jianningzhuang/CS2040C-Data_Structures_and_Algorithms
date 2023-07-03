#include <bits/stdc++.h>
using namespace std;

struct Vertex{
  Vertex* parent;
  Vertex* left;
  Vertex* right;
  int key;
  int depth;
};

class BST{
protected:
  Vertex* root;

public:
  BST(){
    root = NULL;
  }

  int insert(int v){
    if (root == NULL){
      Vertex* T = new Vertex;
      T->key = v;
      T->parent = NULL;
      T->left = NULL;
      T->right = NULL;
      T->depth = 0;
      root = T;
      return 0;
    }
    Vertex* cur = root;
    Vertex* par = NULL;
    while (cur != NULL){
      if (cur->key < v){
        par = cur;
        cur = cur->right;
        if (cur == NULL){
          Vertex* T = new Vertex;
          T->key = v;
          T->parent = par;
          T->left = NULL;
          T->right = NULL;
          T->depth = par->depth + 1;
          cur = T;
          par->right = cur;
          return T->depth;
        }
      }
      else{
        par = cur;
        cur = cur->left;
        if (cur == NULL){
          Vertex* T = new Vertex;
          T->key = v;
          T->parent = par;
          T->left = NULL;
          T->right = NULL;
          T->depth = par->depth + 1;
          cur = T;
          par->left = cur;
          return T->depth;
        }
      }
    }
    return 0;
  }
};

int main(){
  // int n;
  // cin >> n;
  BST* T = new BST();
  int counter = 0;
  for (int i = 0; i < 200; i++){
    // int temp;
    // cin >> temp;
    counter += T->insert(i);
    // cout << counter << endl;
  }
  cout << counter << endl;
}
