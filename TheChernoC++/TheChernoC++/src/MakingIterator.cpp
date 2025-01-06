#include <iostream>
#include <vector>
#include <unordered_map>
#include "Vector.h"

#define LOG(x) std::cout << x << '\n';

//int main() {
//
//	Vector<std::string> values;
//	values.emplaceBack("1");
//	values.emplaceBack("2");
//	values.emplaceBack("3");
//	values.emplaceBack("4");
//	values.emplaceBack("5");
//	for (size_t i = 0; i < values.size(); i++)
//	{
//		LOG(values[i]);
//	}
//
//	std::cout << "--------------" << '\n';
//
//	for (auto& value : values)
//	{
//		LOG(value);
//	}
//	std::cout << "--------------" << '\n';
//
//	for (Vector<std::string>::iterator it = values.begin(); it != values.end(); ++it) {
//		LOG(*it);
//	}
//}