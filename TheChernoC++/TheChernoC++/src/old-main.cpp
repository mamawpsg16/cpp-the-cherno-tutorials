#include <iostream>
#include <string>
#define LOG(message) std::cout << message << '\n';
#include <array>
#include "VirtualFunction.cpp"
#include "InterfacesPureVirtualFunction.cpp"
#include "Mutable.cpp"

extern int s_Variable;

void Logger(const char * message) {
	std::cout << message << '\n';
}


class Animal {
public:
	std::string name;
	std::string breed;

	// Constructor
	Animal(const std::string& name, const std::string& breed) : name(name), breed(breed) {}

	// Virtual function to demonstrate polymorphism
	virtual void makeSound() const {
		std::cout << "Animal sound!" << std::endl;
	}
};

// Derived class
class Dog : public Animal {
public:
	std::string favoriteToy;

	// Constructor
	Dog(const std::string& name, const std::string& breed, const std::string& favoriteToy)
		: Animal(name, breed), favoriteToy(favoriteToy) {
	}
};

// PASS ADDRESS TO POINTER
void Increment(int* value) {
	(*value)++;
}
// PASS BY REFERENCE
void Increment1(int& value) {
	value++;
}

//class Player
//{
//	int xPosition = 0, yPosition = 0;
//	int speed = 0;
//public:
//	Player();
//	~Player();
//
//	void move(int x, int y) {
//		xPosition = x;
//		yPosition = y;
//	}
//
//private:
//
//};
//
//Player::Player()
//{
//}
//
//Player::~Player()
//{
//}


void printString(const std::string& string) {
	std::cout << string << '\n';
}
void Print(Printable* obj) {
	std::cout << obj->getClassName() << '\n';
}
class Log {
public:
	enum Level {
		LevelError, LevelWarning, LevelInfo
	};
	/*const int logLevelError = 0;
	const int logLevelWarning = 1;
	const int logLeveInfo = 2;*/

private:
	Level m_logLevel = LevelInfo;

public:
	void setLevel(Level level) {
		m_logLevel = level;

	}

	void error(const char* message) {
		if (m_logLevel >= LevelError) {
			std::cout << "[ERROR]: " << message << '\n';
		}
	}

	void warn(const char* message){
		if (m_logLevel >= LevelWarning) {
			std::cout << "[WARNING]: " << message << '\n';
		}
	}

	void info(const char* message) {
		if (m_logLevel >= LevelInfo) {
			std::cout << "[INFO]: " << message << '\n';
		}
	}

};

struct Entity {
	static int x, y;

	void print() {
		std::cout << x << ", " << y << "\n";
	}
};

int Entity::x;
int Entity::y;

enum Example : char{
	A = 1 , B, C
};


//DISABLE/DELETE CONSTRUCTOR
class Test {

public:
	Test() = delete;
	static void log() {
		std::cout << "HELLO BITCH";
	}
};

//int main() {
	//int a = 5;
	//const char* ptr = "Hello Btch";
	//for (size_t i = 0; i < 5; i++)
	//{
	//	//if (i % 2 == 0)
	//	if (i < 2)
	//	{
	//		continue;
	//	}
	//	Logger(ptr);
	//	std::cout << "Iteration " << i << '\n';
	//}
	//int num1 = 10;
	//int* ptr1 = &num1;
	//*ptr1 = 1;
	//std::cout << "num1 " << num1;

	//int num2 = 11;
	//Increment(&num2);
	/*Increment1(num2);
	std::cout << "num2 " << num2 << '\n';

	Player player1;
	player1.move(10, 20);

	Log log;
	log.setLevel(Log::LevelError);
	log.error("Hello!");
	log.warn("Hello!");
	log.info("Hello!");*/

	//std::cout << "EXTERN " << s_Variable << '\n';
	//std::cout << "EXTERN " << s_Variable << '\n';

	/*Entity e;
	Entity::x = 1;
	Entity::y = 2;*/

	/*Entity e1;
	e1.x = 3;
	e1.y = 4;*/

	//e.print();
	//e1.print();

	/*Example value = A;
	std::cout << value << '\n';*/

	//Test t; ERROR 
	//Test::log();

	/* INHERITANCE */
	//const std::string& name, const std::string& breed, const std::string& favoriteToy
	//Dog bully("Luna", "Dalmatian", "TeddyBear");
	//bully.makeSound();

	/* VIRTUAL FUNCTION */

	//Identity id;
	//std::cout << id.getName();
	//Identity* id1 = new Identity;
	//std::cout << id1->getName();

	//Player1 newPlayer("Kevin");
	//std::cout << newPlayer.getName();
	//Player1* newPlayer = new Player1("Kevin"); // If you need a pointer (Player1*), use the new keyword to allocate memory for the object and call its constructor: Returns the memory address of the newly created object.
	//std::cout << newPlayer->getName() << std::endl;
	//Identity* p = newPlayer;
	//std::cout << p->getName() << std::endl;
	//delete newPlayer;

	/* INTERFACE (PURE VIRTUAL FUNCTION)*/
	//Identity1 id4 = new Identity1; //ERROR
	/*Identity1* id4 = new Identity1;
	Player2* player3 = new Player2("");

	Print(id4);
	Print(player3);*/


	/* ARRAY */
	//int example[5]; //AUTO DESTROY - CREATED ON STACK 
	//example[0] = 1;
	//int* ptr = example;
	//*(ptr + 2) = 6; //ACCESSING THIRD INT SAME AS example[2] = 6;
	//std::cout << example[2];

	//std::array<int, 5> newArray;
	//newArray.size();
	//int* another = new int[5]; // CREATED AT THE HEAP NEED TO MANUALLY DELETE - CREATED ON THE HEAP
	//for (size_t i = 0; i < 5; i++)
	//{
	//	another[i] = 2;
	//}
	//delete[] another;

	/* STRING */
	const char* name1 = "Kevin";
	//char name[6] = { 'K', 'E', 'V', 'I', 'N', '\0'};

	//std::cout << name << '\n';
	/*std::string name2 = std::string("Krizel") + " Mensah";
	bool containsWord = name2.find('z') != std::string::npos;
	std::cout << containsWord << '\n';
	std::cout << name2.find('z') << '\n';
	std::cout << name2 << '\n';
	printString(name2);

	std::cout << strlen(name1) << '\n';

	using namespace::std::string_literals;
	const char* text = R"(Hello
Bitch)";

	std::cout << text << '\n';*/

	/* CONST */
	//const int MAX_AGE = 100; // CANT CHANGE THE VALUE

	//const int* a = new int; // CANT CHANGE THE VALUE
	//int const* a = new int; // CANT CHANGE WHERE IT POINTS
	//*a = 2; // Allowed
	//a = MAX_AGE;
	//std::cout << *a << '\n';

	/*MUTABLE*/
	//ConstantExample e1;
	//std::cout << e1.getM() << '\n';
	//int v1 = 2;
	//auto  f = [=]() mutable { // TO BE ABLE TO MUTATE THE used variable inside of lambda but wont change the outher variable
	//auto  f = [&]() {
//		v1++;
//			std::cout << "Hello Btch " << v1 << '\n';
//		};
//	f();
//
//	std::cout << v1 << '\n';
//	
//	return 0;
//}