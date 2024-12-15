#include <string>
class Test {
private:
	std::string m_name;
	int m_age;
public:
	//SHOULD BE IN SAME ORDER
	Test() : m_name("Unknown"), m_age(0)  {}
	Test(std::string& name, int age) : m_name(name), m_age(age){}
};