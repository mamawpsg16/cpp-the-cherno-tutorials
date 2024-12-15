#include <iostream>
#include <vector>

void helloWorld(int value) {
	std::cout << "HELLO WORLD " << value <<  '\n';
}

void printNumber(int number) {
	std::cout << "Number:" << number << '\n';
}
static void forEach(const std::vector<int>& numbers, void(*printValue)(int)) {
	for (auto& number: numbers)
	{
		printValue(number);
	}
}

//int main() {
//	//THIS TYPEDEF AND USING ONLY BE A TYPE
//	/*typedef void(*newType1)();*/
//	//using newType1 = void(*)(int);
//	
//	//auto type in a function =
//	 //void (*newType)(); // THIS WILL BE THE TYPE AND ALSO THE NAME OF THE VARIABLE
//
//	//GETTING THE MEMORY ADDRESS OR PONITER INSTEAD OF CALLING THE FUNCTION WITH PARENTHESIS ()
//	 //auto function = helloWorld;
//	 /*function();
//	 function();*/
//
//	 //newType  = helloWorld;
//	 //newType();
//	 //newType();
//
//	/*newType1 helloWorldFunc = helloWorld;
//	helloWorldFunc(8);*/
//
//	std::vector<int> numbers = { 1,2,3,4,5,6 };
//	//auto printNumberPointer = printNumber;
//	//forEach(numbers, printNumber);
//	forEach(numbers, [](int value){ std::cout << "Number:" << value << '\n'; });
//
//
//}