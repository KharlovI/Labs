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

		MatrixByList(CyclicList::ID size, int answer)
		{
			this->size = size;

			for (int i = 0; i < size.i; i++)
			{
				CyclicList::List<T>* temp = new CyclicList::List<T>(size.j, answer);

				this->matrix->AddNewNode(temp);
			}
		}

		void PrintMatrix()
		{
			for (int i = 0; i < this->size.i; i++)
			{
				CyclicList::List<CyclicList::List<T>*>::template Node* iter = this->matrix->GetTail();
				iter->data->Print();
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		T GetValueByIndexMatrix(CyclicList::ID position)
		{
			CyclicList::List<CyclicList::List<T>*>::template Node* iter = this->matrix->GetTail();

			while (iter->index != position.i)
			{
				iter = iter->prev;
			}
			return (iter->data->GetValueByIndex(position.j));
		}

		std::vector<CyclicList::ID> GetIndexesByValueMatrix(T value)
		{
			std::vector<CyclicList::ID> temp;
			CyclicList::List<std::vector<T>*>::template Node* iter = this->matrix->GetTail;

			for (int i = 0; i < this->size.i; i++)
			{
				std::vector<int> intTemp;

				intTemp = iter->data.GetIndexByValue((T)value);

				for (int j = 0; j < intTemp.capacity(); j++)
				{
					temp.push_back({ i,intTemp[j] });
				}

				iter = iter->prev;
			}

			return temp;
		}

		T GetFirstValueByConditionMatrix()
		{
			CyclicList::List<CyclicList::List<T>*>::template Node* iter = this->matrix->GetTail();
			T answer = iter->data->GetFirstValueBycondition();

			while (answer == NULL && iter != this->matrix->GetHead())
			{
				iter = iter->prev;
				answer = iter->data->GetFirstValueBycondition();
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
						temp->push_back((rand() % 5 / 3));
					}

					this->matrix->AddNewNode(temp);
				}

				break;
			case 1:
				int value;
				for (int i = 0; i < size.i; i++)
				{
					std::vector<T>* temp = new std::vector<T>();
					for (int j = 0; j < size.j; j++)
					{
						std::cin >> value;
						temp->push_back(value);
					}
					this->matrix->AddNewNode(temp);
				}
				break;
			}
		}

		~MatrixByListByVectors()
		{
			for (int i = 0; i < this->size.i; i++)
			{
				delete this->matrix->GetValueByIndex(i)->data;
			}
		}

		void PrintVectorValues(std::vector<T>* v)
		{
			for (int j = 0; j < this->size.j; j++)
			{
				std::cout << (*v)[j] << " ";
			}

			std::cout << std::endl;
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
			if (position.i - this->matrix->GetTail()->index < this->matrix->GetHead()->index - position.j)
			{
				CyclicList::List<std::vector<T>*>::template Node* iter = this->matrix->GetTail();
				while (iter->index != position.i)
					iter = iter->prev;

				return (*iter->data)[position.j];
			}
			else
			{
				CyclicList::List<std::vector<T>*>::template Node* iter = this->matrix->GetHead();
				while (iter->index != position.i)
					iter = iter->next;

				return (*iter->data)[position.j];
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
	};

	template <class T>
	class ArrayMatrix
	{
	private:
		T** matrix;
		CyclicList::ID size;
	public:
		ArrayMatrix(CyclicList::ID size, int answer) // 0 - randValues 1 - cin
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
						temp[i][j] = (rand() % 10) / 7; // 7/10 - NULL
					}
				}

				this->matrix = temp;
				break;
			case 1:
				int value;

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
			for (int i = 0; i < this->size; i++)
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

		T GetValueByIndexMatrix(CyclicList::ID index)
		{
			return this->matrix[index.i][index.j];
		}

		T GetFirstValueByConditionMatrix()
		{
			int answer = Condition(); // 1 - <		2 -	>		 3	 ==
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
	};
}