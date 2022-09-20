#pragma once
#include <iostream>
#include <vector>
#include "Utilits.h"

namespace CyclicList
{
    struct ID
    {
        int i;
        int j;
    };

    template <typename T>
    class List
    {
    public:
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
    protected:
        Node* head;
        Node* tail;
    public:
        List()
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        List(int size, int answer)
        {
            srand(time(0));

            this->head = nullptr;
            this->tail = nullptr;

            switch (answer)
            {
            case 0:
                for (int i = 0; i < size; i++)
                {
                    AddNewNode(T(rand() % 7) / 5);
                }
                break;
            case 1:
                for (int i = 0; i < size; i++)
                {
                    int num;
                    std::cin >> num;

                    AddNewNode(num);
                }
            }
        }
        ~List()
        {
            Node* iter1 = this->head;
            Node* iter2 = this->head->next;

            while (iter2 != this->tail)
            {
                delete iter1;
                iter1 = iter2;
                iter2 = iter2->next;
            }

            delete iter1;
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

        Node* GetTail()
        {
            return this->tail;
        }

        Node* GetHead()
        {
            return this->head;
        }

        List<T>* Sum(List<T>* l2, int size)
        {
            T sum;
            List<T>* l3 = new List<T>();
            Node* iter = this->tail;
            Node* iter2 = (*l2).tail;

            for (int i = 0; i < size; i++)
            {
                sum = iter->data + iter2->data;
                l3->AddNewNode(sum);
                iter = iter->prev;
                iter2 = iter2->prev;
            }

            return l3;
        }

        T GetValueByIndex(int index)                 ////// O(n)
        {
            if ((index - tail->index) <= (head->index - index))
            {
                Node* iter = this->tail;

                while (iter->index != index)
                {
                    if (iter == this->head)
                    {
                        std::cout << "This index are not in the list" << std::endl;
                        return NULL;
                    }

                    iter = iter->prev;
                }
                return iter->data;
            }

            else
            {
                Node* iter = this->head;

                while (iter->index != index)
                {
                    if (iter == this->tail)
                    {
                        std::cout << "This index are not in the list" << std::endl;
                        return NULL;
                    }

                    iter = iter->next;
                }
                return iter->data;
            }
        }
        std::vector<int> GetIndexByValue(T value)         /////O(n)
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
            return indexes;
        }
        T GetFirstValueByCondition() // O(n)
        {
            int answer = Condition();
            Node* iter = this->tail;
            int value;

            switch (answer)
            {
            case 1:
                std::cout << "Enter value:" << std::endl;
                std::cin >> value;

                while (iter->data > value && iter != this->head)
                {
                    iter = iter->prev;
                }

                if (iter->data > value)
                {
                    std::cout << "value not found" << std::endl;
                    return NULL;
                }
                else
                {
                    return value;
                }
            case 2:
                std::cout << "Enter value:" << std::endl;
                std::cin >> value;

                while (iter->data < value && iter != this->head)
                {
                    iter = iter->prev;
                }

                if (iter->data < value)
                {
                    std::cout << "value not found" << std::endl;
                    return NULL;
                }
                else
                {
                    return value;
                }
            case 3:

                std::cout << "Enter value:" << std::endl;
                std::cin >> value;

                while (iter->data != value && iter != this->head)
                {
                    iter = iter->prev;
                }

                if (iter->data == value)
                {
                    std::cout << "value not found" << std::endl;
                    return NULL;
                }
                else
                {
                    return value;
                }
            }
        }
    };
}