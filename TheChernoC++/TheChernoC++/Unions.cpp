#include <iostream>
#include <string.h>

struct Vector2 {
    float x, y;
};

struct Vector4 {
    union {
        struct {
            float x, y, z, w;
        };
        struct {
            Vector2 a, b; // 'a' and 'b' will overlap with 'x', 'y', 'z', 
        };
    };
};

void printVector2(const Vector2& vector2) {
    std::cout << vector2.x << ", " << vector2.y << '\n';
}

struct book1_t {
    char title[50];
    char author[50];
    union {
        float dollars; // Price in dollars
        int yen;      // Price in yen
    } price;
};

struct book2_t {
    char title[50];
    char author[50];
    union {
        float dollars; // Price in dollars
        int yen;      // Price in yen
    };
};
//int main() {
//    // Using the constructor for proper initialization
//    Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f };
//
//    // Accessing 'a' and 'b' after initializing 'x', 'y', 'z', and 'w'
//    printVector2(vector.a); // This may not yield expected results
//    printVector2(vector.b); // This may not yield expected results
//
//    // Modify one member
//    vector.z = 500;
//
//    std::cout << "---------------- \n";
//
//    // Accessing 'a' and 'b' again after modifying 'z'
//    printVector2(vector.a); // Still may not yield expected results
//    printVector2(vector.b); // Same here
//    std::cout << "---------------- \n";
//    // Initialize book1 using the struct book1_t
//    struct book1_t book1;
//
//    // Setting values for book1
//    strcpy_s(book1.title, "Hello World");
//    strcpy_s(book1.author, "John Doe");
//    book1.price.dollars = 29.99; // Set price in dollars
//
//    // Print details of book1
//    printf("Book 1:\n");
//    printf("Title: %s\n", book1.title);
//    printf("Author: %s\n", book1.author);
//    printf("Price in Dollars: $%.2f\n", book1.price.dollars);
//
//    // Initialize book2 using the struct book2_t
//    struct book2_t book2;
//
//    //Setting values for book2
//    strcpy_s(book2.title, "Goodbye World");
//    strcpy_s(book2.author, "Jane Doe");
//    book2.yen = 3000; // Set price in yen
//
//    // Print details of book2
//    printf("\nBook 2:\n");
//    printf("Title: %s\n", book2.title);
//    printf("Author: %s\n", book2.author);
//    printf("Price in Yen: ¥%d\n", book2.yen);
//    return 0;
//}
