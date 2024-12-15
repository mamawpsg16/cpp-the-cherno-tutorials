#include <memory>
#include <iostream>

class Foo {
public:
    void doSomething() {
        std::cout << "Foo is doing something!" << std::endl;
    }
};

//int main() {
//    std::unique_ptr<Foo> pFoo(new Foo());  // Create unique_ptr using new
//    pFoo->doSomething();  // Use the object
//    // No need to call delete, it will be automatically deleted when pFoo goes out of scope
//
//
//    std::unique_ptr<Foo> pFoo1 = std::make_unique<Foo>();  // Simplified version No `new` keyword needed
//    pFoo1->doSomething();  // Use the object
//    // No need to call delete, it will be automatically deleted when pFoo goes out of scope
//}
