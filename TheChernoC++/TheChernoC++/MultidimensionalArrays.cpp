#include<iostream>
#include<array>


//int main() {
	//int* numbers = new int[50]; // ALREADY AN INTEGER WHEN ACCESS LIKE numbers[0] = 2
	//int** a2d = new int* [50]; // INTEGER POINTERS THIS  : numbers[0] = 2 // ERROR 
	//for (size_t i = 0; i < 50; i++)
	//{
	//	a2d[i] = new int[50];
	//}

	//for (size_t i = 0; i < 50; i++)
	//{
	//	delete[] a2d[i]; // DELETE THE INTEGERS
	//}
	//delete[] a2d; // DELETE THE POINTER
	//a2d[0][0]  = VALUE 

	//int*** a3d = new int** [50]; // INTEGER POINTERS THIS  : numbers[0] = 2 // ERROR 
	//for (size_t i = 0; i < 50; i++)
	//{
	//	a3d[i] = new int*[50];
	//	for (size_t j = 0; j < 50; j++)
	//	{
	//		a3d[i][j] = new int[50];
	//	}
	//}

	//a3d[0][0][0] = VALUE 

	//int** a2d = new int* [5]; // INTEGER POINTERS THIS  : numbers[0] = 2 // ERROR 
	//for (size_t i = 0; i < 5; i++)
	//{
	//	a2d[i] = new int[5];
	//}

	//for (size_t i = 0; i < 5; i++)
	//{
	//	for (size_t j = 0; j < 5; j++)
	//	{
	//		a2d[i][j] = 2;
	//	}
	//}

	//for (size_t i = 0; i < 5; i++)
	//{
	//	for (size_t j = 0; j < 5; j++)
	//	{
	//		std::cout << a2d[i][j] << '\n';
	//	}
	//}

	//for (size_t i = 0; i < 5; i++)
	//{
	//	delete[] a2d[i]; // DELETE THE INTEGERS
	//}
	//delete[] a2d; // DELETE THE POINTER

	//OPTIMAL WAY OF DOING 2DIMENSIONAL

//	int* array = new int[5 * 5]; // Allocate memory for a 5x5 array
//
//	// Initialize the array correctly
//	for (size_t j = 0; j < 5; j++) {
//		for (size_t i = 0; i < 5; i++) {
//			array[j * 5 + i] = 2; // Correctly access each element
//		}
//	}
//
//	// Print the array
//	for (size_t j = 0; j < 5; j++) {
//		for (size_t i = 0; i < 5; i++) {
//			std::cout << array[j * 5 + i] << ' '; // Print elements in row-major order
//		}
//		std::cout << '\n'; // New line after each row
//	}
//
//	delete[] array; // Free allocated memory
//
//}