#include <iostream>
#include "Matrix.h"

int main()
{
    AllMatrix::ArrayMatrix<int>* m = new AllMatrix::ArrayMatrix<int>({5,3},0);
    m->PrintMatrix();
    std::cout << std::endl;
    std::cout << m->GetValueByIndexMatrix({ 3,2 });
    std::cout << std::endl;
    std::cout << m->GetFirstValueByConditionMatrix();
    std::cout << std::endl;
    std::vector<CyclicList::ID> v = m->GetIndexesByValueMatrix(0);

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i].i << " " << v[i].j << '\t';
    }
}
