#include <iostream>

class Entity {
public:
	int x;
public:
	void print() const {
		std::cout << "Hello!" << '\n';
	}
};

class ScopedPtr {
private:
	Entity* m_obj;
public:
	ScopedPtr(Entity* entity) : m_obj(entity) {}

	~ScopedPtr() {
		delete m_obj;
	}
	
	const Entity* operator->() const	{
		return m_obj;
	}
};

struct Vector3 {
	float x, y, z;
};

//int main(){
	//Entity e;
	//e.print();
	//Entity* e1 = new Entity;
	//e1->print();
	//Entity* e2 = &e;
	//e2->x = 5;
	//e2->print();
	//std::cout << e2->x << '\n';
	//(*e2).print();

	//ScopedPtr scopedPtr = new Entity;
	//scopedPtr.m_obj.print(); // ERROR
	//scopedPtr->print();// GOOD
//}