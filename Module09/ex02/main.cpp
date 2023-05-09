#include <iostream>
#include <iomanip>
#include "PmergeMe.hpp"

bool isValidNumber(const char* end, int number) {
	if (*end != '\0')
		return false;
	if (number > INT_MAX || number <= 0)
		return false;

	return true;
}

template <typename T>
void addNumbersToContainer(int argc, char* argv[], T& container) {
	for (int i = 1; i < argc; i++) {
		char *end;
		long number = strtol(argv[i], &end, 10);

		if (!isValidNumber(end, number)) {
			std::cout << "Error: Invalid number" << std::endl;
			exit(EXIT_FAILURE);
		} else {
			container.push_back(number);
		}
	}
}

template <typename T>
void display(const T& container)
{
	typename T::const_iterator it;
	for (it = container.begin() ; it != container.end(); it++)
	{
		std::cout << *it << " ";
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "[Usage]: ./PmergeMe at least two parameters." << std::endl;
		exit (EXIT_FAILURE);
	}

	PmergeMe pMergeMe;
	std::vector<int> original;
	std::vector<int> vNumbers;
	std::list<int> lNumbers;

	clock_t vStart = clock();
	addNumbersToContainer(argc, argv, vNumbers);
	pMergeMe.mergeInsertSort(vNumbers, 0, vNumbers.size() - 1);
	clock_t vEnd = clock();

	clock_t lStart = clock();
	addNumbersToContainer(argc, argv, lNumbers);
	pMergeMe.mergeInsertSort(lNumbers, lNumbers.begin(), lNumbers.end());
	clock_t lEnd = clock();

	addNumbersToContainer(argc, argv, original);
	std::cout << "Before: "; display(original); std::cout << std::endl;
	std::cout << "After: "; display(vNumbers); std::cout << std::endl;

	double vectorTime = static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC;
	double listTime = static_cast<double>(lEnd - lStart) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vNumbers.size() << " elements with std::vector: " << std::fixed << std::setprecision(6) << vectorTime << " s" << std::endl;
	std::cout << "Time to process a range of " << lNumbers.size() << " elements with std::list: " << std::fixed << std::setprecision(6) << listTime << " s" << std::endl;

	return 0;
}