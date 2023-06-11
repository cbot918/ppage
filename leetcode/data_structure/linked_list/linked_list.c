#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};
typedef struct node Node;



int main(){
	int i, val, num;
	Node *first, *current, *previous;
	printf("Number of nodes: ");

	scanf("%d", &num);

	for (i=0; i<num; i++){
		current = (Node*)malloc(sizeof(Node));
		printf("Data for node %d: ",i+1);
		scanf("%d", &(current->data));
		if (i==0){
			first=current;
			previous=current;
		} else {
			previous -> next = current;
			current -> next = NULL;
			previous = current;
		}
	}
	current = first;
	while(current != NULL){
		printf("address=%p,", current);
		printf("data=%d,", current->data);
		printf("next=%p,\n", current -> next);
		current=current->next;
	}
	return 0;

}
