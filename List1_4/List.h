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

                next = nullptr;
                prev = nullptr;
            }
     
        };
    protected:
        Node* head;
        Node* tail;
    public:
        List()
        {
            head = nullptr;
            tail = nullptr;
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
            head = nullptr;
            tail = nullptr;
            switch (answer)
            {
            case 0:
                for (int i = 0; i < size; i++)
                {
                    T randValue;
                    randValue = ((rand() % 7) / 5) * (rand() % 100);
                    T temp = randValue;
                    AddNewNode(temp);
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
        ~List()
        {
           Node* temp;
           while (tail != head)
           {
               temp = tail->prev;
               delete tail;
               tail = temp;
           }
           delete tail;
        }

        void AddNewNode(T data)                        ////// O(1)
        {
            Node* temp = new Node(data);

            if (head == nullptr)
            {
                head = temp;
                tail = temp;

                head->prev = tail;
                tail->next = head;
            }

            else
            {
                head->prev = temp;
                temp->next = head;
                head = temp;

                tail->next = head;
                head->prev = tail;

                head->index = head->next->index + 1;
            }
        }
        void Print()                        //////// O(n)
        {
            Node* iter = tail;

            while (iter != head)
            {
                std::cout << iter->data << " ";

                iter = iter->prev;
            }

            std::cout << iter->data;
        }

        Node* GetTail()
        {
            return tail;
        }
        Node* GetHead()
        {
            return head;
        }

        List<T>* Sum(List<T>* l2, int size)
        {
            List<T>* l3 = new List<T>();
            Node* iter = tail;
            Node* iter2 = l2->tail;

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
            T null;
            null = NULL;

            if ((index - tail->index) <= (head->index - index))
            {
                Node* iter = tail;

                while (iter->index != index)
                {
                    if (iter == head)
                    {
                        std::cout << "This index are not in the list" << std::endl;
                        return null;
                    }

                    iter = iter->prev;
                }
                return iter->data;
            }

            else
            {
                Node* iter = head;

                while (iter->index != index)
                {
                    if (iter == tail)
                    {
                        std::cout << "This index are not in the list" << std::endl;
                        return null;
                    }

                    iter = iter->next;
                }
                return iter->data;
            }
        }
        std::vector<int> GetIndexByValue(T value)         /////O(n)
        {
            std::vector <int> indexes;
            Node* iter = tail;

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
            T null;
            null = NULL;

            Node* iter = tail;
            switch (answer)
            {
            case 1:
                for (int i = 0; i < (head->index + 1); i++)
                {
                    if(iter->data < value)
                        return iter->data;
                    iter = iter->prev;
                }
                return null;
            case 2:
                for (int i = 0; i < (head->index + 1); i++)
                {
                    if (iter->data > value)
                        return iter->data;
                    iter = iter->prev;
                }
                return null;
            case 3:
                for (int i = 0; i < (head->index + 1); i++)
                {
                    if (iter->data == value)
                        return iter->data;
                    iter = iter->prev;
                }
                return null;
            }
        }
    };
}