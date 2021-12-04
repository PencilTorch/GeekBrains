#include <stdio.h>
#include <stdlib.h>
#define T char
#define true 1==1
#define false 1!=1
typedef int bool;

typedef struct Node {
	struct Node *pNext;
	T data;
} Node;

typedef struct List {
	Node* head;
	int size;
} List;

void initList(List *list) {
	list->head = NULL;
	list->size = 0;
}

bool push(List *list, T value) {
	Node *temp = (Node*) malloc(sizeof(Node));
	if(temp == NULL)
		return false;
	temp->pNext = list->head;
	temp->data = value;
	list->head = temp;
	list->size++;
	return true;
}

T pop(List *list){
	if(list->size == 0){
		printf("Stack is empty\n");
		return -1;
	}
	Node *temp = list->head;
	T data = list->head->data;
	list->head = list->head->pNext;
	list->size--;
	free(temp);
	return data;
}

void printList(List *list) {
	Node *pCurrent = list->head;
	for(int i = 0; i < list->size; ++i){
		printf("%c ", pCurrent->data);
		pCurrent = pCurrent->pNext;
	}
}

int main() {
    
    List *list = (List*) malloc(sizeof(List));
    initList(list);
    
    char a = getchar();
    while(a != '\n'){
    	push(list, a);
    	a = getchar();
	}
    	
    printList(list);
    
    pop(list);
    printf("\n");
    printList(list);
	
    return 0;
}
