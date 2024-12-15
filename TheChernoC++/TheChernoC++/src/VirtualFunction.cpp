#include<iostream>

class Identity {
public:
	virtual std::string getName() {
		return "Identify \n";
	}
};

class Player1 : public Identity {
private:
	std::string m_name;
public:
	Player1(const std::string& name): m_name(name){}
	std::string getName() override {
		return m_name;
	}
};