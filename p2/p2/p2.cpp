#include "p2.h"
#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> copyVecFast1(const std::vector<int>& original)
{
	std::vector<int> newVec;
	newVec.reserve(original.size());
	std::copy(original.begin(), original.end(), std::back_inserter(newVec));
	return newVec;
}

std::vector<int> copyVecFast2(std::vector<int>& original)
{
	std::vector<int> newVec;
	newVec.swap(original);
	return newVec;
}

int main()
{
	std::vector<int> vectori;
	int n = 1e5;
	for (int i = 0; i < n; i++) {
		vectori.push_back(i);
	}

	std::vector<int> vectoro;
	unsigned int start_time = clock();
	vectoro = copyVecFast1(vectori);
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время

	
	std::vector<int> vectoro_2;
	unsigned int start_time_2 = clock();
	vectoro_2 = copyVecFast2(vectori);
	unsigned int end_time_2 = clock(); // конечное время
	unsigned int search_time_2 = end_time_2 - start_time_2; // искомое время

	std::cout << search_time << std::endl;
	std::cout << search_time_2 << std::endl;


}
