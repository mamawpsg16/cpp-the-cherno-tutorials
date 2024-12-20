#include <iostream>

//PUT CONST SO RVALUE AND LVALUE CAN BE ACCEPTED
//void printName(const std::string& name) {
void printName(std::string& name) {
	std::cout << "LVALUE:" << name << '\n';
}

void printName(std::string&& name) {
	std::cout << "RVALUE:" << name << '\n';
}

//int main() {
	// LVALUE (HAVE VALUE AND CAN TAKE RVALUE)
	//int i = 10;
	//int& a = 10; // ERROR - LVALUE CANNOT ACCEPT AN RVALUE

	// RVALUE = ONLY VALUE (TEMPORARY)
	//CORRECT
	//int&& a1 = 25;

	//ERROR
	//int i1 = &a1; // ERROR a1 is an rvalue reference to an int, so it holds an integer value (25), but you are trying to assign the address of a1 (which is of type int*) to a variable i1 of type int
	//CORRECT
	//int i1 = a1; // `i1` now holds the value 25

	//ERROR
	//a1 = &i1; // a1 is an rvalue reference to int, so it expects an int value, but you're trying to assign it a pointer (&i1, which is an int*)
	//CORRECT
	//a1 = 30;
	//std::cout << i << '\n';

//	std::string name = "Kevin";
//	printName(name);
//	printName("Rojenson");
//}