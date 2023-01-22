#include <iostream>

void studyStrtodF() {
	char	*end;

	std::cout << "\n===== study strtod & tset nan =====" << std::endl;
	double	d1 = std::strtod("nanQQQ", &end); // check nan;
	std::cout << "return value: " << d1 << std::endl;
	std::cout << "두번째 인자 포인터: " << end << std::endl;

	float	f = static_cast<float>(d1);
	std::cout << "casting float: " << f << std::endl;

	std::cout << "\n===== test negative =====" << std::endl;
	double	d2 = std::strtod("-1", NULL);
	std::cout << "return value: " << d2 << std::endl;

	std::cout << "\n===== test inf =====" << std::endl;
	double	d3 = std::strtod("inf", NULL);  // check inf;
	std::cout << "return value: " << d3 << std::endl;
	std::cout << "compare infinity(): " << (d3 == std::numeric_limits<double>::infinity() ? "true" : "false") << std::endl;
}

void studyNumericLimitsF() {
	std::cout << "\n===== study numeric_limits =====" << std::endl;
	std::cout << "double" << std::endl;
	std::cout << "max: " << std::numeric_limits<double>::max() << "\n" 
	<< "min: " << std::numeric_limits<double>::min() << "\n" // 중간값, 0
	<< "lowest: " << std::numeric_limits<double>::lowest() << std::endl;
	std::cout << "compare lowest & -max(): " << (std::numeric_limits<double>::lowest() == -std::numeric_limits<double>::max() ? "true" : "false") << std::endl;

	std::cout << "float" << std::endl;
	std::cout << "max: " << std::numeric_limits<float>::max() << "\n" 
	<< "min: " << std::numeric_limits<float>::min() << "\n" // 중간값, 0
	<< "lowest: " << std::numeric_limits<float>::lowest() << std::endl;
	std::cout << "compare lowest & -max(): " << (std::numeric_limits<float>::lowest() == -std::numeric_limits<float>::max() ? "true" : "false") << std::endl;

	std::cout << "char" << std::endl;
	std::cout << "max: " << (int)std::numeric_limits<char>::max() << "\n"
	<< "min: " << (int)std::numeric_limits<char>::min() << "\n"
	<< "u_min: " << (int)std::numeric_limits<u_char>::min() << "\n";

}

int main() {
	// studyStrtodF();
	studyNumericLimitsF();

	return 0;
}