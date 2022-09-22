#include <iostream>
#include "Matrix.h"
#include"Interface.h"
int main()
{
	/*Interface i{};
	i.Start();*/
	AllMatrix::MatrixByListByVectors<double>* m1 = new AllMatrix::MatrixByListByVectors<double>({3,3},0);
	delete m1;

	//AllMatrix::ArrayMatrix<double>* m2 = new AllMatrix::ArrayMatrix<double>({ 3000,3000 }, 0);
	//m2->~ArrayMatrix();
	////AllMatrix::MatrixByList<double>* m2 = new AllMatrix::MatrixByList<double>({ 3,1 }, 1);
	//m1->MultiplyMatrices(m2)->PrintMatrix();
}