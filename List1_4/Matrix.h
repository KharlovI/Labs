#pragma once
#include "List.h"

namespace AllMatrix
{
	template<class T>
	class MatrixByList : public CyclicList::List<T>
	{
	protected:
		struct ID
		{
			int i;
			int j;
		};
	private:
		CyclicList::List<CyclicList::List<T>*>* matrix = new CyclicList::List<CyclicList::List<T>*>();
		int size;
	public:

		MatrixByList(int size)
		{
			this->size = size;

			for (int i = 0; i < size; i++)
			{
				CyclicList::List<T>* temp = new CyclicList::List<T>(size);

				this->matrix->AddNewNode(temp);
			}
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
	};

	template <class T>
	class MatrixByListByVectors : public CyclicList::List<T>
	{
	protected:
		struct ID
		{
			int i;
			int j;
		};
	private:
		CyclicList::List<std::vector<T>*>* matrix = new CyclicList::List<std::vector<T>*>();
		ID size;
	public:
		MatrixByListByVectors(ID size) // i = string, j = column
		{
			srand(time(0));
			this->size = size;

			for (int i = 0; i < size.i; i++)
			{
				std::vector<T>* temp = new std::vector<T>();

				for (int j = 0; j < size.j; j++)
				{
					temp->push_back((rand() % 5 / 3));
				}

				this->matrix->AddNewNode(temp);
			}
		}

		~MatrixByListByVectors()
		{
			for (int i = 0; i < this->size.i; i++)
			{
				delete this->matrix->GetNodeByIndex(i)->data;
			}
		}
		void PrintVectorValues(std::vector<T>* v)
		{
			for (int j = 0; j < this->size.j; j++)
			{
				std::cout << v[j];
			}
		}

		void PrintMatrix()
		{
			CyclicList::List<T>::template Node* iter = this->matrix->tail;


		}
	};
}