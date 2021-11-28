#pragma once

class Matrix{
private:
	double** matr;
	int row, col;
	void clear();

public:
	Matrix(int, int);
	~Matrix() { clear(); }
	
	double* operator [] (int n) const;
	Matrix& operator = (const Matrix&);
	Matrix& operator += (Matrix&);
	Matrix& operator *= (Matrix&);
	Matrix& operator * (Matrix&) const;
	Matrix& operator + (Matrix&) const;

	void print()const;
};