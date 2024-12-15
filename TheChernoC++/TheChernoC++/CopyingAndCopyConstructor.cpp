#include <iostream>

struct Vector {
	float x, y;
};

class String {
	char* m_buffer;
	size_t  m_size;
public:
	String(const char* string) {
		m_size = strlen(string);  // Calculate string size
		m_buffer = new char[m_size + 1];  // Allocate memory (+1 for null terminator)
		memcpy(m_buffer, string, m_size);  // Copy string contents
		m_buffer[m_size] = 0;  // Null-terminate the string
	}

	~String() {
		delete[] m_buffer;
	}

	char& operator[](unsigned int index) {
		return m_buffer[index];
	}

	//String(const  String& other) = delete;  DISABLE COPY CONSTRUCTOR

	String(const  String& other) :m_size(other.m_size) { //DEEP COPY
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, other.m_buffer, m_size + 1);
	}

	friend std::ostream& operator << (std::ostream& stream, const String& string);
};

std::ostream& operator << (std::ostream& stream, const String& string) {
	stream << string.m_buffer;
	return stream;
}
//int main() {
//	//Vector a = { 2, 3 };  // Aggregate initialization FOR STRUCT
//	//Vector b = a;
//	//b.x = 5; // WOULDNT ABLE TO MUTATE THE X VALUE IN A VARIABLE BECAUSE ITS JUST A COPY
//
//	//Vector* a = new Vector();
//	//Vector* b = a; // POINTS TO THE A ADDRESS
//	//b->x = 5;
//	//std::cout << a->x << '\n';
//
//	String string = "Cherno";
//	String string1 = string;
//	string[2] = 'a';
//
//	std::cout << string << '\n';
//	std::cout << string1 << '\n';
//}