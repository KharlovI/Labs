#pragma once
#include<iostream>

inline int Condition()
{
    std::cout << "choose condition:" << std::endl;
    std::cout << "0)Exit  1) less than   2) more than  3)is equal to" << std::endl;

    int answer;
    std::cin >> answer;

    while (answer > 3 || answer < 0)
    {
        std::cout << "Pleas, choose correct answer:" << std::endl;
        std::cin >> answer;
    }

    return answer;
}
inline void ShowOptions()
{
    std::cout << "0)Exit    1)Print matrix       2)Find value by index   3)Find index by value   4)Find first value by condition" << std::endl;
    std::cout << "          5)Sum two matrices   6)Multiply matrices     7)Transpose matrix" << std::endl;
}
inline int Answer()
{
    int answer;
    std::cout << "If you want to generate random values enter (0), else - (1)" << std::endl;
    std::cin >> answer;

    while (answer > 1 || answer < 0)
    {
        std::cout << "Choose 0 or 1" << std::endl;
        std::cin >> answer;
    }

    return answer;
}