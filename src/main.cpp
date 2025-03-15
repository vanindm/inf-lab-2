#include <iostream>
#include "PATypes/DynamicArray.hpp"

int main()
{
    PATypes::DynamicArray<int> array(new int[]{1, 2, 3}, 3);
    for (int i = 0; i < 3; ++i)
    {
        std::cout << array.get(i) << " ";
    }
    return 0;
}
