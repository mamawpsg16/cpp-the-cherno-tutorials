#include <iostream>
#include <cstring>

class String {
public:
	String() = default;
	String(const char* string) {
		std::cout << "CONSTRUCTOR" << '\n';
		m_size = strlen(string);
		m_string = new char[m_size + 1];
		memcpy(m_string, string, m_size);
		m_string[m_size] = 0;
	}

	String(const String& other) {
		std::cout << "COPY CONSTRUCTOR" << '\n';
		m_size = other.m_size;
		m_string = new char[m_size + 1];
		memcpy(m_string, other.m_string, m_size);
		m_string[m_size] = 0;
	}

	void printString() {
		std::cout << m_string << '\n';
	}
	~String() {
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

	void print() {
		m_string.printString();
	}
private:
	String m_string;
};

int main() {
	/*String str("Kevin Mensah");
	str.printString();*/

	Entity entity(String("Kevin Mensah"));
	entity.print();

}