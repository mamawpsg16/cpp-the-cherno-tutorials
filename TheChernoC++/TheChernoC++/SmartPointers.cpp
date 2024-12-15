#include <iostream>
#include <memory> // TO ACCESS SMART POINTERS

class Entity {
public:
	Entity() {
		std::cout << "Created Entity!" << '\n';
	}

	~Entity() {
		std::cout << "Destroyed Entity!" << '\n';
	}
	void print() {

	}
};

//int main() {
//	{
//		//std::shared_ptr<Entity> sharedEntity1;
//		std::weak_ptr<Entity> weakEntity1;
//		{
//			/* UNIQUE PTR */
//			//std::unique_ptr<Entity> entity(new Entity); // FIRST WAY
//			//std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // PREFERRED WAY
//			//entity->print();
//
//			/* SHARED PTR */
//			//std::shared_ptr<Entity> sharedEntity(new Entity); // FIRST WAY
//			std::shared_ptr<Entity> sharedEntity2 = std::make_shared<Entity>(); // PREFERRED WAY
//			//sharedEntity1 = sharedEntity2;
//
//			/* WEAK PTR*/
//			//std::weak_ptr<Entity> weakEntity2 = sharedEntity2;
//			weakEntity1 = sharedEntity2;
//		}
//
//	}
//	// SHARED POINTER WILL DIE NOW 
//	
//}