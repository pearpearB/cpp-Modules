#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &ref) {
	*this = ref;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &ref) {
	(void)ref;
	return *this;
}

void PmergeMe::insertSort(std::vector<int> &numbers, int left, int right) {
	int i, j, key;

	for (i = left + 1; i <= right; i++) {
		key = numbers[i];	// 삽입할 값, 두번째 요소부터 시작
		j = i - 1;				// 삽입할 위치, 삽입할 값의 앞부터 앞으로 전진
		while (j >= left && numbers[j] > key) {
			numbers[j + 1] = numbers[j]; // 삽입할 값보다 큰 값은 뒤로 밀어냄
			j = j - 1;
		}
		numbers[j + 1] = key;
	}
}

void PmergeMe::mergeSort(std::vector<int> &numbers, int left, int mid, int right) {
	std::vector<int> temp;
	int i = left;			// pivot1
	int j = mid + 1;	// pivot2

	/* 앞에서부터 비교하며 작은 것 넣어주기 */
	while (i <= mid && j <= right) {
		if (numbers[i] <= numbers[j]) {
			temp.push_back(numbers[i]);
			i++;
		} else {
			temp.push_back(numbers[j]);
			j++;
		}
	}
	/* 한쪽 남은 요소 넣어주기 */
	while (i <= mid) {
		temp.push_back(numbers[i]);
		i++;
	}
	while (j <= right) {
		temp.push_back(numbers[j]);
		j++;
	}
	/* 왼쪽부터 정렬된 temp의 값 차례로 삽입 */
	for (int k = left; k <= right; k++) {
		numbers[k] = temp[k - left];
	}
}

void PmergeMe::mergeInsertSort(std::vector<int> &numbers, int left, int right) {
	if (right - left + 1 <= CRTR) {
		insertSort(numbers, left, right);
	} else {
		if (left < right) {
			int mid = left + (right - left) / 2;
			mergeInsertSort(numbers, left, mid);
			mergeInsertSort(numbers, mid + 1, right);
	
			mergeSort(numbers, left, mid, right);
		}
	}
}

/* 내부 로직이 복잡해 보일 수 있지만, swap과정임! 
iterator는 배열처럼 인덱스로 바로 접근할 수 없기 때문에 itNextNumber로 위치를 잡고 iterator 이동으로 위치를 찾아 swap*/
void PmergeMe::insertSort(std::list<int>::iterator itLeft, std::list<int>::iterator itRight) {
	std::list<int>::iterator itKey = itLeft; // iterator는 +1이 불가!

	for (++itKey; itKey != itRight; ++itKey) {
		int key = *itKey;
		std::list<int>::iterator itNextNumber;
		std::list<int>::iterator itNumber = itKey;
		for (--itNumber; itNumber != itLeft && *itNumber > key; --itNumber) {
			itNextNumber = itNumber;
			++itNextNumber;
			*(itNextNumber) = *itNumber;
		}
		if (*itNumber > key) {
			itNextNumber = itNumber;
			*(++itNextNumber) = *itNumber;
			*itNumber = key;
		} else {
			itNextNumber = itNumber;
			*(++itNextNumber) = key;
		}
	}
}


void PmergeMe::mergeSort(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right) {
	std::list<int> temp;
	std::list<int>::iterator it1 = left;
	std::list<int>::iterator it2 = mid;

	while (it1 != mid && it2 != right) {
		if (*it1 < *it2) {
			temp.push_back(*it1);
			++it1;
		} else {
			temp.push_back(*it2);
			++it2;
		}
	}
	while (it1 != mid) {
		temp.push_back(*it1);
		++it1;
	}
	while (it2 != right) {
		temp.push_back(*it2);
		++it2;
	}

	std::list<int>::iterator it = left;
	std::list<int>::iterator it_temp = temp.begin();
	while (it != right) {
		*it = *it_temp;
		++it;
		++it_temp;
	}
}

void PmergeMe::mergeInsertSort(std::list<int> &numbers, std::list<int>::iterator left, std::list<int>::iterator right) {
	if (std::distance(left, right) + 1 <= CRTR) { //distance(A, B) : A부터 B까지의 거리
		insertSort(left, right);
	} else {
		std::list<int>::iterator mid = left;
		std::advance(mid, std::distance(left, right) / 2); // advance(시작위치, 이동거리) : 시작위치부터 이동거리만큼 이동
		mergeInsertSort(numbers, left, mid);
		mergeInsertSort(numbers, mid, right);

		mergeSort(left, mid, right);
	}
}