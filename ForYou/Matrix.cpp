#include "Matrix.h"
#include <iostream>


double* Matrix::operator [] (int n) const{
	return matr[n];
}

void Matrix::clear() {
	for (int j = 0; j < row; j++) {
		delete[] matr[j];
	}
	if (row > 0) {
		delete[] matr;
	}
}

Matrix::Matrix(int n, int m) : row(n), col(m) {
	matr = new double* [row];
	for (int j = 0; j < n; j++) {
		matr[j] = new double[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matr[i][j] = (double)i * j;
		}
	}
}; 

Matrix& Matrix::operator = (const Matrix& another) {
	if (this != &another) {
		clear();
		col = another.col;
		row = another.row;
		matr = new  double* [row];
		for (int j = 0; j < row; j++) {
			matr[j] = new double[another.col];
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matr[i][j] = another.matr[i][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator += (Matrix& another) {
	if (another.row != row || another.col != col) {
		throw std::exception("Different sizes.");
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matr[i][j] += another[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator *= (Matrix& another) {
	if (col != another.row) {
		throw std::exception("Different sizes.");
	}
	Matrix mat(row, col);
	mat = *this;
	clear();
	matr = new  double*[row];
	col = another.col;
	for (int j = 0; j < row; j++) {
		matr[j] = new double[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matr[i][j] = 0;
			for (int k = 0; k < another.row; k++) {
				matr[i][j] += mat.matr[i][k] * another[k][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator * (Matrix& another) const {
	if (col != another.row) {
		throw std::exception("Different sizes.");
	}
	Matrix* matr_res = new Matrix(row,col);
	*matr_res = *this;
	(*matr_res) *= another;
	return *matr_res;
}

void Matrix::print() const{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			std::cout << matr[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << "---------------------" << std::endl;
}

Matrix& Matrix::operator + (Matrix& another) const {
	if (another.row != row || another.col != col) {
		throw std::exception("Different sizes.");
	}
	Matrix* mnew = new Matrix(row,col);
	*mnew = *this;
	*mnew += another;
	
	return *mnew;
}