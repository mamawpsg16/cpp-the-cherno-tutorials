#include <iostream>
#include <tuple>
#include <string>

std::tuple<std::string, int> createPerson() {
	return { "Cherno", 15 };
}
//int main() {
	//std::tuple<std::string, int> person = createPerson();

	//DEFAULT WAY
	//auto person = createPerson();
	//std::string& name = std::get<0>(person);
	//int age = std::get<1>(person);

	//SECOND WAY
	//std::string name1;
	//int age1;
	//std::tie(name1, age1) = createPerson();
	
	//THIRDWAY
	//auto [name2, age2] = createPerson();
	//std::cout << name2 << age2 << '\n';
//}
