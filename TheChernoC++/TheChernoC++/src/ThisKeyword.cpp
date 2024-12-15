#include <iostream>


//void PrintEntity(const Entity& e);
// 
// Forward declaration of Entity class
class Entity; // FORWARD DECLARATION

// Declaration of PrintEntity function
void PrintEntity(const Entity* e); //FORWARD DECLARATION

// What Does *this Return?
//Dereferencing this (*this) in the constructor or a member function will return the current object, allowing you to :
//Pass the object to a function by value.
//Chain method calls(if returning* this from member functions).


/*expression	Returns	Example					Use Case
this			Pointer to the current object	Pass the address of the object to a function.
* this			The actual object(dereferenced)	Return the object itself, for chaining or copying.*/

class Entity {

public:
	int x, y;

	Entity(int x, int y) {
		Entity* e = this; // 'this' is a pointer to the current object

		//e->x = x;
		//e->y = x; // THIS IS EQUALS TO THE ONE ABOVE
		this->x = x; // Assigning values to the current object's data members
		this->y = y;

		PrintEntity(this); // *this gives the actual object(not a pointer to it).
	}

	int getX() const {
		return x;
	}
};

void PrintEntity(const Entity* e) {
	std::cout << "Entity: (" << e->x << ", " << e->y << ")" << std::endl;
}

//int main() {
//	Entity entity(1, 2);
//
//	Entity* entityPtr = new Entity(5, 10);
//	PrintEntity(entityPtr);
//}