#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double EPS = 0.0001;

int main()
{
    double start, end, step;
    std::cout << "Введите начало промежутка: "; std::cin >> start;
    std::cout << "Введите конец промежутка : "; std::cin >> end;
    std::cout << "Введите шаг              : "; std::cin >> step;
    std::cout << std::endl;

    std::cout <<
        "    x   | sin(x) | cos(x) | tan(x) " << std::endl <<
        "--------+--------+--------+--------" << std::endl;
    for (double x = start; x <= end; x += step) {
        std::cout <<
            std::fixed <<
            std::setw(8) << std::setprecision(3) << x << '|' <<
            std::setprecision(4) <<
            std::setw(8) << sin(x) << '|' <<
            std::setw(8) << cos(x) << '|' <<
            std::setw(8) << tan(x) << std::endl;

    }


	return 0;
}

