#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL");
}

void push(struct Node** head, int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

int main(){
  
  int keys[] = {1, 2, 2, 2, 3, 4, 4, 5};
  int length = sizeof(keys)/sizeof(keys[0]);
  
  struct Node* head = NULL;
  
  for (int i=0; i<length; i++){
    push(&head, keys[i]);  
  }
  
  // printf("%d", head->data);
  printList(head);

  return 0;
}