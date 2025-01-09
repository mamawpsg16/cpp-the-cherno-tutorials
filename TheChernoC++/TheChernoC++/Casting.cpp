#include <iostream>

class Base {
public:
	Base() {
		std::cout << "Base Construct" << '\n';
	};

	virtual ~Base() { // Enables RTTI (RUNTIME CHECKING REQUIRED FOR DYNAMIC CAST)
		std::cout << "Base Deconstructor" << '\n';
	}
};

class Derived : public Base {
public:
	Derived() {
		std::cout << "Derived Construct" << '\n';
	};

	void show() { std::cout << "Derived class method" << "\n"; }

	~Derived() {
		std::cout << "Derived Deconstructor" << '\n';
	}

};

class Unrelated : public Base {};


void printNonConst(char* str) {
	std::cout << str << "\n";
}

void processData(void* data) {
	std::cout<< "DATA" << data << '\n';
	int* num = reinterpret_cast<int*>(data);  // Cast back to original type
	std::cout << "Processed data: " << *num << "\n";
}

//int main() {
	//double value = 5.25;

	//int a = (int)value; //EXPLICIT CONVERSION
	//double a = (int)value + 3.25; //EXPLICIT CONVERSION
	//double a = (int)(value + 3.25); //EXPLICIT CONVERSION
	//double a = (int)value + 3.3;
	//std::cout << a << '\n';
	
	/* STATIC CAST */
	//Types are known and guaranteed at compile time.
	//You need to avoid runtime overhead.
	
	//double s = static_cast<int>(value) + 3.3;
	//std::cout << s << '\n';

	/* DYNAMIC CAST*/
	//You're working with polymorphic types.
	//You need to check object types at runtime.

	//Base* basePtr = new Derived;   // Upcast to Base
	//Derived* dPtr = dynamic_cast<Derived*>(basePtr);  // Downcast

	//if (dPtr) {
	//	dPtr->show();  // Output: Derived class
	//}
	//else {
	//	std::cout << "Cast failed" << "\n";
	//}

	//// Incorrect cast
	//Unrelated* uPtr = dynamic_cast<Unrelated*>(basePtr);
	//if (!uPtr) { //IF NULLPTR
	//	std::cout << "Incorrect cast failed" <<  "\n";  // This will run
	//}

	//delete basePtr;

	/* CONST CAST - When calling a legacy function that doesn’t accept const arguments
	- Never use const_cast to modify truly constant values like literals or variables defined as const in global or local scope
	.*/
	//const char* message = "Hello, World!";

	// Cast away const-ness
	//printNonConst(const_cast<char*>(message));

	/* REINTERPRET_CAST */
	
	//int x = 42;
	 //Reinterpret int* as char*
	//char* p = reinterpret_cast<char*>(&x);

	//std::cout << "Value as char: " << *p << "\n";  // Shows the first byte of the int

	/* WRONG WAY */
	//struct A {
	//	int x = 10;
	//};

	//struct B {
	//	int y = 20;
	//};

	//A a;
	//B* b = reinterpret_cast<B*>(&a);  // Dangerous cast

	//std::cout << b->y << "\n";  // Undefined behavior

	//int value2 = 42;

	 //Store data in void*
	//void* rawData = &value2;

	 //Cast back and process
//	processData(rawData);
//
//}