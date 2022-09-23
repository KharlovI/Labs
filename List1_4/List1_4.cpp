#include <iostream>
//#include "Matrix.h"
//#include"Interface.h"
#include "TimeDate.h"
int main()
{
	Date::DateTime t;
	t.SetData(1998, 2,29, 15, 36, 63);
	t.PrintExactDate();
	std::cout << std::endl;
	Date::DateTime t2;
	t2.SetData(1998, 2, 29, 15, 36, 63);
	t2.PrintExactDate();
	std::cout << std::endl;
    (t + t2).PrintExactDate();
	/*std::cout << t.IsCorrectByGregorianCalendar() << std::endl;
	t.PrintDateByGregorianCalendar();
	t.PrintExactDate();
	t.NormalizeTime();
	std::cout << std::endl;
	std::cout << t.IsCorrectByGregorianCalendar() << std::endl;
	t.PrintDateByGregorianCalendar();
	t.PrintExactDate();*/
	/*Interface i{};
	i.Start();*/
	//AllMatrix::MatrixByListByVectors<double>* m1 = new AllMatrix::MatrixByListByVectors<double>({3,3},0);
	//delete m1;

	//AllMatrix::ArrayMatrix<double>* m2 = new AllMatrix::ArrayMatrix<double>({ 3000,3000 }, 0);
	//m2->~ArrayMatrix();
	////AllMatrix::MatrixByList<double>* m2 = new AllMatrix::MatrixByList<double>({ 3,1 }, 1);
	//m1->MultiplyMatrices(m2)->PrintMatrix();
}