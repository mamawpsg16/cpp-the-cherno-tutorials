#include <iostream>

class Singleton {
	
public:
	static Singleton& get() {
		static Singleton instance;
		return instance;
	}

	void hello() {
		std::cout << "HELLO WORLD";
	}
};

void function() {
	static int i = 0;
	i++;
	std::cout << i << "\n";
}
//int main() {
//	//function();
//	//function();
//	//function();
//	//function();
//	//function();
//
//	Singleton::get().hello();
//}