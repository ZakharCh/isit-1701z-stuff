#include <iostream>

int main()
{
    int a, b, c;

    std::cout << "Введите два целых числа: ";
    std::cin >> a >> b;

    c = a + b;

    std::cout << "Сумма чисел " << a << " и " << b << " равна " << c
        << std::endl;

	return 0;
}

