#include <iostream>
#include <future>
#include <thread>

int compute(int x) {
    return x * x;
}

void compute1(int x) {
    std::cout << "Result: " << x * x << std::endl;
}

int compute2(int x) {
    std::cout << "Starting compute function...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    return x * x;
}

//int main() {
//    std::cout << "START LUNCH ASYNC\n"; // 1st
//
//    // Launch `compute` asynchronously
//    std::future  future = std::async(std::launch::async, compute, 5);
//
//    // Wait for the result and print it
//    std::cout << "Result: " << future.get() << '\n'; // 2nd (blocks until result is ready)
//
//    std::cout << "END LUNCH ASYNC\n"; // 3rd
//
//    std::cout << "START DEFERRED ASYNC\n"; // 1st
//    // Launch the task with deferred policy
//    auto future1 = std::async(std::launch::deferred, compute2, 5);
//
//    std::cout << "Task created but not executed yet.\n";
//
//    // Trigger execution
//    std::cout << "Requesting result...\n";
//    int result = future1.get(); // compute() executes here
//    std::cout << "Result: " << result << '\n';
//
//    std::cout << "END DEFERRED ASYNC\n"; // 1st
//
//   // THREAD
//    std::cout << "START THREAD\n"; // 3rd
//    std::thread t(compute1, 5); // Create a thread running compute(5)
//    t.join(); // Wait for the thread to finish
//    std::cout << "END THREAD\n"; // 3rd
//    return 0;
//}
