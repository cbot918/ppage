#include<stdio.h>
#include<stdlib.h>


struct node {
  int data;
  struct node *next;
};
typedef struct node Node;

Node* newNode(int val){
  Node *current;

  current = (Node*)malloc(sizeof(Node));
  current->data = val;

  return current;
}


struct linkedList {
  struct node *head;
  struct node *current;
  struct node *prev;
  int length;
};
typedef struct linkedList LinkedList;

LinkedList newList(){
  LinkedList ll;
  ll.head = (Node*)malloc(sizeof(Node));
  ll.current = (Node*)malloc(sizeof(Node));
  ll.prev = (Node*)malloc(sizeof(Node));

  ll.head->next = NULL;
  ll.current->next = NULL;
  ll.prev->next = NULL;
  return ll;
}

void getList(char *banner, LinkedList list){

  printf("\n%s(%d)\n", banner, list.length);

  if(list.head == NULL){
    printf("list is empty\n");
    return;
  }
  list.current = list.head;
  while(1){
    printf("%d\n", list.current->data);
    if(list.current->next == NULL) return;
    list.current = list.current->next;
  }
  
}



int main(){
  int data[] = {3,1,56,8,4};
  long unsigned int data_size = sizeof(data)/sizeof(data[0]);
  printf("elements of data: %lu\n", data_size);
  
  LinkedList ll = newList();

  Node *tmp;
  for (int i = 0; i < data_size; i++){
    tmp = newNode(data[i]);
    ll.length += 1;
    // when empty linkedlist
    if (i == 0) {
      ll.head = tmp;
      ll.current = tmp;
      ll.current->next = NULL;
    }
    
    ll.current->next = tmp;
    ll.current = tmp;
    ll.current->next = NULL;

  }

  getList("list: ",ll);
  

}