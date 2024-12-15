#include <iostream>
#include <string>

// Namespace for book management
namespace BookManagement {
    class Book {
    public:
        std::string title;
        void display() {
            std::cout << "Book Title: " << title << std::endl;
        }
    };
}

// Namespace for member management
namespace MemberManagement {
    class Member {
    public:
        std::string name;
        void display() {
            std::cout << "Member Name: " << name << std::endl;
        }
    };
}

//int main() {
//    // Creating an object of Book from BookManagement namespace
//    BookManagement::Book book;
//    book.title = "C++ Programming";
//
//    // Creating an object of Member from MemberManagement namespace
//    MemberManagement::Member member;
//    member.name = "John Doe";
//
//    // Displaying book and member information
//    book.display();
//    member.display();
//
//    return 0;
//}
