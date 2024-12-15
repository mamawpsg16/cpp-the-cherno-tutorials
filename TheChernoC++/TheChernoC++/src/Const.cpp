class ConstantExample {
private:
	int m_X, m_Y;
	//const int* m_X, m_Y;
	int var; // MUTABLE ALLOWS CONSTANT FUNCTIONS TO MUTATE THE VARIABLE
public:
	int getM() const {
	//const int* const getM() const {
		//m_X = 2; ERROR CANNOT CHANGE THE m_X
		return m_X;
	}
};
