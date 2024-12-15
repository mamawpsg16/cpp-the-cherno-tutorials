#include <iostream>
#include <vector>

struct Vertex {
	float x, y, z;
};

static std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
	stream << "Vertex: " << "x = " << vertex.x << " y = " << vertex.y << " z = " << vertex.z << '\n';
	return stream;
}

void function(const std::vector<Vertex> vertices) {

}
//int main() {
//	//Vertex vertices[5]; // NORMAL WAY
//	//Vertex* vertices = new Vertex[5]; // IN THE HEAP BUT STILL NOT FLEXIBLE;
//	std::vector<Vertex> vertices;
//	vertices.push_back({ 1, 2, 3 });
//	vertices.push_back({ 4, 5, 6 });
//
//	function(vertices);// EXAMPLE OF PASSING VECTOR IN A FUNCTION
//	
//	//for (int i = 0; i < vertices.size(); i++)
//	//{
//	//	//std::cout << vertices[i] << '\n';
//	//	//std::cout << vertices.at(i) << '\n';
//	//}
//
//	vertices.erase(vertices.begin()+1);
//	for (Vertex& v : vertices)
//	{
//		std::cout << v << '\n';
//	}
//}