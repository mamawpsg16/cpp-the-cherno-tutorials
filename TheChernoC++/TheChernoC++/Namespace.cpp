#include <iostream>


namespace apple{
	namespace functions {
		void print(const std::string& text) {
			std::cout << text << '\n';
		}
	}
}

namespace orange {
	void print(const char* text) {
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << '\n';
	}
}
//ALIASING NAMESPACE
//namespace a = apple;
//namespace a = apple::functions;

//int main() {
//	apple::functions::print("Hello World");
//	orange::print("Hello World");
//}