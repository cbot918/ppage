#include<stdio.h>
#include<stdlib.h>

struct ListNode{
  int val;
  struct ListNode *next;
};

typedef struct ListNode Node;

Node* createList(int nums[], int len){

  Node* head = NULL;
  Node* current = NULL;
  Node* nextNode = NULL;

  for(int i=0; i<len; i++){
    if (i == 0){
      head = (Node*)malloc(sizeof(Node));
      head->val = nums[i];
      head->next = NULL;
      continue;
    } 
    if (i == 1){
      current = (Node*)malloc(sizeof(Node));
      current -> val = nums[i];
      current -> next =NULL;
      head -> next = current;
      continue;
    }
    nextNode = (Node*)malloc(sizeof(Node));
    nextNode -> val = nums[i];
    current -> next = nextNode;
    current = current -> next;
  }
  return head;
}

void printList(Node* head){
  Node* current = head;
  while(current!=NULL){
    printf("%d-> ", current->val);
    current = current->next;
  }
  printf("%p\n", current);
}

Node* reverseList(Node* head){
  Node* c = head;

  // parse list val to array
  int nums[20] = {0};
  int count = 0;
  while(c!=NULL){
    nums[count] = c->val;
    c = c->next;
    count += 1;
  }
  
  // reverse array
  int edge = 0;
  if(count%2 ==0){
    edge = count/2;
  } else {
    edge = count/2+1;
  }
  int temp = 0;
  for(int i=0;i<edge; i++){
    temp = nums[i];
    nums[i] = nums[count-i-1];
    nums[count-i-1] = temp;
  }


  Node* newHead = NULL;
  Node* current = NULL;
  Node* nextNode = NULL;
  for (int i=0; i<count; i++){
    if(i == 0){
      newHead = (Node*)malloc(sizeof(Node));
      newHead->val = nums[i];
      newHead->next = NULL;
      continue;
    }
    if(i == 1){
      current = (Node*)malloc(sizeof(Node));
      current->val = nums[i];
      current->next = NULL;
      newHead->next = current;
      continue;
    }
    nextNode = (Node*)malloc(sizeof(Node));
    nextNode->val = nums[i];
    nextNode->next = NULL;
    current->next = nextNode;
    current = current -> next;
  }  

  return newHead;
}

int main(){
  int nums[] = {1,2,3,4,5};
  int len = (int)sizeof(nums)/(int)sizeof(nums[0]);

  Node* head = NULL;
  
  head = createList(nums, len);
  printList(head);
  
  head = reverseList(head);
  printList(head);
}