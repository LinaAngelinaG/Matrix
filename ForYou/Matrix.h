#pragma once

class Matrix{
private:
	double** matr;
	int row, col;
	void clear();

public:
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix() { clear(); }
	
	double* operator [] (int n) const;
	Matrix& operator = (const Matrix&);
	Matrix& operator += (const Matrix&);
	Matrix& operator *= (const Matrix&);
	Matrix operator * (const Matrix&) const;
	Matrix operator + (const Matrix&) const;

	void print()const;
};