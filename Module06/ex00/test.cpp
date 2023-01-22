#include <iostream>

int main() {
	char	*end;

	double	d1 = std::strtod("nanQQQ", &end); // check nan;
	std::cout << d1 << std::endl;
	std::cout << end << std::endl;

	float	f = static_cast<float>(d1);
	std::cout << f << std::endl;

	double	d2 = std::strtod("-1", NULL);
	std::cout << d2 << std::endl;

	double	d3 = std::strtod("inf", NULL);  // check inf;
	std::cout << d3 << std::endl;
	std::cout << (d3 == std::numeric_limits<double>::infinity() ? "true" : "false") << std::endl;

	std::cout << std::numeric_limits<double>::max() << "\n" 
	<< std::numeric_limits<double>::min() << "\n" // 중간값, 0
	<< std::numeric_limits<double>::lowest() << std::endl;


	std::cout << std::numeric_limits<float>::max() << "\n" 
	<< std::numeric_limits<float>::min() << "\n" // 중간값, 0
	<< std::numeric_limits<float>::lowest() << std::endl;

	std::cout << -std::numeric_limits<float>::max() << "\n";

	std::cout << static_cast<int>(-std::numeric_limits<float>::max()) << "\n";

	return 0;
}