#include <iostream>
#include "Matrix.h"

int main()
{
	AllMatrix::MatrixByListByVectors<int>* m = new AllMatrix::MatrixByListByVectors<int>({1,2}, 1);
	m->PrintMatrix();
	std::cout << std::endl;
	AllMatrix::MatrixByListByVectors<int>* m2 = new AllMatrix::MatrixByListByVectors<int>({ 2,1 }, 1);
	std::cout << std::endl;
	m2->PrintMatrix();
	AllMatrix::MatrixByListByVectors<int>* m3 = m->MultiplyMatrices(m2);
	std::cout << std::endl;
	m3->PrintMatrix();
}