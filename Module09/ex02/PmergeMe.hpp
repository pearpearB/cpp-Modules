#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iterator>

enum crit {CRTR = 15};

class PmergeMe
{
	private:
		void insertSort(std::vector<int> &numbers, int left, int right);
		void mergeSort(std::vector<int> &numbers, int left, int mid, int right);
		void insertSort(std::list<int>::iterator left, std::list<int>::iterator right);
		void mergeSort(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right);
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &ref);
		PmergeMe& operator=(const PmergeMe &ref);
		~PmergeMe();

		void mergeInsertSort(std::vector<int> &numbers, int left, int right);
		void mergeInsertSort(std::list<int> &numbers, std::list<int>::iterator left, std::list<int>::iterator right);
};

#endif