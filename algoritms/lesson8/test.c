#include <stdio.h>

#define T char
#define SIZE 1000
#define true 1==1
#define false 1!=1
typedef int boolean;

int cursor = -1;
T Stack[SIZE];

boolean push(T data) {
	if(cursor < SIZE){
		Stack[++cursor] = data;
		return true;
	}
	else{
		printf("%s \n", "Stack overflow");
		return false;
	}
}

T pop() {
	if(cursor != -1){
		return Stack[cursor--];
	}
	else{
		printf("%s \n", "Stack is empty");
		return -1;
	}
}

int main() {
    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    push('f');
    while(cursor != -1){
    	printf("%c ", pop());
	}
	pop();
	
    return 0;
}