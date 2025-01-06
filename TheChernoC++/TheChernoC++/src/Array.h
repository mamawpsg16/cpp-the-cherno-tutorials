#include <iostream>

template<typename T, size_t S>
class Array {
public:
	Array() = default;

	constexpr size_t size() const {
		return S;
	}

	T& operator[](size_t index) {
		return m_data[index];
	}

	// ONLY SHOULD BE ABLE READ THE DATA BUT NOT MODIFY IT
	const T& operator[](size_t index) const {
		return m_data[index];
	}

	T* data() {
		return m_data;
	}

	const T* data() const {
		return m_data;
	}
private:
	T m_data[S];
};
