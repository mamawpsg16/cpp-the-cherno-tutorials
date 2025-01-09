#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void observe()
{
    std::cout << "gw.use_count() == " << gw.use_count() << "; ";
    // we have to make a copy of shared pointer before usage:
    if (std::shared_ptr<int> spt = gw.lock())
        std::cout << "*spt == " << *spt << '\n';
    else
        std::cout << "gw is expired\n";
}

struct Object {
    ~Object() {
        std::cout << "Deleted Object" << '\n';
    }
};

struct Manager {
    //std::shared_ptr<Object> obj;
    std::weak_ptr<Object> obj;

    void func() {
        if (std::shared_ptr<Object> sharedObj = obj.lock()) {

        }

        if (obj.expired()) {

        }

        std::cout << obj.use_count() << '\n';
    }
};

Manager manager;

/* BEST PRACTICES USING WEAK_PTR */
class B; // Forward declaration

class A {
public:
    std::shared_ptr<B> bPtr; // Shared pointer to B
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::weak_ptr<A> aPtr; // Weak pointer to A
    ~B() { std::cout << "B destroyed\n"; }
};


//int main()
//{
   /* {
        auto sp = std::make_shared<int>(42);
        gw = sp;

        observe();
    }

    observe();*/


    /* std::shared_ptr<Object> obj */
    //std::shared_ptr<Object> obj = std::make_shared<Object>();
    //{
    //    std::cout << "Object Count Before Sharing it to Manager " << obj.use_count() << '\n';
    //    Manager manager;
    //    manager.obj = obj;
    //    std::cout << "Object Count After Sharing it to Manager " << obj.use_count() << '\n';
    //}
    //std::cout << "Object Count After Out of scoped to Manager " << obj.use_count() << '\n';

    /* Object* obj */
    //{
    //    std::shared_ptr<Object> obj = std::make_shared<Object>();
    //    manager.obj = obj;
    //    manager.func();
    //}
    //manager.func();
    //std::cout << "Manager Object " << manager.obj << '\n';

    //auto a = std::make_shared<A>();
    //auto b = std::make_shared<B>();

    //a->bPtr = b; // A owns B
    //b->aPtr = a; // B observes A without owning it

//}