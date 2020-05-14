#include <iostream>
#include <cmath>

constexpr double EPS = 0.0001;

int main()
{
    double a, b, c;

    std::cout << "Решаем уравнение вида ax^2+bx+c=0" << std::endl;
    std::cout << "Введите коэффициенты квадратного уравнения: ";
    std::cin >> a >> b >> c;

    double d = b * b - 4 * a * c;

    if ( d >= EPS) { // d > 0
        std::cout << "x1 == " << ((-b - sqrt(d)) / 2. / a) << std::endl;
        std::cout << "x2 == " << ((-b + sqrt(d)) / 2. / a) << std::endl;
    } else if ( d >= -EPS and d < EPS) { // d == 0
        std::cout << "x == " << (-b / 2. / a) << std::endl;
    } else { // d < 0
        std::cout << "Действительных корней нет!" << std::endl;
    }

	return 0;
}

