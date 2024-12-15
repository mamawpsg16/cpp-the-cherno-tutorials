#include <iostream>
#include <string>

#define LOG(x) std::cout << x << '\n';

using String = std::string;  // Alias for std::string
//typedef std::string String; // Alias older way

class Entity {
private:
	String m_name;
	int m_age;
public:
	Entity(const String& name) : m_name(name), m_age(-1 ) {}
	explicit Entity(int age) : m_name("Unknown"), m_age(age) {}

	// Function returning a const reference
	const String& getName() const {
		return m_name;
	}
};

//int main() {
//	//Entity a = "Cherno";
//	//Entity b = 22; //IMPLICIT TO CALL THE CONSTRUCTOR WITH AGE IF NO EXPLICIT KEYWORD
//	Entity b(22); //EXPLICIT TO CALL THE CONSTRUCTOR
//	Entity b = (Entity)22; //EXPLICIT TO CALL THE CONSTRUCTOR
//	Entity b = Entity(22); //EXPLICIT TO CALL THE CONSTRUCTOR
//
//}