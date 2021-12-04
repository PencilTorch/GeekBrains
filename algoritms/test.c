#include <stdio.h>
#include <stdlib.h>

//создание одномерного массива размером с двумерный
int* onedimArr(int* arr, int size) {
    arr = (int*)calloc(sizeof(int), size);
    return arr;
}
//заполнение двумерного массива рандомно
void fillArray(int** arr, int col, int row, int border) {
	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col; ++j) {
			*((*(arr + i)) + j) = rand() % border;
		}
	}
}
//копирование двумерного массива в одномерный
void fillodArray(int** arr, int col, int row, int* odArr, int size) {
    int m = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j, ++m){
            odArr[m] = arr[i][j];
        }
    }
}
//печать двумерного массива
void printArray(int** arr, int col, int row) {
	printf("Print twodimensional array:\n");
    for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col; ++j) {
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
}
//печать одномерного массива
void printodArray(int* odArr, int size, int col) {
    printf("Print onedimensional array:\n");
    for(int i = 0; i < size; ++i){
        printf("%4d", odArr[i]);
        if((i+1)%col == 0) printf("\n");
    }
    printf("\n");
}
//сортировка одномерного массива пузырьком
void bubleSort(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main() {
    int row = 5;
    int col = 5;
    int size = row * col;

    int* odArr = onedimArr(odArr, size);
	
	int** arr = calloc(sizeof(int*), row);
	for(int i = 0; i < row; ++i) {
		arr[i] = (int*)calloc(sizeof(int), col);
	}
	
	fillArray(arr, col, row, 100); //рандомное заполнение двумерного массива
    fillodArray(arr, col, row, odArr, size); //копирование двумерного массива в одномерный
	printArray(arr, col, row); //печать двумерного массива
    bubleSort(odArr, size); //сортировка одномерного массива
    printodArray(odArr, size, col); //печать одномерного массива, как двумерного

	
	for(int i = 0; i < row; ++i) {
		free(arr[i]);
	}
	free(arr);
    free(odArr);

	return 0;
}