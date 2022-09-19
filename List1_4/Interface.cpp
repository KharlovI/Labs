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

	switch (typeOfMatrix)
	{
	case 0:
		break;
	case 1:
		if (dataType == 0)
		{
			break;
		}
		else if (dataType == 1)
		{
			AllMatrix::MatrixByList<int>* matrix = new AllMatrix::MatrixByList<int>(size, Answer());
			break;
		}
		else if (dataType == 2)
		{
			AllMatrix::MatrixByList<float>* matrix = new AllMatrix::MatrixByList<float>(size, Answer());
			break;
		}
		else if (dataType == 3)
		{
			AllMatrix::MatrixByList<double>* matrix = new AllMatrix::MatrixByList<double>(size, Answer());
			break;
		}
		else if (dataType == 4)
		{
			AllMatrix::MatrixByList<bool>* matrix = new AllMatrix::MatrixByList<bool>(size, Answer());
			break;
		}
		break;

	case 2:
		if (dataType == 0)
		{
			break;
		}
		else if (dataType == 1)
		{
			AllMatrix::MatrixByListByVectors<int>* matrix = new AllMatrix::MatrixByListByVectors<int>(size, Answer());
			break;
		}
		else if (dataType == 2)
		{
			AllMatrix::MatrixByListByVectors<float>* matrix = new AllMatrix::MatrixByListByVectors<float>(size, Answer());
			break;
		}
		else if (dataType == 3)
		{
			AllMatrix::MatrixByListByVectors<double>* matrix = new AllMatrix::MatrixByListByVectors<double>(size, Answer());
			break;
		}
		else if (dataType == 4)
		{
			AllMatrix::MatrixByListByVectors<bool>* matrix = new AllMatrix::MatrixByListByVectors<bool>(size, Answer());
			break;
		}
		break;

	case 3:
		if (dataType == 0)
		{
			break;
		}
		else if (dataType == 1)
		{
			AllMatrix::ArrayMatrix<int>* matrix = new AllMatrix::ArrayMatrix<int>(size, Answer());
			break;
		}
		else if (dataType == 2)
		{
			AllMatrix::ArrayMatrix<float>* matrix = new AllMatrix::ArrayMatrix<float>(size, Answer());
			break;
		}
		else if (dataType == 3)
		{
			AllMatrix::ArrayMatrix<double>* matrix = new AllMatrix::ArrayMatrix<double>(size, Answer());
			break;
		}
		else if (dataType == 4)
		{
			AllMatrix::ArrayMatrix<bool>* matrix = new AllMatrix::ArrayMatrix<bool>(size, Answer());
			break;
		}
		break;
	}
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
	return answer;
}
int Interface::SetDataType()
{
	int answer;
	std::cout << "Choose type of data:" << std::endl;
	std::cout << "0)Exit   1) int	2) float	3)double	4)bool";
	std::cin >> answer;

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