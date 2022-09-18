#pragma once
#include <iostream>
#include <vector>
namespace CyclicList
{
    template <typename T>
    class List
    {
    protected:
        struct Node
        {
            T data;

            int index;

            Node* next;
            Node* prev;

            Node(T data)
            {
                this->data = data;
                this->index = 0;

                this->next = nullptr;
                this->prev = nullptr;
            }
        };

        Node* head;
        Node* tail;
    public:
        List()
        {
            this->head = nullptr;
            this->tail = nullptr;
        }

        List(int size) // ? 
        {
            srand(time(0));

            this->head = nullptr;
            this->tail = nullptr;

            //int value;

            for (int i = 0; i < size; i++)
            {
                /* std::cin >> value;

                 AddNewNode(value);*/
                AddNewNode(T(rand() % 5) / 4);
            }
        }

        ~List()
        {
            Node* iter1 = this->head;
            Node* iter2 = this->head->next;

            while (iter2 != nullptr)
            {
                delete iter1;
                iter1 = iter2;
                iter2 = iter2->next;
            }

            delete iter2;
        }

        void AddNewNode(T data)                        ////// O(1)
        {
            Node* temp = new Node(data);

            if (this->head == nullptr)
            {
                this->head = temp;
                this->tail = temp;

                this->head->prev = this->tail;
                this->tail->next = this->head;
            }

            else
            {
                this->head->prev = temp;
                temp->next = this->head;
                this->head = temp;

                this->tail->next = this->head;
                this->head->prev = this->tail;

                this->head->index = this->head->next->index + 1;
            }
        }

        void Print()                        //////// O(n)
        {
            Node* iter = this->tail;

            while (iter != this->head)
            {
                std::cout << iter->data << " ";

                iter = iter->prev;
            }

            std::cout << iter->data;
        }

        Node* GetNodeByIndex(int index)                 ////// O(n)
        {
            if ((index - tail->index) <= (head->index - index))
            {
                Node* iter = this->tail;

                while (iter->index != index)
                {
                    if (iter == this->head)
                    {
                        std::cout << "This index are not in the list" << std::endl;
                        return nullptr;
                    }

                    iter = iter->prev;
                }
                return iter;
            }

            else
            {
                Node* iter = this->head;

                while (iter->index != index)
                {
                    if (iter == this->tail)
                    {
                        std::cout << "This index are not in the list" << std::endl;
                        return nullptr;
                    }

                    iter = iter->next;
                }
                return iter;
            }
        }

        std::vector<int> GetIndexByValue(int value)         /////O(n)
        {
            std::vector <int> indexes;
            Node* iter = this->tail;

            for (int i = 0; i < this->head->index; i++, iter = iter->prev)
            {
                if (iter->data == value)
                {
                    indexes.push_back(iter->index);
                }
            }

            if (indexes.empty())
            {
                std::cout << "This list does not contain this value" << std::endl;
            }

            return indexes;
        }
    };
}