#include <iostream>
using namespace std;

int main() {
#include <iostream>

int main()
{
	const int SIZE = 10;
	int arr[SIZE][SIZE] = { 0 };
	for (size_t i = 0; i < SIZE; i++) {
		for (rsize_t j = 0; j < SIZE; j++) {
			if (i == j) arr[i][j] = 1;
		}
	}
	for (size_t i = 0; i < SIZE; i++) {
		for (rsize_t j = 0; j < SIZE; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

 system("pause");
 return 0;   
}
