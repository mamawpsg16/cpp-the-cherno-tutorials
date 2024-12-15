#include <iostream>
#include <string>

#define LOG(x) std::cout << x << '\n';

using String = std::string;  // Alias for std::string
//typedef std::string String; // Alias older way

class Entity {
private:
	String m_name;
public:
	Entity() : m_name("Unknown") {}
	Entity(const String& name) : m_name(name) {}

	// Function returning a const reference
	const String& getName() const {
		return m_name;
	}
};

//int main() {
//	int a = 2;
//	int* b = new int;
//	int* c = new int[10]; //10 ELEMENTS 
//
//	Entity* entity = new Entity[50]; //50 ELEMENTS 
//
//	LOG(a);
//
//	delete b;
//	delete[] c;
//	delete[] entity;
//
//}