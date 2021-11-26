#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

void fillArr(int* arr, int size) {
	for(int i = 0; i < size; ++i){
		arr[i] = rand() % 100;
	}
}

void printArr(int* arr, int size) {
	for(int i = 0; i < size; ++i)
        printf("%4d", arr[i]);
}

void swapInt(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//sorting by inserts
void sortInserts(int* arr, int size) {
	int temp, pos;
	for(int i = 1; i < size; ++i){
		temp = arr[i];
		pos = i - 1;
		while(pos >= 0 && arr[pos] > temp){
			arr[pos + 1] = arr[pos];
			--pos;
		}
		arr[pos + 1] = temp;
	}
}

//update quick sorting
void uqs(int* arr, int first, int last) {
	if(last-first < 10) {
		sortInserts(arr, last+1);
	}
	else {
		int mp1 = first;
		int mp2 = (first+last)/2;
		int mp3 = last;
		int a = arr[mp1];
		int b = arr[mp2];
		int c = arr[mp3];
		int mp;
		if (a > b) {
    		if (c > a) mp = mp1;
    		mp = (b > c) ? mp2 : mp3;
 		}
  		else if (c > b) mp = mp2;
 		else if (a > c) mp = mp1;
		else mp = mp3;
		int m = (first+last)/2;
		if(arr[m] != arr[mp])
			swapInt(&arr[m], &arr[mp]);
		int i = first;
		int j = last;
		int x = arr[(first+last)/2];
		do{
			while(arr[i] < x) i++;
			while(arr[j] > x) j--;
			if(i <= j) {
				swapInt(&arr[i], &arr[j]);
				i++;
				j--;
			}
		} while(i <= j);
		if(i < last) uqs(arr, i, last);
		if(j > first) uqs(arr, first, j);
	}
}

//update bucket sorting
void bucketSort(int* arr, int size) {
	const int max = size;
	const int b = 10;
	int buckets[b][max+1];
	for(int i = 0; i < b; ++i){
		buckets[i][max] = 0;
	}
	for(int digit = 1; digit < 1000; digit*=10){
		for(int i = 0; i < max; ++i){
			if(arr[i]%2 == 0){
			int d = (arr[i]/digit)%b;
			int counter = buckets[d][max];
			buckets[d][counter] = arr[i];	
			counter++;
			buckets[d][max] = counter;
			}
		}
		int idx = 0;
		for(int i = 0; i < b; ++i){
			for(int j = 0; j < buckets[i][max]; ++j, ++idx){
				if(arr[idx]%2 == 0){
					arr[idx] = buckets[i][j];
				}
				else {
					--j;
				}	
			}
			buckets[i][max] = 0;
		}
	}
}

int main() {
	
int arr[SIZE];
fillArr(arr, SIZE);
printArr(arr, SIZE);

//task 1
uqs(arr, 0, SIZE-1);

//task 2
//bucketSort(arr, SIZE);

printf("\n");
printArr(arr, SIZE);


return 0;
}
