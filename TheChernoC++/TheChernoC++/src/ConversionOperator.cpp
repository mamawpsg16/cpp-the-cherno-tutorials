#include <iostream>

template<typename T>
class ScopedPtr {
public:
	ScopedPtr() = default;
	ScopedPtr(T* ptr) : m_ptr(ptr){}
	~ScopedPtr() { delete m_ptr; }

	T* get() {
		return m_ptr;
	}
	
	operator bool() const { return m_ptr; }

	const T* get() const {
		return m_ptr;
	}
private:
	T* m_ptr = nullptr;
};

struct Orange {
	operator float() { return 5.5f; }
};

void printFloat(float value) {

}

struct Entity {
	float X = 0.0f, Y = 0.0f;
};

void processEntity(const ScopedPtr<Entity>& e) {
	if (!e) {

	}
}

//int main() {
//	//Orange orange;
//	//float f = orange;
//	//std::cout << f << '\n';
//	//std::cout << (float)orange << '\n';
//
//	ScopedPtr<Entity> e = new Entity();
//	Entity* entity = new Entity();
//
//	if (entity) {
//
//	}
//}