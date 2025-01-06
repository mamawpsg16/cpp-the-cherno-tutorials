#include <iostream>
#include <memory>
#include <vector>
#include <string>

class File {
private:
    std::string filename;

public:
    File(const std::string& name) : filename(name) {
        std::cout << "File '" << filename << "' opened.\n";
    }
    ~File() {
        std::cout << "File '" << filename << "' closed.\n";
    }
    void read() const {
        std::cout << "Reading file: " << filename << "\n";
    }
};

class FileManager {
    std::vector<std::shared_ptr<File>> openFiles;

public:
    void openFile(const std::string& name) {
        std::shared_ptr<File> file = std::make_shared<File>(name);
        openFiles.push_back(file);
    }

    void readFiles() const {
        for (const auto& file : openFiles) {
            file->read();
        }
    }
};

//int main() {
//    FileManager manager;
//    manager.openFile("document.txt");
//    manager.openFile("hello.txt");
//    //manager.openFile("report.pdf");
//
//    std::cout << "Processing files...\n";
//    manager.readFiles();
//
//    // Files are automatically closed when FileManager is destroyed
//    return 0;
//}
