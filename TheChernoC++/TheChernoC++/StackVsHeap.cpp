#include <iostream>

struct MyStruct
{
	float x, y, z;
	MyStruct() : x(10), y(11), z(12){}
};

//int main() {
//	// STACK
//	int a = 5; 
//	int array[5];
//
//	array[0] = 1;
//	array[1] = 2;
//	array[2] = 3;
//	array[3] = 4;
//	array[4] = 5;
//
//	//MyStruct str;
//
//
//	// HEAP
//	int* b = new int;
//	*b = 10;
//	int* array2 = new int[5];
//	array2[0] = 1;
//	array2[1] = 2;
//	array2[2] = 3;
//	array2[3] = 4;
//	array2[4] = 5;
//
//	MyStruct* heapStruct = new MyStruct;
//
//
//	std::cout << "a= " << a << '\n';
//	std::cout << "b= " << *b << '\n';
//	delete b;
//	delete[] array2;
//	delete heapStruct;
//}