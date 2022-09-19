#pragma once
#include <iostream>
#include "Matrix.h"

class Interface
{
public:
	void Start();

	int SetTypeOfMatrix();
	int SetDataType();
	int ChooseOption();

	template<typename T>
	void DoOperationListMatrix(AllMatrix::MatrixByList<T>* matrix);
	template<typename T>
	void DoOperationVectoreMatrix(AllMatrix::MatrixByListByVectors<T>* matrix);
	template<typename T>
	void DoOperationArrayMatrix(AllMatrix::ArrayMatrix<T>* matrix);

	CyclicList::ID SetSizeOfMatrix();
};

template<typename T>
inline void Interface::DoOperationListMatrix(AllMatrix::MatrixByList<T>* matrix)
{
	int option = ChooseOption();
	switch (option)
	{
	case 0:
		break;
	case 1:
		matrix->PrintMatrix();
		std::cout << std::endl;//////
		break;
	case 2:
		CyclicList::ID position;
		std::cout << "Enter position(2 digits):" << std::endl;
		std::cin >> position.i >> position.j;
		T value = matrix->GetValueByIndexMatrix(position);
		break;
	case 3:
		T value;
		std::cout << "Enter value:";
		std::cin >> value;
		std::vector<CyclicList::ID> = matrix->GetIndexesByValueMatrix(value);
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		break;
	}
}

template<typename T>
inline void Interface::DoOperationVectoreMatrix(AllMatrix::MatrixByListByVectors<T>* matrix)
{
	int option = ChooseOption();
	switch (option)
	{
	case 0:
		break;
	case 1:
		matrix->PrintMatrix();
		std::cout << std::endl;//////
		break;
	case 2:
		CyclicList::ID position;
		std::cout << "Enter position(2 digits):" << std::endl;
		std::cin >> position.i >> position.j;
		T value = matrix->GetValueByIndexMatrix(position);
		break;
	case 3:
		T value;
		std::cout << "Enter value:";
		std::cin >> value;
		std::vector<CyclicList::ID> = matrix->GetIndexesByValueMatrix(value);
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		break;
	}
}

template<typename T>
inline void Interface::DoOperationArrayMatrix(AllMatrix::ArrayMatrix<T>* matrix)
{
	int option = ChooseOption();
	switch (option)
	{
	case 0:
		break;
	case 1:
		matrix->PrintMatrix();
		std::cout << std::endl;//////
		break;
	case 2:
		CyclicList::ID position;
		std::cout << "Enter position(2 digits):" << std::endl;
		std::cin >> position.i >> position.j;
		T value = matrix->GetValueByIndexMatrix(position);
		break;
	case 3:
		T value;
		std::cout << "Enter value:";
		std::cin >> value;
		std::vector<CyclicList::ID> = matrix->GetIndexesByValueMatrix(value);
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		break;
	}
}
