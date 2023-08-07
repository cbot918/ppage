#include <stdio.h>
#include <stdlib.h>

struct st_node {
  int val;
  struct st_node *parent;
  struct st_node *left, *right;
};

typedef struct st_node Node;

Node* initRoot(int val, Node *left, Node *right){
  Node *self = (Node*)malloc(sizeof(Node));
  self -> val = val;
  self -> left = left;
  self -> right = right;
  return self;
}

Node* createTree(int nums[], int len){
  Node *root = NULL;
  Node *current = NULL;
  for(int i=0; i<len; i++){
    if(i == 0){
      root = initRoot(nums[0], NULL, NULL);
      current = root;
      continue;
    }
    if(nums[1] <= current->val){
      current->left = (Node*)malloc(sizeof(Node));
      current->left->val = nums[1];
      
    } else {
      current->right = (Node*)malloc(sizeof(Node));
      current->right->val = nums[1];
    }
    
    
    return NULL;
    
  }
}

int main(){

  int nums[] = {5,1,3,2,4,7};
  int len = (int)sizeof(nums)/sizeof(nums[0]);

  Node *root = initRoot(5, NULL, NULL);

  printf("%d ", root->val);
  printf("%p ", root->left);
  printf("%p ", root->right);

  return 0;
}