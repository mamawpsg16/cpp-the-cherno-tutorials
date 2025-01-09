#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void showTasks(const std::vector<std::string>& tasks)
{
    std::cout << "\nTo-Do List:" << std::endl;
    for (int i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}

void saveTasksBinary(const std::vector<std::string>& tasks, const std::string& filename)
{
    std::ofstream outputFile(filename, std::ios::binary);

    // Write the number of tasks
    size_t taskCount = tasks.size();
    outputFile.write(reinterpret_cast<const char*>(&taskCount), sizeof(taskCount));

    // Write each task's length and content
    for (const auto& task : tasks)
    {
        size_t length = task.size();
        outputFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
        outputFile.write(task.c_str(), length);
    }

    outputFile.close();
}

void loadTasksBinary(std::vector<std::string>& tasks, const std::string& filename)
{
    std::ifstream inputFile(filename, std::ios::binary);

    // Read the number of tasks
    size_t taskCount;
    inputFile.read(reinterpret_cast<char*>(&taskCount), sizeof(taskCount));

    // Read each task's length and content
    for (size_t i = 0; i < taskCount; ++i)
    {
        size_t length;
        inputFile.read(reinterpret_cast<char*>(&length), sizeof(length));

        std::string task(length, '\0');
        inputFile.read(&task[0], length);

        tasks.push_back(task);
    }

    inputFile.close();
}

//int main()
//{
//    std::vector<std::string> tasks;
//    std::string task;
//    char choice;
//
//    // Load existing tasks from binary file
//    loadTasksBinary(tasks, "tasks.dat");
//
//    do
//    {
//        std::cout << "\nA - Add a task" << std::endl;
//        std::cout << "V - View tasks" << std::endl;
//        std::cout << "Q - Quit" << std::endl;
//        std::cout << "Enter your choice: ";
//        std::cin >> choice;
//
//        switch (choice)
//        {
//        case 'A':
//        case 'a':
//            std::cout << "Enter a task: ";
//            std::cin.ignore(); // Clears the input buffer
//            getline(std::cin, task);
//            tasks.emplace_back(task);
//            break;
//        case 'V':
//        case 'v':
//            showTasks(tasks);
//            break;
//        }
//    } while (choice != 'Q' && choice != 'q');
//
//    // Save tasks to binary file
//    saveTasksBinary(tasks, "tasks.dat");
//
//    return 0;
//}
