#include <iostream>
#include <string_view>

static uint32_t s_allocCount = 0;

// Custom new operator to count allocations
//void* operator new(size_t size) {
//    s_allocCount++;
//    std::cout << "Allocating size: " << size << " bytes\n";
//    return malloc(size);
//}
//
//// Function to print a name using std::string_view
//void printName(const std::string_view name) {
//    std::cout << "Hello " << name << '\n';
//}

//int main() {
//    // Use a fixed-size character array instead of std::string
//    char fullName[50] = "Kevin Mensah"; // Fixed-size buffer
//
//    // Print the full name
//    printName(fullName); // Pass char array as std::string_view
//
//    // Create substrings using std::string_view
//    std::string_view firstName(fullName, 5); // "Kevin"
//    std::string_view lastName(fullName + 6, 6); // "Mensah"
//
//    // Print first and last names
//    printName(firstName);
//    printName(lastName);
//
//    // Output total allocations made
//    std::cout << s_allocCount << " allocations" << "\n";
//
//    return 0;
//}
