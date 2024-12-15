#include <iostream>

//OVERLOADING
//void print(int value) {
//	std::cout << value << '\n';
//}
//
//void print(std::string value) {
//	std::cout << value << '\n';
//}

//template <typename T>
//void print(T value) {
//	std::cout << value << '\n';
//}

template<typename T, int N>
class Array {
private:
	T m_array[N];
public:
	int getSize() {
		return N;
	}
};

//int main() {
//	//print(5);
//	//print("Kevin");
//	//print<int>(5);
//
//	Array<int, 5> array;
//	std::cout << array.getSize();
//
//}