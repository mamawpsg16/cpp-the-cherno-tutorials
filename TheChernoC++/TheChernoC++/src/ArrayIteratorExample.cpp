#include <iostream>

class ArrayIterator {
public:
    ArrayIterator(int* ptr) : m_ptr(ptr) {}

    // Pre-increment (triggered by ++start)
    ArrayIterator& operator++() {
        std::cout << "PRE FIX" << '\n';
        m_ptr++;
        return *this;
    }

    // Post-increment (triggered by start++)
    ArrayIterator operator++(int) {
        std::cout << "POST FIX" << '\n';
        ArrayIterator temp = *this;  // Copy current iterator
        m_ptr++;
        return temp;  // Return the old iterator
    }

    int& operator*() {
        return *m_ptr;
    }

    bool operator!=(const ArrayIterator& other) const {
        return m_ptr != other.m_ptr;
    }

private:
    int* m_ptr;  // Pointer to array element
};

// Test with an array
//int main() {
//    int numbers[] = { 10, 20, 30, 40, 50 };
//    ArrayIterator start(numbers);  // Iterator at numbers[0]
//    ArrayIterator end(numbers + 5);  // Past-the-end iterator
//
//    std::cout << "Using pre-increment (++start):" << std::endl;
//    while (start != end) {
//        std::cout << *start << " ";
//        ++start;  // Pre-increment
//    }
//
//    std::cout << "\nRe-testing with post-increment (start++):" << std::endl;
//    start = ArrayIterator(numbers);  // Reset to the beginning
//    std::cout << "START " << *start << '\n';
//    std::cout << "END " << *end << '\n';
//    while (start != end) {
//        std::cout << *start << " ";
//        start++;  // Post-increment
//    }
//
//    return 0;
//}
