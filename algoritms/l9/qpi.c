#include <stdio.h>
#include <stdlib.h>

#define SZ 10

typedef struct {
	int pr;
	int dat;
} Node;

Node* arr[SZ];
int tail;
int items;

void init() {
	for(int i = 0; i < SZ; ++i){
		arr[i] = NULL;
	}
	tail = 0;
	items = 0;
}

void ins(int pr, int dat) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;

	if(items == SZ){
		printf("%s \n", "Queue is full");
		return;
	}
	else {
		if(tail == SZ){
			for(int i = 0; i < SZ; ++i){
				if(arr[i] == NULL){
					arr[i] = node;
					items++;
					break;
				}
			}
		}
		else{
			arr[tail++] = node;
			items++;
		}
	}
}

Node* rem() {
	if(items == 0)
		return NULL;
	else {
		int i = 0;
		int flag = 0;
		int idx = SZ;
		while(i < SZ){
			if(arr[i] != NULL && arr[i]->pr < idx){
				idx = arr[i]->pr;
				flag = i;
			}
			i++;
		}
		Node* tmp = arr[flag];
		arr[flag] = NULL;
		items--;
		return tmp;
	}
}

void printQueue() {
	printf("[ ");
	for(int i = 0; i < SZ; ++i){
		if(arr[i] == NULL)
			printf("[*, *] ");
		else
			printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
	}
	printf(" ]");
}


int main() {
    init();
	ins(1, 11);
	ins(3, 22);
	ins(4, 33);
	ins(2, 44);
	ins(3, 55);
	ins(4, 66);
	ins(5, 77);
	ins(1, 88);
	ins(2, 99);
	ins(6, 100);
	printQueue();
	printf("\n");
		for(int i = 0; i < 7; ++i){
		Node* n = rem();
		printf("pr=%d, dat=%d \n", n->pr, n->dat);
	}
	printQueue();
	printf("\n");
	ins(1, 110);
	ins(3, 120);
	ins(6, 130);
	printf("\n");
	printQueue();
	
	
    return 0;
}
