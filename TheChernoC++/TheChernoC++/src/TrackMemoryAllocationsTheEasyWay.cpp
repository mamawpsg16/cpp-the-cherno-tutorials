#include <iostream>

struct AllocationMetrics {
	uint32_t totalAllocated = 0;
	uint32_t totalFreed = 0;

	uint32_t currentUsage() {
		return totalAllocated - totalFreed ;
	}
};

static AllocationMetrics s_allowMetrics;

//void* operator new(size_t size) {
//	s_allowMetrics.totalAllocated += size;
//
//	return malloc(size);
//}
//
//void operator delete(void* memory, size_t size) {
//	s_allowMetrics.totalFreed += size;
//
//	return free(memory);
//}

static void printMemoryUsage() {
	std::cout << "Memory Usage: " << s_allowMetrics.currentUsage() << "bytes \n";
}

struct Object {
	int x, y, z;
};

//int main() {
//	printMemoryUsage();
//	std::string string = "kevin";
//	printMemoryUsage();
//	{
//		printMemoryUsage();
//		std::unique_ptr<Object> obj = std::make_unique<Object>();
//		printMemoryUsage();
//	}
//
//	printMemoryUsage();
//
//}