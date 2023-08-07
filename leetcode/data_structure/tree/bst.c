#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  int val;
  struct node *left;
  struct node *right;
};

typedef struct node Node;

Node *root, *ptr = NULL;

// DFS
void inorder(Node* current){
  if(current != NULL){
    inorder(current->left);
    printf("%d ",current->val);
    inorder(current->right);
  }    
}
void preorder(Node* current){
  if(current != NULL){
    printf("%d ",current->val);
    preorder(current->left);
    preorder(current->right);
  }
}
void postorder(Node* current){
  if(current != NULL){
    postorder(current->left);
    postorder(current->right);
    printf("%d ",current->val);
  }
}

// LevelOrder
int height(Node* current);
void printCurrentLevel(Node *current,int level);

void LevelOrder(Node* root){
  int h = height(root);
  for(int i=0; i<=h; i++){
    printCurrentLevel(root, i);
  } 
}
void printNode(Node *current){
  if(current == NULL){
    printf("%p ", current);
    return;
  }
  printf("%d ", current->val);
}
void printCurrentLevel(Node *current,int level){
  if(level == 0)
    return;
  if(level == 1)
    // printf("%d ", current->val);
    printNode(current);
  if(level > 1){
    printCurrentLevel(current->left, level-1);
    printCurrentLevel(current->right, level-1);
  }
}
int height(Node* current){
  if(current == NULL)
    return 0;
  else {
    int lheight = height(current->left);
    int rheight = height(current->right);

    if (lheight > rheight)
      return (lheight + 1);
    else
      return (rheight + 1);
  }
}

int main(){
  // data array
  int data[] = {8,5,1,7,10,12};
  // int data[] = {5,1,3,2,4,7};
  int data_len = (int)sizeof(data)/sizeof(data[0]);

  Node *prev, *current = NULL;

  for (int i=0; i< data_len; i++){
    // 先把資料建一個 node
    ptr = (Node*)malloc(sizeof(Node));
    ptr->val = data[i]; ptr->left = NULL; ptr->right = NULL;
    
    if (root == NULL){
      root = ptr;
    } else {
      current = root;
      while(current!=NULL){
        prev = current;
        if(ptr->val < current->val)
          current = current -> left;
        else
          current = current -> right;
      }
      if(ptr->val < prev->val)
        prev->left = ptr;
      else
        prev->right = ptr;
    }
  }

  // 排序: inorder traverse
  printf("inroder 排序:\n");
  inorder(root);

  printf("\npreorder: \n");
  preorder(root);

  printf("\npostorder: \n");
  postorder(root);

  printf("\n\nheight: \n");
  printf("%d \n",height(root));

  printf("BFS: \n");
  LevelOrder(root);
}