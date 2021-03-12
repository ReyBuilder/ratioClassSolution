#include <iostream>
#include "Ratio.h"

Ratio operator*(const int value, const Ratio ratio) {
    return ratio * value;
}

int main()
{
    Ratio r(-1, 3);
    Ratio r2(-34, 51);
    std::cout << "Ratio1" << std::endl << r << std::endl;
    std::cout << "Ratio2" << std::endl << r2 << std::endl;
    std::cout << "Ratio1 + Ratio2" << std::endl << (r + r2) << std::endl;
    std::cout << "Ratio1 + int" << std::endl << (r * 2) << std::endl;
    std::cout << "Ratio1 * Ratio2" << std::endl << (r * r2) << std::endl;
    std::cout << "int * Ratio2" << std::endl << (2 * r2) << std::endl;
}