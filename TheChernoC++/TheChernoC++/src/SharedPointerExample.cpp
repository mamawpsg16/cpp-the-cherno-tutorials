#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created.\n"; }
    ~MyClass() { std::cout << "MyClass destroyed.\n"; }
};

//int main() {
//    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
//    {
//        std::shared_ptr<MyClass> ptr2 = ptr1; // ptr2 shares ownership with ptr1
//        std::cout << "Use count: " << ptr1.use_count() << "\n"; // Outputs 2
//    } // ptr2 goes out of scope here, use count decreases
//
//    std::cout << "Use count after ptr2 goes out of scope: " << ptr1.use_count() << "\n"; // Outputs 1
//    return 0;
//}
