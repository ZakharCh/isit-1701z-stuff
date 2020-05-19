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
	unsigned qty;

	std::cout << "Введите количество чисел: ";
	std::cin >> qty;

	arr.resize(qty);

	unsigned idx = 0;
	for (auto && i : arr) {
		std::cout << "Введите элемент " << idx++ << ": ";
		std::cin >> i;
	}
	std::sort(arr.begin(), arr.end());
	std::cout << "Отсортированный массив:" << std::endl;
	for (auto && i : arr)
		std::cout << i << ' ';

	std::cout << std::endl;

	return 0;
}


