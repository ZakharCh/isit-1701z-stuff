/*
 * stl-test-1.cc
 *
 *  Created on: 19 мая 2020 г.
 *      Author: unyuu
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> arr;

	std::cout << "Вводите элементы, Ctrl-D - конец." << std::endl;
	unsigned idx = 0, val;

	for(;;) {
		std::cout << "Введите элемент " << idx++ << ": ";
		std::cin >> val;
		if ( std::cin.good() ) { arr.push_back(val); continue; }
		break;
	}
	std::cout << "Введено " << arr.size() << " чисел." << std::endl;
	std::sort(arr.begin(), arr.end());
	std::cout << "Отсортированный массив:" << std::endl;
	for (auto && i : arr)
		std::cout << i << ' ';

	std::cout << std::endl;

	return 0;
}


