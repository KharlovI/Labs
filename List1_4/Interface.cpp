#include "Interface.h"

void Interface::Start()
{
	int typeOfMatrix;
	int dataType;
	int mainAnswer;

	CyclicList::ID size;

	typeOfMatrix = SetTypeOfMatrix();
	dataType = SetDataType();
	size = SetSizeOfMatrix();

	if (typeOfMatrix == 1)
	{
		if (dataType == 1)
		{
			AllMatrix::MatrixByList<int>* matrix1 = new AllMatrix::MatrixByList<int>(size,Answer());
			DoOperationListMatrix<int>(matrix1);
		}
		else if (dataType == 2)
		{
			AllMatrix::MatrixByList<float>* matrix1 = new AllMatrix::MatrixByList<float>(size, Answer());
			DoOperationListMatrix<float>(matrix1);
		}
		else if (dataType == 3)
		{
			AllMatrix::MatrixByList<double>* matrix1 = new AllMatrix::MatrixByList<double>(size, Answer());
			DoOperationListMatrix<double>(matrix1);
		}
		
	}

	/// <summary>
	/// ///
	/// </summary>
	/*else if (typeOfMatrix == 2)
	{

	}
	else if (typeOfMatrix == 3)
	{

	}*/
}

int Interface::SetTypeOfMatrix()
{
	int answer;
	std::cout << "Choose type of matrix:" << std::endl;
	std::cout << "0)Exit  1)List of lists  2) List of vectors  3)Arrays" << std::endl;
	std::cin >> answer;

	while (answer > 3 || answer < 0)
	{
		std::cout << "Pleas, choose correct answer:" << std::endl;
		std::cin >> answer;
	}
	std::cout << std::endl;

	return answer;
}
int Interface::SetDataType()
{
	int answer;
	std::cout << "Choose type of data:" << std::endl;
	std::cout << "0)Exit   1) int	2) float	3)double	4)bool" << std::endl;
	std::cin >> answer;
	std::cout << std::endl;
	while (answer > 4 || answer < 0)
	{
		std::cout << "Pleas, choose correct answer:" << std::endl;
		std::cin >> answer;
	}
	return answer;
}
int Interface::ChooseOption()
{
	int answer;
	std::cout << "Choose option:" << std::endl;
	ShowOptions();
	std::cin >> answer;

	while(answer < 0 || answer > 7)
	std::cin >> answer;

	std::cout << std::endl;
	return answer;
}

CyclicList::ID Interface::SetSizeOfMatrix()
{
	CyclicList::ID size;
	std::cout << "Enter size of matrix:" << std::endl;
	std::cout << "Count of string:  ";
	std::cin >> size.i;
	while (size.i <= 0)
	{
		std::cout << "Pleas, choose size > 0" << std::endl;
		std::cin >> size.i;
	}
	std::cout << "Count of column:  ";
	std::cin >> size.j;
	while (size.j <= 0)
	{
		std::cout << "Pleas, choose size > 0" << std::endl;
		std::cin >> size.i;
	}
	return size;
}