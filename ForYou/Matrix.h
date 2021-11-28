#pragma once
#include <iostream>

template <class T>
class Matrix
{
private:
	T** matr;
	int row, col;
	void clear();
public:
	Matrix(int, int);
	~Matrix() { clear(); }
	Matrix(const Matrix<T>& a);

	T* operator [] (int n) const;
	Matrix<T>& operator = (const Matrix<T>&);
	Matrix<T>& operator += (Matrix<T>&);
	Matrix<T>& operator *= (Matrix<T>&);
	Matrix<T>& operator * (Matrix<T>&) const;
	Matrix<T>& operator + (Matrix<T>&) const;
	void print()const;
};