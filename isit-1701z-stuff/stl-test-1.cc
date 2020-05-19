/*
 * stl-test-1.cc
 *
 *  Created on: 19 мая 2020 г.
 *      Author: unyuu
 */

#include <iostream>

#include <cstdlib>

int cmp_ints(const void * a, const void * b)
{
	int aa = *reinterpret_cast<const int *>(a);
	int bb = *reinterpret_cast<const int *>(b);
	if (aa > bb) return 1;
	else if (bb > aa) return -1;
	else return 0;
}

int main()
{
	int * arr;
	unsigned qty;

	std::cout << "Введите количество чисел: ";
	std::cin >> qty;

	arr = new int[qty];



	for (unsigned i = 0; i < qty; i++) {
		std::cout << "Введите элемент " << i << ": ";
		std::cin >> arr[i];
	}

//	for (unsigned i = 0; i < qty-1; i++)
//		for (unsigned j = i+1; j < qty; j++) {
//			if (arr[j] < arr[i]) {
//				auto tmp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = tmp;
//			}
//		}
	qsort(arr, qty, sizeof(int), cmp_ints);

	std::cout << "Отсортированный массив:" << std::endl;
	for (unsigned i = 0; i < qty; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;

	delete[] arr;

	return 0;
}


