#include <iostream>
#include <string>

#define LOG(x) std::cout << x << '\n';

using String = std::string;  // Alias for std::string
//typedef std::string String; // Alias older way

struct Vector2 {
	float x, y;

	Vector2(float x, float y): x(x), y(y){}

	Vector2 add(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
		//return operator+(other);
	}

	Vector2 operator+(const Vector2& other) const {
		return add(other);
	}

	Vector2 multiply(const Vector2& other) const {
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator*(const Vector2& other) const {
		return multiply(other);
	}

	bool operator==(const Vector2& other) const {
		return  x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const {
		return  !(*this == other);
	}


};

std::ostream& operator<<(std::ostream& stream, const Vector2& other) {
	stream << "x = " << other.x << ", " << "y = " << other.y;
	return stream;
}

//int main() {
//
//	Vector2 position(4.0f, 4.0f);
//	Vector2 speed(0.5f, 1.5f);
//	Vector2 powerup(1.1f, 1.1f);
//
//	Vector2 result = position.add(speed.multiply(powerup)); //0.55 // 1.65  -  // 4.55 // 5.65
//	Vector2 result1 = position + speed;// *powerup;
//	Vector2 result2 = position.add(speed.multiply(powerup));
//	LOG(result.x);
//	LOG(result.y);
//	LOG(result1.x);
//	LOG(result1.y);
//
//	std::cout << result << '\n';
//	bool isEqual = result == result1;
//	bool isEqualV1 = result == result2;
//	bool isNotEqual = result != result1;
//
//	std::cout << "IS VECTORS RESULT &  RESULT1 IS EQUAL ? " << isEqual << '\n';
//	std::cout << "IS VECTORS RESULT &  RESULT2 IS EQUAL ? " << isEqualV1 << '\n';
//	std::cout << "IS VECTORS RESULT &  RESULT1 IS NOT EQUAL ? " << isNotEqual << '\n';
//
//}