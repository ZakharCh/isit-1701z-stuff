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

	for (unsigned i = 0; i < qty; i++) {
		std::cout << "Введите элемент " << i << ": ";
		std::cin >> arr[i];
	}

	std::sort(arr.begin(), arr.end());

	std::cout << "Отсортированный массив:" << std::endl;
	for (unsigned i = 0; i < qty; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;

	return 0;
}


