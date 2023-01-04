#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	std::string 	filename;
	std::string		s1;
	std::string		s2;
	std::ifstream	fileSrc;
	std::ofstream	fileDst;
	std::string		buf;

	if (argc != 4) {
		std::cout << "Please enter: ./losers <file_name> <s1> <s2>" << std::endl;
		return 1;
	}
	
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty()) {
		std::cout << "<s1> must exist" << std::endl;
		return 1;
	}
	if (!s1.compare(s2)) {
		std::cout << "<s1> and <s2> must be different" << std::endl;
		return 1;
	}

	filename = argv[1];
	fileSrc.open(filename);
	if (fileSrc.fail()) {
		std::cout << "File " << filename << " does not exist" << std::endl;
		return 1;
	}

	fileDst.open(std::string(filename) + ".replace");
	if (fileDst.fail()) {
		std::cout << "File " << filename << ".replace" << " can't open" << std::endl;
		return 1;
	}

	while (std::getline(fileSrc, buf, '\0')) {
		if (std::cin.eof()) break;

		size_t	pos = 0;
		while ((pos = buf.find(s1, pos)) != std::string::npos) {
			buf.erase(pos, s1.length());
			buf.insert(pos, s2);
			pos += s2.length();
		}
		fileDst << buf;
	}

	fileSrc.close();
	fileDst.close();

	return 0;
}
