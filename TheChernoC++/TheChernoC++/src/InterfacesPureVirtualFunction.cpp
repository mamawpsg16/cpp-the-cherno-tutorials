#include<iostream>

class Printable {
public:
	virtual std::string getClassName() = 0; //PURE VIRTUAL FUNCTION
};


class Identity1 : public Printable {
public:
	//virtual std::string getName() = 0; //PURE VIRTUAL FUNCTION
	virtual std::string getName() {
		return "Identity1";
	};

	std::string getClassName() override {
		return "CLASS Identity1";
	}
};

class Player2 : public Identity1 {
private:
	std::string m_name;
public:
	Player2(const std::string& name) : m_name(name) {}
	std::string getName() override {
		return m_name;
	}
	std::string getClassName() override {
		return "CLASS Player2";
	}
};