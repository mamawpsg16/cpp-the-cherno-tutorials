#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

// Save tasks to a binary file
void saveTasksToBinaryFile(const std::vector<std::string>& tasks, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file for writing.");
    }

    // Write the number of tasks to the file
    size_t tasksSize = tasks.size();
    file.write(reinterpret_cast<const char*>(&tasksSize), sizeof(tasksSize));
    if (!file) {
        throw std::runtime_error("Error: Failed to write tasks size to file.");
    }

    // Write each task to the file
    for (const auto& task : tasks) {
        size_t taskLength = task.size();
        file.write(reinterpret_cast<const char*>(&taskLength), sizeof(taskLength));
        if (!file) {
            throw std::runtime_error("Error: Failed to write task length to file.");
        }

        file.write(task.c_str(), taskLength);
        if (!file) {
            throw std::runtime_error("Error: Failed to write task content to file.");
        }
    }

    file.close();
}

// Read tasks from a binary file
void readTasksFromBinaryFile(const std::string& filename, std::vector<std::string>& tasks) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file for reading.");
    }

    // Read the number of tasks from the file
    size_t tasksSize;
    file.read(reinterpret_cast<char*>(&tasksSize), sizeof(tasksSize));
    if (!file) {
        throw std::runtime_error("Error: Failed to read tasks size from file.");
    }

    tasks.clear();
    tasks.reserve(tasksSize);

    // Read each task from the file
    for (size_t i = 0; i < tasksSize; ++i) {
        size_t taskLength;
        file.read(reinterpret_cast<char*>(&taskLength), sizeof(taskLength));
        if (!file) {
            throw std::runtime_error("Error: Failed to read task length from file.");
        }

        std::string task(taskLength, '\0');
        file.read(&task[0], taskLength);
        if (!file) {
            throw std::runtime_error("Error: Failed to read task content from file.");
        }

        tasks.push_back(task);
    }

    file.close();
}

int main() {
    try {
        // Define tasks and filename
        std::vector<std::string> tasks = { "C++", "NOTEPAD", "Binary File Example" };
        std::string filename = "tasks_file.dat";

        // Save tasks to binary file
        saveTasksToBinaryFile(tasks, filename);
        std::cout << "Tasks successfully saved to binary file.\n";

        // Read tasks from binary file
        std::vector<std::string> loadedTasks;
        readTasksFromBinaryFile(filename, loadedTasks);
        std::cout << "Tasks successfully loaded from binary file:\n";

        // Display loaded tasks
        for (const auto& task : loadedTasks) {
            std::cout << "- " << task << "\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
