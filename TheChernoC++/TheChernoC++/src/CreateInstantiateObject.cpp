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
//	//Entity entity;
//	/*Entity entity("Kevin");*/
//	//Entity entity = Entity("Kevin"); //MOST FAST CONSTRUCT
//	Entity* e;
//	{
//		//Entity entity("Kevin"); // ALLOCATE TO STACK
//		Entity* entity  = new Entity("Kevin"); // ALLOCATE TO HEAP
//		e = entity;
//		//LOG((*entity).getName()); //SAME AS BELOW
//		LOG(entity->getName());
//
//	}
//	delete e;
//
//}