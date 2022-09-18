#pragma once
#include "List.h"

namespace AllMatrix
{
	template<class T, class U>
	class Matrix : public CyclicList::List<T>
	{
	private:
		struct ID
		{
			int i;
			int j;
		};

		CyclicList::List<U>* matrix = new CyclicList::List<U>();
		int size;

	public:

		Matrix(int size)
		{
			this->size = size;

			for (int i = 0; i < size; i++)
			{
				CyclicList::List<T>* temp = new CyclicList::List<T>(size);

				this->matrix->AddNewNode((U)temp);
			}
		}

		~Matrix()
		{
			this->matrix->~List();
		}

		void PrintMatrix()
		{
			for (int i = 0; i < this->size; i++)
			{
				this->matrix->GetNodeByIndex(i)->data->Print();
				std::cout << std::endl;
			}

			std::cout << std::endl;
		}

		CyclicList::List<T>::template Node* GetNodeByIndexMatrix(ID position)
		{
			return ((this->matrix->GetNodeByIndex(position.i))->data->GetNodeByIndex(position.j));
		}

		std::vector<ID>(int value)
		{
			std::vector<ID> v;
			std::vector<int> buffer;

			for (int i = 0; i < this->size; i++)
			{
				buffer = this->matrix->GetNodeByIndex(i)->data->GetIndexByValue(value);
			}
		}
	};
}