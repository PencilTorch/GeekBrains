#include <iostream>
#include<math.h>
#include <vector>
using namespace std;


class Matrix {
public:
    Matrix(size_t n) {
        create_matrix(n, n);
    }
    Matrix(size_t _rows, size_t _cols) {
        create_matrix(_rows, _cols);
    }
    ~Matrix() {
        clear_matrix();
    }
    Matrix(const Matrix& other) {
        clear_matrix();
        create_matrix(other.rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                m[i][j] = other.m[i][j];
            }
        }
    }
    Matrix& operator=(const Matrix& other) {
        clear_matrix();
        create_matrix(other.rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                m[i][j] = other.m[i][j];
            }
        }
    }

    // определитель
    double determinant(size_t rows) {
            if (rows == 1) {
                return m[0][0];
            }
            else if (rows == 2) {
                return m[0][0] * m[1][1] - (m[1][0] * m[0][1]);
            }
            else if (rows >= 3) {
                double det = 0;
                size_t a, b;
                Matrix tmp(rows - 1);
                for (size_t i = 0; i < rows; ++i) {
                    a = 0;
                    for (size_t j = 1; j < rows; ++j) {
                        b = 0;
                        for (size_t k = 0; k < rows; ++k) {
                            if (k != i) {
                                tmp.m[a][b] = m[j][k];
                                b++;
                            }
                        }
                        a++;
                    }
                    det += pow(-1, i + 2) * m[0][i] * tmp.determinant(rows - 1);
                }
                return det;
            }
    }
    // чтение-запись
    friend istream& operator>>(istream& is, Matrix& mtx);
    friend ostream& operator<<(ostream& os, const Matrix& mtx);

    void create_matrix(size_t r, size_t c) {
        this->rows = r;
        this->cols = c;
        m.resize(rows);
        for (size_t i = 0; i < rows; ++i)
            m[i].resize(cols);
    }

    void clear_matrix() {
        if (!m.empty()) {
            for (size_t i = 0; i < rows; ++i)
                m[i].clear();
            m.clear();
            this->rows = 0;
            this->cols = 0;
        }
    }

private:
    vector<vector<double>> m;
    size_t rows;
    size_t cols;
};



int main() {
    Matrix matrix(3, 3);
    cout << "Enter values matrix:\n";
    cin >> matrix;
    cout << "Output of values:\n";
    cout << matrix;
    cout << "\ndeterminant: " << matrix.determinant(3);

    return 0;
}

istream& operator>>(istream& is, Matrix& mtx) {
    for (size_t i = 0; i < mtx.rows; ++i) {
        for (size_t j = 0; j < mtx.cols; ++j) {
            is >> mtx.m[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Matrix& mtx) {
    for (size_t i = 0; i < mtx.rows; ++i) {
        for (size_t j = 0; j < mtx.cols; ++j) {
            os << mtx.m[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}