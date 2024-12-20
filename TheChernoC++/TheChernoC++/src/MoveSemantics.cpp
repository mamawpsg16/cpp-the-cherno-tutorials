#include <iostream>

class User {
public:
	User() {
		std::cout << "Default User Created" << std::endl;
		m_data = nullptr;
		m_dataSize = 0;
	}

	User(const char* name){
		std::cout << "User Created" << '\n';

		m_dataSize = strlen(name);
		m_data = new char[m_dataSize + 1];
		memcpy(m_data, name, m_dataSize);
		m_data[m_dataSize] = 0;
	}

	//User(const User& other) = delete;

	User(const User& other) {
		std::cout << "User Copied" << '\n';
		m_dataSize = other.m_dataSize;
		m_data = new char[other.m_dataSize + 1];
		memcpy(m_data, other.m_data, m_dataSize);
		m_data[m_dataSize] = 0;
	}

	User& operator=(const User& other) {
		std::cout << "User Assigned" << '\n';
		if (this != &other) { // Check for self-assignment
			delete[] m_data; // Free existing resource
			m_dataSize = other.m_dataSize;
			m_data = new char[m_dataSize + 1];
			memcpy(m_data, other.m_data, m_dataSize);
			m_data[m_dataSize] = 0;
		}
		return *this; // Return *this to allow chained assignments
	}


	//User(User&& other) = delete;

	User(User&& other) noexcept : m_dataSize(other.m_dataSize), m_data(other.m_data) {
		std::cout << "User Moved" << '\n';

		other.m_dataSize = 0;
		other.m_data = nullptr;
	}

	~User() {
		std::cout << "User Destroyed" << '\n'; // Destructor message
		delete[] m_data;
	}

	void printData() const {
		std::cout << "User Data: ";
		if (m_data) {
			std::cout << m_data << std::endl;
		}
		else {
			std::cout << "nullptr" << std::endl;
		}
	}

	void printName() {
		for (uint32_t i = 0; i < m_dataSize; i++)
		{
			printf("%c", m_data[i]);
		}

		printf("\n");
	}

private:
	char* m_data;
	uint32_t m_dataSize;
};

class Entity {
public:
	Entity(const User& user): m_name(user){}

	//Entity(User&& user) : m_name((User&&)user) {}
	Entity(User&& user) : m_name(std::move(user)) {}

	void printUser() {
		m_name.printName();
	}
private:
	User m_name;

};
class Shit {
public: // Make constructor and destructor public for access
	Shit() {
		std::cout << "Shit Created\n";
	}

	~Shit() {
		std::cout << "Shit Destroyed\n";
	}
};
int main() {
	//{
		User user = "kevin";
		User user1 = user;

		User user2 = "Hello Btch";
		user2 = user;
	//	user.printData(); // Print user data to show default constructor worked
	//	Shit shit;

	//	//Entity entity{ "Kevin" }; // Use list initialization

	//	//// Access entity to prevent compiler optimization
	//	//entity.printUser();

	//	std::cin.get();
	//}
}