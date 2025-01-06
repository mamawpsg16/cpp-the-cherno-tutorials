#include <iostream>

template<typename T, size_t S>
class Array {
public:
	Array() = default;

	constexpr size_t size() const {
		return S;
	}

	T& operator[](size_t index) {
		return m_data[index];
	}

	// ONLY SHOULD BE ABLE READ THE DATA BUT NOT MODIFY IT
	const T& operator[](size_t index) const {
		return m_data[index];
	}

	T* data() {
		return m_data;
	}

	const T* data() const {
		return m_data;
	}
private:
	T m_data[S];
};
//int main() {
	//Array<int, 5> collection;

	//const auto& arrayReference = collection;

	//std::memset(collection.data(), 0, collection.size() *  sizeof(int));

	//collection[1] = 5;
	//collection[2] = 3;

	//Array<std::string, 2> collection;
	//collection[0] = "Kevin";
	//collection[1] = "Kristian";
	//for (size_t i = 0; i < collection.size(); i++)
	//{	
	//	//arrayReference[i] = 2;
	//	//collection[i] = 2;
	//	std::cout << collection[i] << '\n';
	//}
//}