#include <iostream>
#include <vector>

int num1 = 1;

void forEach(const std::vector<int>& numbers, void(*printValue)(int)) {
	for (auto& number : numbers)
	{
		printValue(number);
	}
}

auto incrementNumber = []() {
	extern int num1;
	num1++;
	std::cout << "Num1 Value = " << num1;
};


//int main() {
//	std::vector<int> numbers = { 1,2,3,4,5,6 };
//	auto it = std::find_if(numbers.begin(), numbers.end(), [](int value) { return value > 3; });
//
//	std::cout << *it << '\n';
//	int b = 1;
//	auto lambda = [&b](int value) { std::cout << "Number:" << b << '\n'; };
//	lambda(5);
//	forEach(numbers, [](int value){ std::cout << "Number:" << value << '\n'; });
//	incrementNumber();
//}