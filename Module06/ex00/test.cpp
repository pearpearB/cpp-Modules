#include <iostream>

int main() {
	char	*end;

	double	d1 = std::strtod("nanQQQ", &end); // check nan;
	std::cout << d1 << std::endl;
	std::cout << end << std::endl;

	float	f = static_cast<float>(d1);
	std::cout << f << std::endl;

	double	d2 = std::strtod("42.42abc", NULL);
	std::cout << d2 << std::endl;

	double	d3 = std::strtod("inf", NULL);  // check inf;
	std::cout << d3 << std::endl;
	std::cout << (d3 == std::numeric_limits<double>::infinity() ? "true" : "false") << std::endl;

	return 0;
}