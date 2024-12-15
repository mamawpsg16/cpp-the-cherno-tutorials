#include<iostream>
struct Entity {
	int x, y;
};
//int main() {
//	//int a = 50;
//	//double value = a; // IMPLICITLY CONVERTED TO DOUBLE SO THE MEMORY IS DIFFERENT
//	//double value = *(double*)&a;// TYPE PUNNING  (NOT SAFE) 
//	//std::cout << value << '\n';
//
//	Entity e = { 1, 2 };
//	int* position = (int*)& e;
//	int y = *(int*)((char*) & e + 4);
//
//	std::cout << y << '\n';
//	std::cout << position[0] << ', ' << position[1] << '\n';
//}