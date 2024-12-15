#include <iostream>
#include <memory>

class Foo {
public:
    Foo() { std::cout << "Foo constructed" << std::endl; }
    ~Foo() { std::cout << "Foo destroyed" << std::endl; }
    void doSomething() {
        std::cout << "Foo is doing something!" << std::endl;
    }
};

class Bar {
private:
    std::shared_ptr<Foo> pFoo;
public:
    Bar() {
        pFoo = std::make_shared<Foo>();  // Foo is created
    }

    std::shared_ptr<Foo> getFoo() {
        return pFoo;  // Return shared_ptr (shared ownership)
    }
};

//int main() {
//    Bar bar;
//
//    // Get shared_ptr from Bar
//    std::shared_ptr<Foo> foo1 = bar.getFoo();
//    foo1->doSomething();  // Calls Foo's method
//
//    {
//        std::shared_ptr<Foo> foo2 = bar.getFoo();  // Another shared_ptr sharing ownership
//        foo2->doSomething();
//        std::cout << "Reference count: " << foo2.use_count() << std::endl;
//    }  // foo2 goes out of scope here
//
//    std::cout << "Reference count after foo2 goes out of scope: " << foo1.use_count() << std::endl;
//
//    // foo1 goes out of scope and Foo will be destroyed here
//
//    return 0;
//}
