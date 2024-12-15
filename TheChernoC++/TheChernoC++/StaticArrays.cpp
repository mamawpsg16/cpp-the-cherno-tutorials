#include <iostream>
#include <array>

template<typename T, size_t S>
void printArray(const std::array<T, S>& data) {
	/*for (size_t i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << '\t';
	}*/

	for (const T& num :  data)
	{
		std::cout << num << '\t';
	}
}
//int main() {
//
//	// STANDARD
//	//std::array<int, 5> data;
//	//data[0] = 1;
//	/*for (auto num : data)
//	{
//		std::cout << num << '\n';
//	}*/
//
//	// C STYLE
//	//int dataOld[5];
//
//	std::array<int, 5> data = {1,2,3,4,5};
//	printArray(data);
//
//}