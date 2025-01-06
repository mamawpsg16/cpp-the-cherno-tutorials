#include <iostream>
class Entity {
public:
	Entity() = default;
	const std::string getName() const{
		return m_name;
	}

	void printType() {
		std::cout << "Entity" << '\n';
	}
private:
	Entity* m_parent;
	std::string m_name;
};

struct EntityData {
	Entity* m_parent; //0
	std::string m_name; // 8
};

const std::string& entryGetName(const EntityData* self) {
	//self == nullptr

	uint64_t offset = offsetof(EntityData, m_name);

	return self->m_name;
}

void entityPrintType(EntityData* self) {
	//self == nullptr but where not actually using the self
	std::cout << "Entity" << '\n';
}
//int main() {
//	Entity* entity = nullptr;
//	//void* value = NULL; // NULL = 0 
//	//entity->getName(); // ERROR IF ENTITY IS NULL OR NULLPTR
//	//entity->printType(); // GOOD BECAUSE WERE NOT USING THE SELF OR THE THIS IN THIS
//
//	uint64_t offset = offsetof(EntityData, m_name);
//	//offset = (uint64_t) & ((EntityData*)nullptr)->m_name;
//	std::cout << "offset of m_name: " << offset << '\n';
//}