#include <iostream>
#ifdef _DEBUG
	#define  WAIT std::cin.get()
	#define LOG(x) std::cout << x << '\n';
#endif

//int main() {
//	LOG("Hello Btch");
//	WAIT;
//}