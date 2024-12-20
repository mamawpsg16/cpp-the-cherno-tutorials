#include <iostream>

class Singleton {
public:
	Singleton(const Singleton&) = delete;            // No copy
	Singleton& operator=(const Singleton&) = delete; // No assignment
	static Singleton& get() {
		static Singleton s_instance;

		return s_instance;
	}
	static int getValue() {
		return get().intValue();
	}
private:
	Singleton() = default;
	int intValue() {
		return value;
	}
	int value = 25;
};

//int main() {
//	std::cout << Singleton::getValue() << '\n';
//}