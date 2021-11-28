#include "Matrix.h"
#include <iostream>

template <class T>
T* Matrix<T>::operator [] (int n) const{
	return matr[n];
}

template <class T>
void Matrix<T>::clear() {
	for (int j = 0; j < col; j++) {
		delete[] matr[j];
	}
	if (row > 0) {
		delete[] matr;
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& another)
{
	row = another.row;
	col = another.col;
	clear();
	matr = new T* [row]; 
	for (int i = 0; i < row; i++) {
		matr[i] = new T[col];
	}
	for (int k = 0; k < row; k++) {
		for (int i = 0; i < col; i++) {
			matr[k][i] = another.matr[k][i];
		}
	}
}

template <class T>
Matrix<T>::Matrix(int n, int m) : row(n), col(m) {
	matr = new T* [row];
	for (int j = 0; j < n; j++) {
		matr[j] = new T[col];
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matr[i][j] = (T) i*j;
		}
	}
};

template <class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T>& another) {
	if (this != &another) {
		clear();
		col = another.col;
		row = another.row;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matr[i][j] = another.matr[i][j];
			}
		}
	}
	return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator += (Matrix<T>& another) {
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

template <class T>
Matrix<T>& Matrix<T>::operator *= (Matrix<T>& another) {
	if (col != another.row) {
		throw std::exception("Different sizes.");
	}
	Matrix<T> mat(row, col);
	mat = *this;
	clear();
	matr = new  T*[row];
	for (int j = 0; j < row; j++) {
		matr[j] = new T[another.row];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matr[i][j] = 0;
			for (int k = 0; k < col; k++) {
				matr[i][j] += mat.matr[i][k] * another[k][j];
			}
		}
	}

	return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator * (Matrix<T>& another) const {
	if (col != another.row) {
		throw std::exception("Different sizes.");
	}
	Matrix<T> matr_res(row, another.col);
	matr_res = *this;
	matr_res *= another;
	/*
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matr_res[i][j] = 0;
			for (int k = 0; k < col; k++) {
				matr_res[i][j] += matr[i][k] * another[k][j];
			}
		}
	}*/
	return matr_res;
}

template <class T>
void Matrix<T>::print() const{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			std::cout << matr[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << "---------------------" << std::endl;
}

template <class T>
Matrix<T>& Matrix<T>::operator + (Matrix<T>& another) const {
	if (another.row != row || another.col != col) {
		throw std::exception("Different sizes.");
	}
	Matrix<T> mnew(row,col);
	mnew = *this;
	mnew += another;
	return mnew;
}