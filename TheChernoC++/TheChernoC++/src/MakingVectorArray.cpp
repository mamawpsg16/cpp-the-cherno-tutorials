#include <iostream>
#include "Array.h"
#include "Vector.h"

// Template function to print the contents of a Vector
// It iterates through the Vector and prints each element
// using the subscript operator.
template<typename T>
void  printVector(const Vector<T>& vector) {
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << '\n';
    }
}

// A simple 3D vector structure with x, y, z coordinates
// and a dynamically allocated memory block.
struct Vector3 {
    float x = 0.0f, y = 0.0f, z = 0.0f;  // 3D coordinates
    int* m_memoryBlock = nullptr;        // Pointer to dynamically allocated memory

    // Default constructor initializes memory block.
    Vector3() {
        m_memoryBlock = new int[5];
    }

    // Constructor to initialize with a scalar value.
    Vector3(float scalar) : x(scalar), y(scalar), z(scalar) {
        m_memoryBlock = new int[5];
    }

    // Constructor to initialize with specific x, y, z values.
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {
        m_memoryBlock = new int[5];
    }

    // Copy constructor - deleted to prevent copying.
    Vector3(const Vector3& other) = delete;

    // Move constructor - transfers ownership of memory block.
    Vector3(Vector3&& other) noexcept : x(other.x), y(other.y), z(other.z) {
        m_memoryBlock = other.m_memoryBlock;
        other.m_memoryBlock = nullptr; // Nullify source pointer to avoid double delete
        std::cout << "Move Constructor" << '\n';
    }

    // Copy assignment operator - deleted to prevent copying.
    Vector3& operator=(const Vector3& other) = delete;

    // Move assignment operator - transfers ownership and cleans up the source.
    Vector3& operator=(Vector3&& other) noexcept {
        if (this != &other) {  // Check for self-assignment
            delete[] m_memoryBlock;  // Free existing memory
            m_memoryBlock = other.m_memoryBlock;
            other.m_memoryBlock = nullptr;

            x = other.x;
            y = other.y;
            z = other.z;
            std::cout << "Move Assignment" << '\n';
        }
        return *this;
    }

    // Destructor to free allocated memory.
    ~Vector3() {
        delete[] m_memoryBlock;
        std::cout << "Vector3 Destroyed" << '\n';
    }
};

// Template function to print Vector3 objects stored in a Vector.
template<typename T>
void printVector3(const Vector<Vector3>& vector) {
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i].x << vector[i].y << vector[i].z << '\n';
    }
}

// Overloaded stream operator for Vector3 to print x, y, z.
std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << v.x << ", " << v.y << ", " << v.z;
    return os;
}

// Main function to demonstrate the usage of Array and Vector with Vector3 objects.
//int main() {
//    // Array of fixed size initialized with string values.
//    Array<std::string, 2> names;
//    names[0] = "Kevin";
//    names[1] = "Cherno";
//
//    // Vector to store Vector3 objects.
//    {
//        Vector<Vector3> vector3;
//
//        // Emplace Vector3 objects directly into the Vector (construct in place).
//        vector3.emplaceBack(1.0f);
//        vector3.emplaceBack(1, 2, 3);
//        vector3.emplaceBack();
//        vector3.emplaceBack(4, 5, 6);
//
//        // Print contents of vector3
//        printVector(vector3);
//
//        // Remove last two elements from the vector
//        vector3.popBack();
//        vector3.popBack();
//
//        printVector(vector3);
//
//        // Add more Vector3 objects
//        vector3.emplaceBack(7, 8, 9);
//        vector3.emplaceBack(10, 11, 12);
//
//        // Clear all elements from the vector
//        vector3.clear();
//        printVector(vector3);
//
//        // Add elements again after clearing
//        vector3.emplaceBack(7, 8, 9);
//        vector3.emplaceBack(10, 11, 12);
//
//        // Print the final contents
//        printVector(vector3);
//
//        std::cout << "----------------" << '\n';
//
//        // Vector to store integers
//        Vector<int> vectorInt;
//        vectorInt.pushBack(1);
//        vectorInt.emplaceBack(2);
//        vectorInt.pushBack(5);
//        printVector(vectorInt);
//
//        vectorInt.emplaceBack(7);
//        vectorInt.clear();
//        printVector(vectorInt);
//    }
//}
