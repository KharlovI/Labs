#include "Interface.h"
#include "TimeDate.h"

void Interface::Start()
{
	int typeOfMatrix;
	int dataType;
	int mainAnswer;

	CyclicList::ID size;

	typeOfMatrix = SetTypeOfMatrix();
	if (typeOfMatrix != 0)
	{
		dataType = SetDataType();
		if (dataType != 0)
		{
			size = SetSizeOfMatrix();

			if (typeOfMatrix == 1)
			{
				if (dataType == 1)
				{
					AllMatrix::MatrixByList<int>* matrix1 = new AllMatrix::MatrixByList<int>(size, Answer());
					int option = ChooseOption();
					DoOperationListMatrix<int>(matrix1, option);
					delete matrix1;
				}
				else if (dataType == 2)
				{
					AllMatrix::MatrixByList<float>* matrix1 = new AllMatrix::MatrixByList<float>(size, Answer());
					int option = ChooseOption();
					DoOperationListMatrix<float>(matrix1, option);
					delete matrix1;
				}
				else if (dataType == 3)
				{
					AllMatrix::MatrixByList<double>* matrix1 = new AllMatrix::MatrixByList<double>(size, Answer());
					int option = ChooseOption();
					DoOperationListMatrix<double>(matrix1, option);
					delete matrix1;
				}
				else if (dataType == 4)
				{
					std::cout << "You can not chouse this type" << std::endl;
				}
			}

			else if (typeOfMatrix == 2)
			{
				if (dataType == 1)
				{
					AllMatrix::MatrixByListByVectors<int>* matrix1 = new AllMatrix::MatrixByListByVectors<int>(size, Answer());
					int option = ChooseOption();
					DoOperationVectoreMatrix<int>(matrix1, option);
					delete matrix1;
				}
				else if (dataType == 2)
				{
					AllMatrix::MatrixByListByVectors<float>* matrix1 = new AllMatrix::MatrixByListByVectors<float>(size, Answer());
					int option = ChooseOption();
					DoOperationVectoreMatrix<float>(matrix1, option);
					delete matrix1;
				}
				else if (dataType == 3)
				{
					AllMatrix::MatrixByListByVectors<double>* matrix1 = new AllMatrix::MatrixByListByVectors<double>(size, Answer());
					int option = ChooseOption();
					DoOperationVectoreMatrix<double>(matrix1, option);
					delete matrix1;
				}
				else if (dataType == 4)
				{
					std::cout << "You can not chouse this type" << std::endl;
				}

			}
			else if (typeOfMatrix == 3)
			{
				if (dataType == 1)
				{
					AllMatrix::ArrayMatrix<int>* matrix1 = new AllMatrix::ArrayMatrix<int>(size, Answer());
					int option = ChooseOption();
					DoOperationArrayMatrix<int>(matrix1, option);
					delete matrix1;
				}
				else if (dataType == 2)
				{
					AllMatrix::ArrayMatrix<float>* matrix1 = new AllMatrix::ArrayMatrix<float>(size, Answer());
					int option = ChooseOption();
					DoOperationArrayMatrix<float>(matrix1,option);
					delete matrix1;
				}
				else if (dataType == 3)
				{
					AllMatrix::ArrayMatrix<double>* matrix1 = new AllMatrix::ArrayMatrix<double>(size, Answer());
					int option = ChooseOption();
					DoOperationArrayMatrix<double>(matrix1, option);
					delete matrix1;
				}
				else if (dataType == 4)
				{
					AllMatrix::ArrayMatrix<DateTime>* matrix1 = new AllMatrix::ArrayMatrix<DateTime>(size, Answer());

					int option = ChooseOption();
					while (option == 6)
					{
						std::cout << "This option is unvaluable for dataType (date)" << std::endl;
						option = ChooseOption();
					}
					DoOperationArrayMatrix<DateTime>(matrix1, option);
					delete matrix1;
				}
			}
		}
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
	std::cout << std::endl;

	return answer;
}
int Interface::SetDataType()
{
	int answer;
	std::cout << "Choose type of data:" << std::endl;
	std::cout << "0)Exit   1) int	2) float   3)double  4) date" << std::endl;
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