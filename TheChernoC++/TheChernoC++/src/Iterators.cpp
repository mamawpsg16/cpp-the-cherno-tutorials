#include <iostream>
#include <vector>
#include <unordered_map>

#define LOG(x) std::cout << x << '\n';

//int main() {
//
//	std::vector<int> values = { 1,2,3,4,5 };
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
//	for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
//	{
//		LOG(*it);
//	}
//
//	std::cout << "--------------" << '\n';
//	using scoreMap = std::unordered_map<std::string, int>;
//	scoreMap map;
//	map["cpp"] = 1;
//	map["python"] = 0;
//
//	for (scoreMap::const_iterator it = map.begin();  it != map.end(); it++)
//	{
//		auto& key = it->first;
//		auto& value = it->second;
//		std::cout << key << " = " << value << '\n';
//
//	}
//	std::cout << "--------------" << '\n';
//	for (auto& kv : map)
//	{
//		auto& key = kv.first;
//		auto& value = kv.second;
//		std::cout << key << " = " << value << '\n';
//	}
//
//	std::cout << "--------------" << '\n';
//	//STRUCTURED BINDINGS
//	for (auto& [key, value] : map)
//	{
//		std::cout << key << " = " << value << '\n';
//	}
//}