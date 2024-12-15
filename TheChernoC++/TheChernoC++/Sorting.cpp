#include <iostream>
#include <vector>
#include<algorithm>
#include <functional>

//int main() {
//	std::vector<int> numbers = { 1,5,4,3,2 };
//
//	//std::sort(numbers.begin(), numbers.end());
//	//std::sort(numbers.begin(), numbers.end(), std::greater<int>());
//	std::sort(numbers.begin(), numbers.end(), [](int number1, int number2) {
//		//return number1 < number2;
//		if (number1 == 1) {
//			return false;
//		}
//
//		if (number2 == 1) {
//			return true;
//		}
//		
//		return number1 < number2;
//		});
//	for (auto num: numbers)
//	{
//		std::cout << num << '\n';
//	}
//}