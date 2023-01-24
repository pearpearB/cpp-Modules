#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	
	std::vector<int> v;
	v.push_back(6);
	v.push_back(3);
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);

	std::sort(v.begin(), v.end());

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << std::endl; // 포인터가 오버로딩 되어 있어 값 접근 가능
	}

	std::cout << "front back: " << v.front() << " " << v.back() << std::endl; // 마지막 요소 반환

	std::vector<int> vv;
	vv.push_back(20);
	vv.push_back(21);

	v.insert(v.end(), vv.begin(), vv.end()); // 벡터를 합칠 수 있다.

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << std::endl;
	}

	return 0;
}