#include <iostream>
#include <vector>

struct Vertex {
	float x, y, z;

	Vertex(float x, float y, float z) : x(x), y(y) , z(z){}

	Vertex(const Vertex& other) : x(other.x), y(other.y), z(other.z) {
		std::cout << "Copied!" << '\n';
	}
};

std::ostream& operator<<(std::ostream& os, const Vertex& v) {
	os << "Vertex(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

//int main() {
//	std::vector<Vertex> vertices;
//	vertices.reserve(3);
//	//vertices.push_back(Vertex(1, 2, 3)); // INSTEAD OF CALLING THE CONSTRUCTOR
//	//vertices.push_back(Vertex(4, 5, 6));
//	//vertices.push_back(Vertex(7, 8, 9));
//	vertices.emplace_back(4, 5, 6);
//	vertices.emplace_back(7, 8, 9);
//	vertices.emplace_back(1, 2, 3); // DO THIS INSTEAD
//
//	for (Vertex& v: vertices)
//	{
//		std::cout << v << '\n';
//	}
//}