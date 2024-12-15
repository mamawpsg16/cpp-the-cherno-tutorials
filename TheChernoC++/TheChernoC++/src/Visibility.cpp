class Visibility {
protected:
	int X, Y;
	void print() {

};

public:
	Visibility() {
		X = 0;
	}
};

class Echo : public Visibility {
public:
	Echo() {
		X = 2;
	}
};