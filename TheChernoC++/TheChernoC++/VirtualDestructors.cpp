#include <iostream>

class Base {
public:
	Base() {
		std::cout << "Base Construct" << '\n';
	};

	// the actual object being deleted is of type Derived. Since Base's destructor is virtual, 
	// the compiler looks up the correct destructor chain and first calls Derived's destructor, followed by Base's destructor.
	virtual ~Base() {
		std::cout << "Base Deconstructor" << '\n';
	}
};

class Derived: public Base {
public:
	Derived() {
		std::cout << "Derived Construct" << '\n';
	};

	~Derived() {
		delete m_array;
		std::cout << "Derived Deconstructor" << '\n';
	}
private:
	int* m_array = new int[5];
};

//int main() {
//	Base* base = new Base();
//	delete base;
//
//	std::cout << "----------" << '\n';
//
//	Derived* derived = new Derived();
//	delete derived;
//
//	std::cout << "----------" << '\n';
//
//	Base* poly = new Derived();
//	delete poly;
//
//}