#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Please enter: ./losers <file_name> <s1> <s2>" << std::endl;
		return 1;
	}
	
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	if (s1.empty()) {
		std::cout << "<s1> must exist" << std::endl;
		return 1;
	}
	if (!s1.compare(s2)) {
		std::cout << "<s1> and <s2> must be different" << std::endl;
		return 1;
	}

	std::ifstream	fileSrc(argv[1]);
	if (fileSrc.fail()) {
		std::cout << "File " << argv[1] << " does not exist" << std::endl;
		return 1;
	}

	std::ofstream	fileDst(std::string(argv[1]) + ".replace");
	if (fileDst.fail()) {
		std::cout << "File " << argv[1] << ".replace" << " can't open" << std::endl;
		return 1;
	}

	std::string	line;
	while (std::getline(fileSrc, line, '\0')) {
		size_t	tmp = 0;;
		if (std::cin.eof()) break;
		while ((tmp = line.find(s1, tmp)) != std::string::npos) {
			line.erase(tmp, s1.length());
			line.insert(tmp, s2);
			tmp += s2.length();
		}
		fileDst << line;
	}

	fileSrc.close();
	fileDst.close();

	return 0;
}
