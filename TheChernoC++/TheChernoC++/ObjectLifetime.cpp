#include <iostream>
#include <string>

class Entity {
public:
	Entity() {
		std::cout << "Created Entity!" << '\n';
	};

	~Entity() {
		std::cout << "Destroyed Entity!" << '\n';
	};
};

//int* createArray() { // WRONG
//	int array[50];
//
//	return array;
//}

class scopedPtr {
private:
	Entity* m_ptr;
public:
	scopedPtr(Entity* ptr) :m_ptr(ptr) {

	}

	~scopedPtr() {
		delete m_ptr;
	}
};

//int main() {
//	{
//		//Entity e; //STACK
//		//Entity* e = new Entity; // HEAP NEED TO MANUALLY DELETE 
//		scopedPtr e(new Entity()); // SMART POINTER AUTO DELETE
//	}
//}