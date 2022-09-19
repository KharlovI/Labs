#pragma once
#include<iostream>

int Condition()
{
    std::cout << "choose condition:" << std::endl;
    std::cout << "1) less than   2) more than  3)is equal to" << std::endl;

    int answer;
    std::cin >> answer;

    while (answer > 3 || answer < 1)
    {
        std::cout << "Pleas, choose correct answer:" << std::endl;
        std::cin >> answer;
    }

    return answer;
}
