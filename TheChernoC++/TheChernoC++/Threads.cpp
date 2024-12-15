#include<iostream>
#include<thread>

static bool s_finished = false;

void doWork() {
	using namespace std::literals::chrono_literals; // FOR SLEEP
	std::cout << "Started thread id= " << std::this_thread::get_id() << '\n';
	while (!s_finished) {
		std::cout << "Started Working" << '\n';
		std::this_thread::sleep_for(1s);
	}
}
//int main() {
//	std::thread worker(doWork);
//	
//	std::cin.get();
//	s_finished = true;
//	worker.join();
//
//	std::cout << "Finished Working \n";
//	std::cout << "Main Thread" << '\n';
//}
