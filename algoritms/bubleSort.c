#include <stdio.h>
#include <stdlib.h>

//функция рандомного заполнения массива
void fillArray(int** arr, int col, int row, int border) {
	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col; ++j) {
			*((*(arr + i)) + j) = rand() % border;
		}
	}
}
//печать массива
void printArray(int** arr, int col, int row) {
	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col; ++j) {
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
}
//сортировка пузырьком
void bubleSort(int** arr, int col, int row) {
	for(int k = 0; k < (row*col-1); ++k) {
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(i == row-1 && j == col-1) 
					continue;
				if(j == col-1 && arr[i][j] > arr[i+1][0]) {
					int t = arr[i][j];
					arr[i][j] = arr[i+1][0];
					arr[i+1][0] = t;
				}
				if(j != col-1 && arr[i][j] > arr[i][j+1]) {
					int t = arr[i][j];
					arr[i][j] = arr[i][j+1];
					arr[i][j+1] = t;
				}
			}
		}
	}
}

int main() {
	int row = 5, col = 5; //размерность массива

	//создание динамического двумерного массива
	int** arr = calloc(sizeof(int*), row);
	for(int i = 0; i < row; ++i) {
		arr[i] = (int*)calloc(sizeof(int), col);
	}
	
	fillArray(arr, col, row, 100);
	printArray(arr, col, row);
	bubleSort(arr, col, row);
	printf("\n Sortet array: \n");
	printArray(arr, col, row);
	
	//освобождение памяти
	for(int i = 0; i < row; ++i) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}