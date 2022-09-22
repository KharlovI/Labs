#pragma once
#include "List.h"

namespace AllMatrix
{
	template<class T>
	class MatrixByList : public CyclicList::List<T>
	{
	private:
		CyclicList::List<CyclicList::List<T>*>* matrix = new CyclicList::List<CyclicList::List<T>*>();
		CyclicList::ID size;
	public:
		MatrixByList()
		{
			this->head = nullptr;
			this->tail = nullptr;
			this->size = { NULL,NULL };
		}
		MatrixByList(int size)
		{
			this->head = nullptr;
			this->tail = nullptr;
			this->size = { size,0 };
			for (int i = 0; i < size; i++)
			{
				CyclicList::List<T>* temp = new CyclicList::List<T>();
				this->matrix->AddNewNode(temp);
			}
		}
		MatrixByList(CyclicList::ID size)
		{
			this->head = nullptr;
			this->tail = nullptr;
			this->size = size;
			for (int i = 0; i < size.i; i++)
			{
				CyclicList::List<T>* temp = new CyclicList::List<T>(size.j);
				this->matrix->AddNewNode(temp);
			}
		}
		MatrixByList(CyclicList::ID size, int answer)
		{
			this->size = size;
			for (int i = 0; i < size.i; i++)
			{
				CyclicList::List<T>* temp = new CyclicList::List<T>(size.j, answer);
				this->matrix->AddNewNode(temp);
			}
		}
		~MatrixByList()
		{
			CyclicList::List<CyclicList::List<T>*>::template Node* iterForMatrix1 = this->matrix->GetTail();
			CyclicList::List<CyclicList::List<T>*>::template Node* iterForMatrix2 = iterForMatrix1->prev;

			CyclicList::List<T>::template Node* iter1 = iterForMatrix1->data->GetTail();
			CyclicList::List<T>::template Node* iter2 = iter1->prev;
			for (int i = 0; i < this->size.i - 2; i++)
			{
				for (int j = 0; j < this->size.j - 2; j++)
				{
					delete (iter1);
					iter1 = iter2;
					iter2 = iter2->prev;
				}
				delete (iter1);
				delete iter2;
				delete (iterForMatrix1);
				iterForMatrix1 = iterForMatrix2;
				iterForMatrix2 = iterForMatrix2->prev;
				iter1 = iterForMatrix1->data->GetTail();
				iter2 = iter1->prev;
			}
			delete iterForMatrix1;
			delete iterForMatrix2;
		}

		void SetSize(CyclicList::ID size)
		{
			this->size.i = size.i;
			this->size.j = size.j;
		}
		CyclicList::ID GetSize()
		{
			return this->size;
		}

		void PrintMatrix()
		{
			CyclicList::List<CyclicList::List<T>*>::template Node* iter = this->matrix->GetTail();
			for (int i = 0; i < this->size.i; i++)
			{
				iter->data->Print();
				std::cout << std::endl;
				iter = iter->prev;
			}
			std::cout << std::endl;
		}

		T GetValueByIndexMatrix(CyclicList::ID position)
		{
			if (this->size.i >= position.i && this->size.j >= position.j)
			{
				CyclicList::List<CyclicList::List<T>*>::template Node* iter = this->matrix->GetTail();

				while (iter->index != (position.i - 1))
				{
					iter = iter->prev;
				}
				return (iter->data->GetValueByIndex(position.j - 1));
			}
			else
			{
				std::cout << "out of range: i = " << this->size.i << "  j = " << this->size.j << std::endl;
				return (T)NULL;
			}
		}
		std::vector<CyclicList::ID> GetIndexesByValueMatrix(T value)
		{
			std::vector<CyclicList::ID> temp;
			CyclicList::List<CyclicList::List<T>*>::template Node* iter = this->matrix->GetTail();
			CyclicList::List<T>::template Node* iter2 = iter->data->GetTail();

			for (int i = 0; i < this->size.i; i++)
			{
				for (int j = 0; j < this->size.j; j++)
				{
					if(iter2->data == value)
					temp.push_back({ iter->index,iter2->index});
					iter2 = iter2->prev;
				}
				iter = iter->prev;
				iter2 = iter->data->GetTail();
			}

			return temp;
		}
		T GetFirstValueByConditionMatrix()
		{
			CyclicList::List<CyclicList::List<T>*>::template Node* iter = this->matrix->GetTail();
			int condition = Condition();
			T value;
			std::cout << "Enter value:" << std::endl;
			std::cin >> value;

			T answer = iter->data->GetFirstValueByCondition(condition, value);

			for (int i = 0; i < this->size.i; i++)
			{
				if (answer != T(NULL))
					return answer;
				iter = iter->prev;
				answer = iter->data->GetFirstValueByCondition(condition, value);
			}
			return answer;
		}

		MatrixByList<T>* SumMatrix(MatrixByList<T>* m2)
		{
			MatrixByList<T>* answer = new MatrixByList<T>();
			answer->SetSize(this->size);
			CyclicList::List<CyclicList::List<T>*>::template Node* iterForMatrix1 = this->matrix->GetTail();
			CyclicList::List<CyclicList::List<T>*>::template Node* iterForMatrix2 = m2->matrix->GetTail();

			CyclicList::List<T>* iterForList1 = iterForMatrix1->data;
			CyclicList::List<T>* iterForList2 = iterForMatrix2->data;

			for (int i = 0; i < this->size.i; i++)
			{
				answer->matrix->AddNewNode(iterForList1->Sum(iterForList2, this->size.j));
				iterForMatrix1 = iterForMatrix1->prev;
				iterForMatrix2 = iterForMatrix2->prev;
				iterForList1 = iterForMatrix1->data;
				iterForList2 = iterForMatrix2->data;
			}
			return answer;
		}
		MatrixByList<T>* MultiplyMatrices(MatrixByList<T>* m2)
		{
			if (this->size.j == m2->size.i)
			{
				MatrixByList<T>* answer = new MatrixByList<T>({ this->size.i, m2->size.j });
				CyclicList::List<CyclicList::List<T>*>::template Node* iterMatrixAnswer = answer->matrix->GetTail();
				CyclicList::List<CyclicList::List<T>*>::template Node* iterMatrix1 = this->matrix->GetTail();
				CyclicList::List<CyclicList::List<T>*>::template Node* iterMatrix2 = m2->matrix->GetTail();

				CyclicList::List<T>::template Node* iterListAnswer = iterMatrixAnswer->data->GetTail();
				CyclicList::List<T>::template Node* iterList1 = iterMatrix1->data->GetTail();
				CyclicList::List<T>::template Node* iterList2 = iterMatrix2->data->GetTail();


				for (int k = 0; k < this->size.i; k++)
				{
					for (int i = 0; i < this->size.j; i++)
					{
						for (int j = 0; j < m2->size.j; j++)
						{
							iterListAnswer->data += iterList1->data * iterList2->data;

							iterList2 = iterList2->prev;
							iterListAnswer = iterListAnswer->prev;
						}
						iterMatrix2 = iterMatrix2->prev;
						iterList2 = iterMatrix2->data->GetTail();
						iterList1 = iterList1 ->prev;
					}
					iterMatrix1 = iterMatrix1->prev;
					iterList1 = iterMatrix1->data->GetTail();
					iterMatrixAnswer = iterMatrixAnswer->prev;
					iterListAnswer = iterMatrixAnswer->data->GetTail();
				}
				return answer;
			}

			return nullptr;
		}
		MatrixByList<T>* MatrixTransposition()
		{
			MatrixByList<T>* answer = new MatrixByList<T>(this->size.j);
			answer->SetSize({ this->size.j, this->size.i });
			CyclicList::List<CyclicList::List<T>*>::template Node* iterMatrix1 = this->matrix->GetTail();
			CyclicList::List<CyclicList::List<T>*>::template Node* iterMatrix2 = answer->matrix->GetTail();

			CyclicList::List<T>::template Node* iter1 = iterMatrix1->data->GetTail();
			//CyclicList::List<T>::template Node* iter2 = iterMatrix2->data->GetTail();

			for (int i = 0; i < answer->size.j; i++)
			{
				for (int j = 0; j < answer->size.i; j++)
				{
					(*iterMatrix2->data).AddNewNode(iter1->data);
					iterMatrix2 = iterMatrix2->prev;
					iter1 = iter1->prev;
				}
				iterMatrix1 = iterMatrix1->prev;
				iter1 = iterMatrix1->data->GetTail();
			}
			return answer;
		}
	};

	template <class T>
	class MatrixByListByVectors : public CyclicList::List<T>
	{
	private:
		CyclicList::List<std::vector<T>*>* matrix = new CyclicList::List<std::vector<T>*>();
		CyclicList::ID size;
	public:
		MatrixByListByVectors()
		{
			this->head = nullptr;
			this->tail = nullptr;
			this->size = {NULL,NULL};
		}
		MatrixByListByVectors(CyclicList::ID size)
		{
			this->head = nullptr;
			this->tail = nullptr;
			this->size = size;
			for (int i = 0; i < size.i; i++)
			{
				std::vector<T>* temp = new std::vector<T>();

				for (int j = 0; j < size.j; j++)
				{
					temp->push_back(NULL);
				}

				this->matrix->AddNewNode(temp);
			}
		}
		MatrixByListByVectors(CyclicList::ID size, int answer) // i = string, j = column
		{
			srand(time(0));
			this->size = size;

			switch (answer)
			{
			case 0:
				for (int i = 0; i < size.i; i++)
				{
					std::vector<T>* temp = new std::vector<T>();

					for (int j = 0; j < size.j; j++)
					{
						temp->push_back((T)(rand() % 5 / 3));
					}

					this->matrix->AddNewNode(temp);
				}

				break;
			case 1:
				T value;
				for (int i = 0; i < size.i; i++)
				{
					std::vector<T>* temp = new std::vector<T>();
					for (int j = 0; j < size.j; j++)
					{
						std::cin >>  value;
						temp->push_back(value);
					}
					this->matrix->AddNewNode(temp);
				}
				break;
			}
		}
		~MatrixByListByVectors()
		{
			CyclicList::List<std::vector<T>*>::template Node* iterForMatrix1 = this->matrix->GetTail();
			CyclicList::List<std::vector<T>*>::template Node* iterForMatrix2 = iterForMatrix1->prev;
			for (int i = 0; i < this->size.i - 2; i++)
			{
				delete (iterForMatrix1->data);
				delete (iterForMatrix1);
				iterForMatrix1 = iterForMatrix2;
				iterForMatrix2 = iterForMatrix2->prev;
			}
			delete (iterForMatrix1);
			delete (iterForMatrix2);
		}

		void PrintVectorValues(std::vector<T>* v)
		{
			for (int j = 0; j < this->size.j; j++)
			{
				std::cout << (*v)[j] << " ";
			}

			std::cout << std::endl;
		}
		CyclicList::ID GetSize()
		{
			return this->size;
		}
		void SetSize(CyclicList::ID size)
		{
			this->size = size;
		}
		void PrintMatrix()
		{
			CyclicList::List<std::vector<T>*>::template Node* iter = this->matrix->GetTail();

			while (iter != this->matrix->GetHead())
			{
				PrintVectorValues(iter->data);

				iter = iter->prev;
			}

			PrintVectorValues(iter->data);
		}

		T GetValueByIndexMatrix(CyclicList::ID position)
		{
			if (this->size.i >= position.i && this->size.j >= position.j)
			{
				if (position.i - this->matrix->GetTail()->index < this->matrix->GetHead()->index - position.j)
				{
					CyclicList::List<std::vector<T>*>::template Node* iter = this->matrix->GetTail();
					while (iter->index != position.i - 1)
						iter = iter->prev;

					return (*iter->data)[position.j - 1];
				}
				else
				{
					CyclicList::List<std::vector<T>*>::template Node* iter = this->matrix->GetHead();
					while (iter->index != position.i - 1)
						iter = iter->next;

					return (*iter->data)[position.j - 1];
				}
			}
			else
			{
				std::cout << "out of range: i = " << this->size.i << "  j = " << this->size.j << std::endl;
				return (T)NULL;
			}
		}
		std::vector<CyclicList::ID> GetIndexesByValueMatrix(T value)
		{
			CyclicList::List<std::vector<T>*>::template Node* iter = this->matrix->GetTail();
			std::vector<CyclicList::ID> vector;

			for (int j = 0; j < this->size.j; j++)
			{
				if ((*iter->data)[j] == value)
				{
					vector.push_back({ (*iter).index, j });
				}
			}

			while (iter != this->matrix->GetHead())
			{
				iter = iter->prev;

				for (int j = 0; j < this->size.j; j++)
				{
					if ((*iter->data)[j] == value)
					{
						vector.push_back({ (*iter).index, j });
					}
				}
			}
			return vector;
		}
		T GetFirstValueByConditionMatrix()
		{
			int answer = Condition();

			T value;
			T returnedValue = NULL;

			CyclicList::List<std::vector<T>*>::template Node* iter = this->matrix->GetTail();

			std::cout << "Enter value:" << std::endl;
			std::cin >> value;

			switch (answer)
			{
			case 1:
				for (int i = 0; i < this->size.i; i++)
				{
					for (int j = 0; j < this->size.j; j++)
					{
						if ((*iter->data)[j] < value)
						{
							returnedValue = (*iter->data)[j];
							return returnedValue;
						}
					}
					iter = iter->prev;
				}
				return returnedValue;

			case 2:
				for (int i = 0; i < this->size.i; i++)
				{
					for (int j = 0; j < this->size.j; j++)
					{
						if ((*iter->data)[j] > value)
						{
							returnedValue = (*iter->data)[j];
							return returnedValue;
						}
					}
					iter = iter->prev;
				}
				return returnedValue;

			case 3:
				for (int i = 0; i < size.i; i++)
				{
					for (int j = 0; j < size.j; j++)
					{
						if ((*iter->data)[j] = value)
						{
							returnedValue = (*iter->data)[j];
							return returnedValue;
						}
					}
					iter = iter->prev;
				}
				return returnedValue;
			}
		}

		MatrixByListByVectors<T>* SumMatrix(MatrixByListByVectors<T>* m2)
		{
			MatrixByListByVectors<T>* answer = new MatrixByListByVectors<T>();
			answer->SetSize({this->size.i, this->size.j});
			CyclicList::List<std::vector<T>*>::template Node* iterForMatrix1 = this->matrix->GetTail();
			CyclicList::List<std::vector<T>*>::template Node* iterForMatrix2 = m2->matrix->GetTail();

			for (int i = 0; i < this->size.i; i++)
			{
				std::vector<T>* temp = new std::vector<T>();

				for (int j = 0; j < this->size.j; j++)
				{
					temp->push_back(((*iterForMatrix1->data)[j] + (*iterForMatrix2->data)[j]));
				}
				answer->matrix->AddNewNode(temp);
				iterForMatrix1 = iterForMatrix1->prev;
				iterForMatrix2 = iterForMatrix2->prev;
			}
			return answer;
		}
		MatrixByListByVectors<T>* MultiplyMatrices(MatrixByListByVectors<T>* m2)
		{
			MatrixByListByVectors<T>* answer = new MatrixByListByVectors<T>({ this->size.i,m2->size.j });

			if (this->size.j == m2->size.i)
			{
				CyclicList::List<std::vector<T>*>::template Node* iterAnswer = answer->matrix->GetTail();
				CyclicList::List<std::vector<T>*>::template Node* iter1 = this->matrix->GetTail();
				CyclicList::List<std::vector<T>*>::template Node* iter2 = m2->matrix->GetTail();

				for (int k = 0; k <this->size.i; k++)
				{
					for (int j = 0; j < m2->size.j; j++)
					{
						for (int i = 0; i < m2->size.i; i++)
						{
							(*iterAnswer->data)[j] += (*iter1->data)[i] * (*iter2->data)[j];
							iter2 = iter2->prev;
						}
					}
					iter1 = iter1->prev;
					iterAnswer = iterAnswer->prev;
				}
			}
			return answer;
		}
		MatrixByListByVectors<T>* MatrixTransposition()
		{
			MatrixByListByVectors<T>* answer = new MatrixByListByVectors<T>({this->size.j, this->size.i});
			CyclicList::List<std::vector<T>*>::template Node* iter1 = this->matrix->GetTail();
			CyclicList::List<std::vector<T>*>::template Node* iter2 = answer->matrix->GetTail();
			for (int i = 0; i < answer->size.i; i++)
			{
				for (int j = 0; j < answer->size.j; j++)
				{
					(*iter2->data)[j] = (*iter1->data)[i];
					iter1 = iter1->prev;
				}
				iter2 = iter2->prev;
			}
			return answer;
		}
	};

	template <class T>
	class ArrayMatrix
	{
	private:
		T** matrix;
		CyclicList::ID size;
	public:
		ArrayMatrix(CyclicList::ID size)
		{
			this->size = size;
			T** temp = new T * [size.i];
			for (int i = 0; i < size.i; i++)
			{
				temp[i] = new T[size.j];
				for (int j = 0; j < this->size.j; j++)
				{
					temp[i][j] = NULL;
				}
			}

			this->matrix = temp;
		}
		ArrayMatrix(CyclicList::ID size, int answer)
		{
			this->size = size;
			T** temp = new T * [size.i];

			switch (answer)
			{
			case 0 :
				srand(time(0));

				for (int i = 0; i < size.i; i++)
				{
					temp[i] = new T[size.j];

					for (int j = 0; j < this->size.j; j++)
					{
						temp[i][j] = (T)((rand() % 10) / 7);
					}
				}

				this->matrix = temp;
				break;
			case 1:
				T value;

				for (int i = 0; i < size.i; i++)
				{
					temp[i] = new T[size.j];

					for (int j = 0; j < this->size.j; j++)
					{
						std::cin >> value;

						temp[i][j] = value;
					}
				}

				this->matrix = temp;
				break;
			}
		}
		~ArrayMatrix()
		{
			for (int i = 0; i < this->size.i; i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;
		}

		void PrintMatrix()
		{
			for (int i = 0; i < this->size.i; i++)
			{
				for (int j = 0; j < this->size.j; j++)
				{
					std::cout << this->matrix[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}
		CyclicList::ID GetSize()
		{
			return this->size;
		}

		T GetValueByIndexMatrix(CyclicList::ID index)
		{
			if (this->size.i >= index.i && this->size.j >= index.j)
				return this->matrix[index.i - 1][index.j - 1];

			else
				std::cout << "out of range: i = "<< this->size.i << "  j = " << this->size.j << std::endl;
			return (T)NULL;
		}
		T GetFirstValueByConditionMatrix()
		{
			int answer = Condition();
			T userValue;
			std::cin >> userValue;

			switch (answer)
			{
			case 1:
				for (int i = 0; i < this->size.i; i++)
				{
					for (int j = 0; j < this->size.j; j++)
					{
						if (this->matrix[i][j] < userValue)
						{
							return this->matrix[i][j];
						}
					}
				}
				return NULL;
			
			case 2:
				for (int i = 0; i < this->size.i; i++)
				{
					for (int j = 0; j < this->size.j; j++)
					{
						if (this->matrix[i][j] > userValue)
						{
							return this->matrix[i][j];
						}
					}
				}
				
				return NULL;
			case 3:
				for (int i = 0; i < this->size.i; i++)
				{
					for (int j = 0; j < this->size.j; j++)
					{
						if (this->matrix[i][j] == userValue)
						{
							return this->matrix[i][j];
						}
					}
				}
				return NULL;
			}
		}
		std::vector<CyclicList::ID> GetIndexesByValueMatrix(T value)
		{
			std::vector<CyclicList::ID> v;
			for (int i = 0; i < this->size.i; i++)
			{
				for (int j = 0; j < this->size.j; j++)
				{
					if (this->matrix[i][j] == value)
					{
						v.push_back({ i,j });
					}
				}
			}
			return v;
		}

		ArrayMatrix<T>* SumMatrix(ArrayMatrix<T>* m2)
		{
			ArrayMatrix<T>* answer = new ArrayMatrix<T>(this->size);

			for (int i = 0; i < this->size.i; i++)
			{
				for (int j = 0; j < this->size.j; j++)
				{
					answer->matrix[i][j] = this->matrix[i][j] + (*m2).matrix[i][j];
				}
			}

			return answer;
		}
		ArrayMatrix<T>* MultiplyMatrices(ArrayMatrix<T>* m2)
		{
			ArrayMatrix<T>* answer = new ArrayMatrix<T>({ this->size.i, m2->size.j});
			
			if (this->size.j == m2->size.i)
			{
				for (int k = 0; k < m2->size.j; k++)
				{
					for (int i = 0; i < this->size.i; i++)
					{
						for (int j = 0; j < this->size.j; j++)
						{
							answer->matrix[i][k] += (this->matrix[i][j] * m2->matrix[j][k]);
						}
					}
				}
			}
			else
			{
				std::cout << "Wrong size( " << std::endl;
			}
			return answer;
		}
		ArrayMatrix<T>* MatrixTransposition()
		{
			ArrayMatrix<T>* answer = new ArrayMatrix<T>({ this->size.j, this->size.i });
			for (int i = 0; i < answer->size.i; i++)
			{
				for (int j = 0; j < answer->size.j; j++)
				{
					answer->matrix[i][j] = this->matrix[j][i];
				}
			}

			return answer;
		}
	};
}