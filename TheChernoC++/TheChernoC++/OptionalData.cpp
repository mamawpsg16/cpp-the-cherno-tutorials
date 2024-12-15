#include <iostream>
#include <optional>
#include <string>
#include <fstream>

// optional can be used as the return type of a factory that may fail
std::optional<std::string> create(bool b)
{
    if (b)
        return "Godzilla";
    return {};
}

void createAndWriteIntoFile() {
    // Create and open a text file
    std::ofstream MyFile("abc.txt");

    // Check if the file was opened successfully
    if (!MyFile) {
        std::cerr << "Error opening file!" << std::endl;
        return; // Exit the function if the file cannot be opened
    }

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough! V0";
    MyFile << "Files can be tricky, but it is fun enough! V1";
    MyFile << "Files can be tricky, but it is fun enough! V2";

    // Close the file
    MyFile.close();
}

std::string openAndReadFile(const std::string& filename) {
    // Create a text string to store the file content
    std::string myText;
    std::string line;

    // Open the text file
    std::ifstream MyReadFile(filename);

    // Check if the file was opened successfully
    if (!MyReadFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return ""; // Return an empty string if the file cannot be opened
    }

    // Use a while loop together with getline() to read the file line by line
    while (std::getline(MyReadFile, line)) {
        myText += line + "\n"; // Append each line and add a newline character
    }

    // Close the file
    MyReadFile.close();

    return myText; // Return the complete text as a string
}

// std::nullopt can be used to create any (empty) std::optional
auto create2(bool b)
{
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}

std::optional<std::string> readFileAsString(const std::string& filepath) {
    std::ifstream stream(filepath);
    if (stream) {
        std::string result;
        std::getline(stream, result);

        stream.close();

        return result;
    }
    return {};
}
//int main()
//{
    /*createAndWriteIntoFile();
    std::string filename = "abc.txt";
    std::string fileContent = openAndReadFile(filename);
    std::cout << "Content of " << filename << ":\n" << fileContent;

    std::cout << "create(false) returned "
        << create(false).value_or("empty") << '\n';*/

    // optional-returning factory functions are usable as conditions of while and if
    /*if (auto str = create2(true))
        std::cout << "create2(true) returned " << *str << '\n';*/

//    std::optional<std::string> data = readFileAsString("1.txt");
//    std::string value = data.value_or("Not present");
//    std::cout << value << "value" << '\n';
//    std::cout << data.value() << "\n";
//    if (data) {
//        std::cout << "File read sucessfully \n";
//    }
//    else {
//        std::cout << "File could not be opened \n";
//    }
//
//}