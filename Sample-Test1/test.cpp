#include "pch.h"
#include "Matrix.h"

TEST(TestConstructor, Constructors) {
	int a = 3, b = 2;
	Matrix mat1(a,b);
	Matrix mat2(b,a);
	Matrix mat3(3, 2);

	mat1.print();
	mat2.print();
	mat3.print();

	mat3 = mat1 + mat1;
	//mat3 = mat1;

	mat3[0][0] = 1;

	mat3.print();

	//mat1 *= mat2;
	mat1 = mat1 * mat2;
	//(mat1 * mat2).print();
	mat1.print();

}