#include <iostream>
#include <variant>
#include <optional>

enum class Error {
	None = 0, NotFound = 1, NoAccess = 2
};

std::variant<std::string, Error> readFileAgainAsString() {
	return {};
}

//int main() {
//	std::variant<std::string, int> data; // CAN BE STRING OR INT
//	std::cout << sizeof(int) << "\n";
//	std::cout << sizeof(std::string) << "\n";
//	std::cout << sizeof(data) << "\n";
//	data = "Cherno";
//
//	std::cout << std::get<std::string>(data) << '\n';
//	if (auto value = std::get_if<std::string>(&data)) {
//		std::cout << *value;
//		std::string& v = *value;
//		std::cout << v;
//	}
//	data = 2;
//
//	std::cout << std::get<int >(data) << '\n';
//}