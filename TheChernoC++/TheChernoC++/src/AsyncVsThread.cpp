#include <iostream>
#include <future>
#include <chrono>
#include <thread>

int compute() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate long computation
    return 42;
}

void printMessage() {
    std::cout << "Hello from std::thread!" << std::endl;
}


void handleRequest(int requestId) {
    std::cout << "Handling request " << requestId << " on thread " << std::this_thread::get_id() << std::endl;
    // Simulate processing time
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int performComplexTask(int taskId) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate long computation
    return taskId * 10; // Return some result based on taskId
}

//int main() {

    // ASYNC
    // EXAMPLE #!1
    //std::future<int> result = std::async(std::launch::async, compute); // Start async task
    //std::cout << "Waiting for result..." << std::endl;
    //int value = result.get(); // Get the result (blocks until it's ready)
    //std::cout << "Result from std::async: " << value << std::endl;

    //EXAMPLE #2
    //std::cout << "Starting tasks asynchronously..." << std::endl;

    //// Start tasks asynchronously
    //std::future<int> result1 = std::async(std::launch::async, performComplexTask, 1);
    //std::future<int> result2 = std::async(std::launch::async, performComplexTask, 2);

    //// Do other work while waiting for results
    //std::cout << "Main thread is free to do other work..." << std::endl;

    //// Retrieve results when needed
    //int value1 = result1.get(); // Blocks here if not yet finished
    //int value2 = result2.get(); // Blocks here if not yet finished

    //std::cout << "Results: " << value1 << ", " << value2 << std::endl;

    // THREAD -  The main thread is blocked until all requests are handled. It cannot do anything else during this time

    //EXAMPLE #1
    //std::thread t(printMessage); // Create a new thread
    //t.join(); // Wait for the thread to finish

    //EXAMPLE #2
    //const int numRequests = 5;
    //std::vector<std::thread> threads;

    //for (int i = 0; i < numRequests; ++i) {
    //    threads.emplace_back(handleRequest, i); // Create a new thread for each request
    //}

    //for (auto& t : threads) {
    //    t.join(); // Wait for all threads to complete
    //}
//}
