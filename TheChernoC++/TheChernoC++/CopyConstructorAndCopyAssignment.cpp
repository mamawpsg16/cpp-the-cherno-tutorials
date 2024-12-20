#include <iostream>

struct Vector {
	float x, y;
};

class User {
private:
	char* m_name;
	size_t stringSize;
public:
	User(const char* name) {
		stringSize = strlen(name);
		m_name = new char[stringSize + 1];

		memcpy(m_name, name, stringSize);

		m_name[stringSize] = 0;
	}

	//which means you can't create a new object as a copy of another User object (e.g., using User u2 = u1;).
	//User(const User& other) = delete; //DONT ALLOW COPYING CONSTRUCTOR

	//which means you can't assign one User object to another User object (e.g., using u1 = u2;).
	//User& operator=(const User& other) = delete; // DONT ALLOW COPY ASSIGNMENT OPERATOR

	// Copy Constructor
	User(const User& other) : stringSize(other.stringSize) {
		std::cout << "COPIED" << '\n';
		m_name = new char[stringSize + 1];
		memcpy(m_name, other.m_name, stringSize);
		m_name[stringSize] = '\0'; // Null-terminate the string
	}

	// Copy Assignment Operator
	User& operator=(const User& other) {
		if (this != &other) { // Avoid self-assignment
			delete[] m_name; // Free existing resource
			stringSize = other.stringSize;
			m_name = new char[stringSize + 1];
			memcpy(m_name, other.m_name, stringSize);
			m_name[stringSize] = '\0'; // Null-terminate the string
		}
		return *this;
	}

	friend std::ostream& operator <<(std::ostream& stream, const User& user);

	char& operator[](unsigned int index) {
		return m_name[index];
	}

	~User() {
		delete[] m_name;
	}
};

std::ostream& operator <<(std::ostream& stream,const User& user) {
	stream << user.m_name << '\n';
	return stream;
}

void printUserName(User user){
	std::cout << user << '\n';
}


//int main() {
//	//Vector a = { 2, 3 };  // Aggregate initialization FOR STRUCT
//	//Vector b = a;
//	//b.x = 5; // WOULDNT ABLE TO MUTATE THE X VALUE IN A VARIABLE BECAUSE ITS JUST A COPY
//	//std::cout << "a.x = " << a.x << " b.x = " << b.x << '\n';
//
//	/*Vector* a = new Vector();
//	std::cout << "a memory address = " << a << '\n';*/
//
//	//Vector* b = a; // POINTS TO THE A ADDRESS
//	/*std::cout << "b memory address = " << b << '\n';
//	b->x = 5;
//	std::cout << "a.x = " << a->x << " b.x = " << b->x << '\n';*/
//
//	/* SHALLOW COPY WITH ERROR BECAUSE ITS DELETED THE ALLOCATE m_name twice */
//	/*User user1 = "Kevin";
//	User user2 = user1;
//	user1[1] = 'a';
//
//	std::cout << user1 << '\n';
//	std::cout << user2 << '\n';*/
//
//	/* DEEP COPY */
//	User user1 = "Kevin";
//	//User user2 = user1; // COPY CONSTRUCTOR
//	//user2[1] = 'a';
//
//	User user3 = "Rojenson"; // COPY ASSIGNMENT
//	user3 = user1;
//
//	//std::cout << user1 << '\n';
//	//std::cout << user3 << '\n';
//
//	//printUserName(user1);
//	//printUserName(user2);
//	printUserName(user3);
//}