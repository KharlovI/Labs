#pragma once
#include <iostream>
#include "Matrix.h"

class Interface
{
public:
	int SetTypeOfMatrix();
	int SetDataType();
	int ChooseOption();

	template<typename T>
	void DoOperationListMatrix(AllMatrix::MatrixByList<T>* matrix);
	template<typename T>
	void DoOperationVectoreMatrix(AllMatrix::MatrixByListByVectors<T>* matrix);
	template<typename T>
	void DoOperationArrayMatrix(AllMatrix::ArrayMatrix<T>* matrix);

	void Start();
	CyclicList::ID SetSizeOfMatrix();
};

template<typename T>
inline void Interface::DoOperationListMatrix(AllMatrix::MatrixByList<T>* matrix)
{
	int option = ChooseOption();
	while (option != 0)
	{
		T value;
		CyclicList::ID size;
		CyclicList::ID position;
		int answer;
		AllMatrix::MatrixByList<T>* matrix2;
		std::vector<CyclicList::ID> indexes;

		if (option == 1)
		{
			matrix->PrintMatrix();
			std::cout << std::endl;
		}
		else if (option == 2)
		{
			CyclicList::ID position;
			std::cout << "Enter position(2 digits):" << std::endl;
			std::cin >> position.i >> position.j;
			T value = matrix->GetValueByIndexMatrix(position);
			std::cout << value;
			std::cout << std::endl;
		}
		else if (option == 3)
		{
			T value;
			std::cout << "Enter value:";
			std::cin >> value;
			std::vector<CyclicList::ID> indexes = matrix->GetIndexesByValueMatrix(value);
			for (int i = 0; i < indexes.capacity(); i++)
			{
				std::cout << indexes[i].i << " " << indexes[i].j << '\t';
			}
			std::cout << std::endl;
		}
		else if (option == 4)
		{
			T value;
			std::cout << "Choose condition:" << std::endl;
			value = matrix->GetFirstValueByConditionMatrix();
			std::cout << value;
			std::cout << std::endl;
		}
		else if (option == 5)
		{
			CyclicList::ID size;
			std::cout << "Enter the second matrix:" << std::endl;
			std::cout << "Size:";
			std::cin >> size.i >> size.j;
			while (size.i != matrix->GetSize().i || size.j != matrix->GetSize().j)
			{
				std::cout << "Enter correct size:" << " i == " << matrix->GetSize().i << " and j  == " << matrix->GetSize().j << std::endl;
				std::cin >> size.i >> size.j;
			}
			int answer = Answer();
			AllMatrix::MatrixByList<T>* matrix2 = new AllMatrix::MatrixByList<T>(size, answer);
			matrix->PrintMatrix();
			std::cout << "  +  " << std::endl;
			matrix2->PrintMatrix();
			std::cout << "  ||  " << std::endl;
			matrix->SumMatrix(matrix2)->PrintMatrix();
			break;
		}
		else if (option == 6)
		{
			std::cout << "Enter the second matrix:" << std::endl;
			std::cout << "Size:";
			std::cin >> size.i >> size.j;
			while ((matrix->GetSize().j != size.i) || (size.i == 0) || (size.j = 0))
			{
				std::cout << "Enter correct size:" << " i == " << matrix->GetSize().j << " and j could be non zero value" << std::endl;
				std::cin >> size.i >> size.j;
			}
			int answer = Answer();
			AllMatrix::MatrixByList<T>* matrix2 = new AllMatrix::MatrixByList<T>(size, answer);
			matrix->PrintMatrix();
			std::cout << "  *  " << std::endl;
			matrix2->PrintMatrix();
			std::cout << "  ||  " << std::endl;
			matrix->MultiplyMatrices(matrix2)->PrintMatrix();
			std::cout << std::endl;
		}
		else if (option == 7)
		{
			std::cout << std::endl;
			matrix->MatrixTransposition()->PrintMatrix();
		}
		option = ChooseOption();
	}
}

//template<typename T>
//inline void Interface::DoOperationVectoreMatrix(AllMatrix::MatrixByListByVectors<T>* matrix)
//{
//	int option = ChooseOption();
//	while (option != 0)
//	{
//		T value;
//		CyclicList::ID position;
//		CyclicList::ID size;
//		int answer;
//		AllMatrix::MatrixByListByVectors<T>* matrix2;
//		std::vector<CyclicList::ID> indexes;
//
//		switch (option)
//		{
//		case 0:
//			break;
//		case 1:
//			matrix->PrintMatrix();
//			std::cout << std::endl;//////
//			break;
//		case 2:
//			std::cout << "Enter position(2 digits):" << std::endl;
//			std::cin >> position.i >> position.j;
//			value = matrix->GetValueByIndexMatrix(position);
//			std::cout << std::endl;
//			std::cout << value;
//			std::cout << std::endl;
//			break;
//		case 3:
//			value;
//			std::cout << "Enter value:";
//			std::cin >> value;
//			indexes = matrix->GetIndexesByValueMatrix(value);
//			std::cout << std::endl;
//			for (int i = 0; i < indexes.capacity(); i++)
//			{
//				std::cout << indexes[i].i << " " << indexes[i].j << '\t';
//			}
//			std::cout << std::endl;
//			break;
//		case 4:
//			value;
//			std::cout << "Choose condition:" << std::endl;
//			value = matrix->GetFirstValueByConditionMatrix();
//			std::cout << std::endl;
//			std::cout << value;
//			std::cout << std::endl;
//			break;
//		case 5:
//			std::cout << "Enter the second matrix:" << std::endl;
//			std::cout << "Size:" << std::endl;
//			std::cin >> size.i >> size.j;
//			while (size.i != matrix->GetSize().i || size.j != matrix->GetSize().j)
//			{
//				std::cout << "Enter correct size:" << " i == " << matrix->GetSize().i << " and j  == " << matrix->GetSize().j << std::endl;
//				std::cin >> size.i >> size.j;
//			}
//			answer = Answer();
//			matrix2 = new AllMatrix::MatrixByListByVectors<T>(size, answer);
//			matrix->PrintMatrix();
//			std::cout << "  +  " << std::endl;
//			matrix2->PrintMatrix();
//			std::cout << "  ||  " << std::endl;
//			matrix->SumMatrix(matrix2)->PrintMatrix();
//			std::cout << std::endl;
//			break;
//			
//		case 6:
//			std::cout << "Enter the second matrix:" << std::endl;
//			std::cout << "Size:";
//			std::cin >> size.i >> size.j;
//			while ((matrix->GetSize().j != size.i) || (size.j = 0))
//			{
//				std::cout << "Enter correct size:" << " i == " << matrix->GetSize().j << " and j could be non zero value" << std::endl;
//				std::cin >> size.i >> size.j;
//			}
//			answer = Answer();
//			matrix2 = new AllMatrix::MatrixByListByVectors<T>(size, answer);
//			matrix->PrintMatrix();
//			std::cout << "  *  " << std::endl;
//			matrix2->PrintMatrix();
//			std::cout << "  ||  " << std::endl;
//			matrix->MultiplyMatrices(matrix2)->PrintMatrix();
//			std::cout << std::endl;
//			break;
//		case 7:
//			std::cout << std::endl;
//			matrix->MatrixTransposition()->PrintMatrix();
//			break;
//		}
//		option = ChooseOption();
//	}
//}
//
//template<typename T>
//inline void Interface::DoOperationArrayMatrix(AllMatrix::ArrayMatrix<T>* matrix)
//{
//	int option = ChooseOption();
//	while (option != 0)
//	{
//		T value;
//		CyclicList::ID position;
//		CyclicList::ID size;
//		int answer;
//		AllMatrix::ArrayMatrix<T>* matrix2;
//		std::vector<CyclicList::ID> indexes;
//
//		switch (option)
//		{
//		case 0:
//			break;
//		case 1:
//			matrix->PrintMatrix();
//			std::cout << std::endl;//////
//			break;
//		case 2:
//			std::cout << "Enter position(2 digits):" << std::endl;
//			std::cin >> position.i >> position.j;
//			value = matrix->GetValueByIndexMatrix(position);
//			break;
//		case 3:
//			value;
//			std::cout << "Enter value:";
//			std::cin >> value;
//			indexes = matrix->GetIndexesByValueMatrix(value);
//			break;
//		case 4:
//			value;
//			std::cout << "Choose condition:" << std::endl;
//			value = matrix->GetFirstValueByConditionMatrix();
//			std::cout << value;
//			break;
//		case 5:
//			std::cout << "Enter the second matrix:" << std::endl;
//			std::cout << "Size:";
//			std::cin >> size.i >> size.j;
//			while ((size.i != matrix->GetSize().i) || size.j != matrix->GetSize().j)
//			{
//				std::cout << "Enter correct size:" << " i == " << matrix->GetSize().i << " and j  == " << matrix->GetSize().j << std::endl;
//				std::cin >> size.i >> size.j;
//			}
//			answer = Answer();
//		    matrix2 = new AllMatrix::ArrayMatrix<T>(size, answer);
//			matrix->PrintMatrix();
//			std::cout << "  +  " << std::endl;
//			matrix2->PrintMatrix();
//			std::cout << "  ||  " << std::endl;
//			matrix->SumMatrix(matrix2)->PrintMatrix();
//			break;
//		case 6:
//			std::cout << "Enter the second matrix:" << std::endl;
//			std::cout << "Size:";
//			std::cin >> size.i >> size.j;
//			while ((matrix->GetSize().j != size.i) || (size.i == 0) || (size.j = 0))
//			{
//				std::cout << "Enter correct size:" << " i == " << matrix->GetSize().j << " and j could be non zero value" << std::endl;
//				std::cin >> size.i >> size.j;
//			}
//			answer = Answer();
//			matrix2 = new AllMatrix::ArrayMatrix<T>(size, answer);
//			matrix->PrintMatrix();
//			std::cout << "  *  " << std::endl;
//			matrix2->PrintMatrix();
//			std::cout << "  =  " << std::endl;
//			matrix->MultiplyMatrices(matrix2)->PrintMatrix();
//			std::cout << std::endl;
//			break;
//		case 7:
//			std::cout << std::endl;
//			matrix->MatrixTransposition()->PrintMatrix();
//			break;
//		}
//		option = ChooseOption();
//	}
//}
