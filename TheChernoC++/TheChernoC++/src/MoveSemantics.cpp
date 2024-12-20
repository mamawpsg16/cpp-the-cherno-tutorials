#include <iostream>
#include <cstring>

class String {
public:
	String() : m_string(nullptr), m_size(0) {}
	String(const char* string) {
		std::cout << "CONSTRUCTOR" << '\n';
		m_size = strlen(string);
		m_string = new char[m_size + 1];
		memcpy(m_string, string, m_size);
		m_string[m_size] = 0;
	}

	//COPY CONSTRUCTOR
	String(const String& other) {
		std::cout << "COPY CONSTRUCTOR" << '\n';
		m_size = other.m_size;
		m_string = new char[m_size + 1];
		memcpy(m_string, other.m_string, m_size);
		m_string[m_size] = 0;
	}

	//MOVE CONSTRUCTOR
	String(String&& other) noexcept {
		std::cout << "MOVE CONSTRUCTOR" << '\n';
		m_size = other.m_size;
		m_string = other.m_string;

		other.m_size = 0;
		other.m_string = nullptr;
	}

	//MOVE ASSIGNMENT OPERATOR
	String& operator =(String&& other) noexcept {
		std::cout << "MOVE ASSIGNMENT" << '\n';

		if (this != &other) {
			delete[] m_string;  // Free the existing resource

			m_size = other.m_size;
			m_string = other.m_string;

			other.m_size = 0;
			other.m_string = nullptr;
		}

		return *this;
	}

	void printString() {
		if (m_string) {
			std::cout << m_string << '\n';
		}
		else {
			std::cout << "String is empty" << '\n';
		}
	}

	~String() {
		std::cout << "DESTROYED" << '\n';
		delete[] m_string;
	}
private:
	char* m_string;
	size_t m_size;
};

class Entity {
public:
	Entity(const String& string) : m_string(string) {

	}

	//Entity(String&& string) : m_string((String&&)string) {
	Entity(String&& string) : m_string(std::move(string)) {

	}

	void print() {
		m_string.printString();
	}
private:
	String m_string;
};

int main() {
	/*String str("Kevin Mensah");
	str.printString();*/

	// MOVE CONSTRUCTOR
	//Entity entity = String("Kevin Mensah");
	/*Entity entity("Kevin Mensah"); 
	entity.print();*/

	// MOVE ASSIGNMENT
	
	/* THIS TRIGGERS MOVE CONSTRUCTOR INSTEAD AS THE entity1 is not already an object*/
	//Entity entity1 = (String&&)entity;
	//Entity entity1 = std::move(entity);

	/* MOVE ASSIGNMENT OPERATOR */
	String apple = "APPLE";
	String dest; 
	std::cout << "Apple :" << '\n';
	apple.printString();
	std::cout << "Dest :" << '\n';
	dest.printString();

	dest = std::move(apple);

	std::cout << "Apple :" << '\n';
	apple.printString();
	std::cout << "Dest :" << '\n';
	dest.printString();
}