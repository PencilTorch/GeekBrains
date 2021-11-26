#include <stdio.h>

//for 4
const int sizeX = 15;
const int sizeY = 15;

// 1 decimal to binary
void decToBin(int n) {
	if (n > 0) {
		decToBin(n/2);
		printf("%d", n%2);
	}
}

// 2 rec pow simple
int RecPowL(int a, int b) {
    return b == 1 ? a : a * RecPowL(a, b - 1);
}

// 3 rec pow hard
int RecPowH(int a, int b) {
	if (b%2 == 0) {
		a = a * a;
		b = b / 2;
		return RecPowL(a, b);
	}
	else {
		int temp = RecPowL(a, b);
		a = temp * a;
		b = b - 1;
		return RecPowL(a, b);
	}
}

// 4 count routes of king
int routes(int x, int y, int arrB[sizeX][sizeY]) {
	if(x == 0 && y == 0) 
		return 0;
	else if(x == 0 || y == 0) 
		return 1;
	else if(arrB[x][y] == 1)
		return 1;
	else 
		return routes(x, y - 1, arrB) + routes(x - 1, y, arrB);
}

int main() {
    /*
    // 1
    int N;
    scanf("%d", &N);
 	decToBin(N);
 	*/
 	
 	/*
 	// 2
 	printf("%d", RecPowL(5,5));
 	*/
 	
 	/*
 	// 3
 	printf("%d", RecPowH(2,3));
 	*/
 	
 	// 4
 	int arrBarrier[sizeX][sizeY];
 	// fill array of barrier
	 for(int y = 0; y < sizeY; ++y) {
 		for(int x = 0; x < sizeX; ++x) {
 			arrBarrier[x][y] = rand()%2;
		 }
	 }
 	// print array of barrey
 	for(int y = 0; y < sizeY; ++y) {
 		for(int x = 0; x < sizeX; ++x) {
 			printf("%5d", arrBarrier[x][y]);
		 }
		 printf("\n");
	 }
	 printf("\n");
 	// print routes of king
 	for(int y = 0; y < sizeY; ++y) {
 		for(int x = 0; x < sizeX; ++x) {
 			printf("%5d", routes(x, y, arrBarrier));
		 }
		 printf("\n");
	 }
 	
    return 0;
}