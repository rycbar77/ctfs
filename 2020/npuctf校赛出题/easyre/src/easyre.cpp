#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <exception>

void scram(std::vector<uint8_t> & s) {
	uint8_t start = 0x23;
	for (size_t i = 0; i < s.size(); i++) {
		if (s.at(i) != '\n') {
			s.at(i) ^= start;
			start = (start + i) % std::numeric_limits<uint8_t>::max();
		} else {
			throw std::exception();
		}
	}
}

bool valid(std::vector<uint8_t> & s) {
	const std::vector<uint8_t> cmp = {69, 230, 208, 74, 79, 195, 126, 170, 69, 252, 66, 178, 65, 181, 1, 180, 82, 125, 57, 32, 26, 192, 78, 19, 90, 47, 103, 170, 93, 121, 107, 245, 77, 6, 65, 121, 34, 53, 249, 200, 15, 222, 136, 81, 51, 76, 240, 129, 80, 244, 238, 20, 46, 241, 37, 189, 16, 124, 98, 48, 227, 248, 128, 43, 196, 133, 42, 248, 207, 90, 174, 203, 140, 58, 162, 208, 187, 197, 140, 93, 131, 52, 107, 249, 129, 114, 75, 14, 84, 195, 113, 83, 85, 233, 7, 187, 80, 26, 231, 7, 100, 27, 117, 116, 94, 142, 93, 46, 220, 246, 23, 59, 236, 237, 215, 189, 223, 233, 118, 99, 136, 226, 234, 137, 133, 215, 79, 52, 103, 57, 213, 88, 5, 217, 210, 210, 52, 105, 241, 191, 73, 118, 225, 156, 254, 13, 12, 179, 210, 6, 72, 218, 209, 213, 30, 184, 84, 148, 76, 152, 6, 138, 104, 168, 40, 94, 100, 249, 230, 88, 247, 2, 242, 141, 59, 136, 189, 20, 236, 143, 49, 112, 12, 11, 65, 102, 34, 142, 25, 88, 1, 46, 208, 220, 75, 192, 136, 244, 218, 230, 159, 115, 136, 125, 124, 145, 31, 117, 37, 112, 214, 12, 186, 9, 124, 242, 211, 78, 161, 9, 131, 81, 60, 186, 72, 100, 56, 45, 24, 0, 136, 227};
	for (size_t i = 0, j = 0; j < cmp.size(); i++, j += 4) {
		if (cmp.at(j) != s.at(i)) return false;
	}
	/*
	for (size_t i = 0; i < cmp.size(); i++) {
		if (cmp.at(i) != s.at(i)) return false;
	}
	*/
	return true;
}

void intro(void) {
	std::cout << "Welcome! It is a easy re problem. Are you ready?" << std::endl;
	int c = ::getchar();
	if (!(c > 0x20 && c < 0x7f)) {
		std::cout << "Try this." << std::endl;
	}
}

std::vector<uint8_t> get_input(void) {
	std::cout << "Input the flag: ";
	std::string inp;
	std::cin >> inp;
	return std::vector<uint8_t>(inp.begin(), inp.end());
}


int main() {
	intro();
	std::vector<uint8_t> uinput = get_input();
	scram(uinput);
	if (valid(uinput)) {
		std::cout << "Congratulations!" << std::endl;
	} else {
		std::cout << "Wrong!" << std::endl;
	}
}