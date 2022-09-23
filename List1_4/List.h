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
        List(int size)
        {
            this->head = nullptr;
            this->tail = nullptr;
            for (int i = 0; i < size; i++)
            {
                AddNewNode(NULL);
            }
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
                    AddNewNode(T((rand() % 7) / 5));
                }
                break;
            case 1:
                for (int i = 0; i < size; i++)
                {
                    T num;
                    std::cin >> num;

                    AddNewNode(num);
                }
            }
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
            List<T>* l3 = new List<T>();
            Node* iter = this->tail;
            Node* iter2 = (*l2).tail;

            for (int i = 0; i < size; i++)
            {
                l3->AddNewNode(iter->data + iter2->data);
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
        T GetFirstValueByCondition(int answer, T value) // O(n)
        {
            Node* iter = this->tail;
            switch (answer)
            {
            case 1:
                for (int i = 0; i < (this->head->index + 1); i++)
                {
                    if(iter->data < value)
                        return iter->data;
                    iter = iter->prev;
                }
                return T(NULL);
            case 2:
                for (int i = 0; i < (this->head->index + 1); i++)
                {
                    if (iter->data > value)
                        return iter->data;
                    iter = iter->prev;
                }
                return T(NULL);
            case 3:
                for (int i = 0; i < (this->head->index + 1); i++)
                {
                    if (iter->data == value)
                        return iter->data;
                    iter = iter->prev;
                }
                return T(NULL);
            }
        }
    };
}