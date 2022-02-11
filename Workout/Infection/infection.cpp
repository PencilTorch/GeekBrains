#include <iostream>
#include <Windows.h> //для цветов
#include <cstdlib> //для рандома
#include <ctime>

//дескриптор окна для изменения цвета текста
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Печать массива
void printArr(int** const arr, const int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[i][j] == 9) {
                SetConsoleTextAttribute(hConsole, 12); //цвет текста светло-красный
                std::cout << arr[i][j] << "  ";
            }
            else if (arr[i][j] < 9 && arr[i][j] > 4) {
                SetConsoleTextAttribute(hConsole, 4); //цыет текста красный
                std::cout << arr[i][j] << "  ";
            }
            else if (arr[i][j] <= 4 && arr[i][j] > 0) {
                SetConsoleTextAttribute(hConsole, 14); //желтый
                std::cout << arr[i][j] << "  ";
            }
            else {
                SetConsoleTextAttribute(hConsole, 2); //зеленый
                std::cout << arr[i][j] << "  ";
            }
        }
        std::cout << "\n";
    }
    SetConsoleTextAttribute(hConsole, 15); //возвращаем белый цвет
}

//Заполняем массив нулями - нет инфекции
void fillArr(int** arr, const int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            arr[i][j] = 0;
        }
    }
}

void arrCopy(int** arrFirst, int** const arrSecond, const int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            arrFirst[i][j] = arrSecond[i][j];
        }
    }
}

//функция вероятности инфекции
bool infection(int chance) {
    int m = rand() % 100 + 1;
    if (m <= chance)
        return true;
    else return false;
}

int main() {
    int size;
    std::cout << "Field size: ";
    std::cin >> size;
    int** arr = new int* [size];
    for (int i = 0; i < size; ++i) {
        arr[i] = new int[size];
    }
    fillArr(arr, size);
    int x_first, y_first;
    std::cout << "Select the first infected cell: x = ";
    std::cin >> x_first;
    std::cout << " y = ";
    std::cin >> y_first;
    //Первая точка заражения с проверкой на область поля
    while (!((x_first > 0 && x_first <= size) && (y_first > 0 && y_first <= size))) {
        std::cout << "Point behind the field!\n";
        std::cout << "Select the first infected cell: x = ";
        std::cin >> x_first;
        std::cout << " y = ";
        std::cin >> y_first;
    }
    x_first -= 1;
    y_first -= 1;
    // 9 - это только заразился
    arr[x_first][y_first] = 9;
    //для рандома
    srand(static_cast<unsigned int>(time(0)));
    //временный массив
    int** arrTemp = new int* [size];
    for (int i = 0; i < size; ++i) {
        arrTemp[i] = new int[size];
    }
    fillArr(arrTemp, size);
    arrTemp[x_first][y_first] = 9;
    //цикл символизирующий период времени, для выходв нажать пробел и интер
    char c = getchar();
    while (c != ' ') {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (arr[i][j] > 0) {
                    int x_begin = i - 1;
                    int x_end = i + 1;
                    int y_begin = j - 1;
                    int y_end = j + 1;
                    for (int x = x_begin; x <= x_end; ++x) {
                        for (int y = y_begin; y <= y_end; ++y) {
                            //проверка на границы поля и нулевой иммунитет
                            if ((x >= 0 && x < size) && (y >= 0 && y < size) && (arr[x][y] == 0)) {
                                //проверка на диагональные соседние ячейки
                                if ((x == i - 1 && y == j - 1) || (x == i - 1 && y == j + 1) || (x == i + 1 && y == j - 1) || (x == i + 1 && y == j + 1)) {
                                    if (infection(25)) {
                                        arrTemp[x][y] = 9;
                                    }
                                }
                                //проверка на соседние ячейки (не диагональные)
                                else if ((x == i && y == j + 1) || (x == i && y == j - 1) || (y == j && x == i + 1) || (y == j && x == i - 1)) {
                                    if (infection(50)) {
                                        arrTemp[x][y] = 9;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << "\n";
        printArr(arrTemp, size);
        c = getchar();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (arrTemp[i][j] <= 9 && arrTemp[i][j] > 0) {
                    //заразность падает
                    arrTemp[i][j] -= 1;
                }
            }
        }
        //копируем временный массив в основной
        arrCopy(arr, arrTemp, size);
        //очищаем экран консоли
        system("cls");
    }

    //очистка динамической памяти
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    for (int i = 0; i < size; ++i) {
        delete[] arrTemp[i];
    }
    delete[] arrTemp;

    return 0;
}
