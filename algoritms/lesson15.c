//
#include <stdio.h>
#include <stdlib.h>
#define T char

typedef struct Node {
	struct Node *pNext;
	T data;
} Node;
//lesson 15
typedef struct List {
	Node *head;
	int size;
} List;

void initList(List *list) {
	list->head = NULL;
	list->size = 0;
}

void push_back(List *list, T data) {
	if(list->head == NULL){
		Node *temp = (Node*) malloc(sizeof(Node));
		temp->pNext = NULL;
		temp->data = data;
		list->head = temp;
	}
	else {
		Node *current = list->head;
		while(current->pNext != NULL){
			current = current->pNext;
		}
		current->pNext = (Node*) malloc(sizeof(Node));
		current->pNext->data = data;
		current->pNext->pNext = NULL;
	}
	list->size++;
}

// task 1
void sumCode(List *list){
	Node *temp = list->head;
	int sum = 0;
	while(temp != NULL){
		sum += (int)temp->data;
		temp = temp->pNext;
	}
	printf("\nsum code chars = %d \n", sum);
}

//task 2
void countMoney(int num){
	int arrMoneys[5] = {50,10,5,2,1};
	int arrCountMoneys[5] = {0};
	for(int i = 0, t = 0; num > 0; ++i){
		int t = num/arrMoneys[i];
		if(t > 0){
			arrCountMoneys[i] = t;
		}
		num = num % arrMoneys[i];
	}
	printf("\nUsed %d money by %d, %d money by %d, %d money by %d, %d money by %d, %d money by %d \n",
			arrCountMoneys[0], arrMoneys[0], arrCountMoneys[1], arrMoneys[1], 
			arrCountMoneys[2], arrMoneys[2], arrCountMoneys[3], arrMoneys[3], arrCountMoneys[4], arrMoneys[4]);
}

int main() {
    
   List *os = (List*) malloc(sizeof(List));
   initList(os);
   T c = getchar();
    while(c != '\n'){
    	push_back(os, c);
    	c = getchar();
	}
   
   sumCode(os);
   
   countMoney(48);
	
    return 0;
}
