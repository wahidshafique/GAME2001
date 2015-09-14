#include <iostream>
using namespace std;

template<class T>
class Rectangle {
	T width;
	T height;
	T area = 0;
public:
	T getWidth() { return width; };
	T getHeight() { return height; };
	Rectangle(T a, T b) {
		width = a;
		height = b;
		area = a * b;
	}
	friend bool operator<= (Rectangle &lhs, Rectangle &rhs) {
		return lhs.area <= rhs.area;
	}
};

template<class T>
T mid(T val1, T val2, T val3) {
	if (val2 <= val1 && val1 <= val3)
		return val1;
	if (val1 <= val2 && val2 <= val3)
		return val2;
	if (val1 <= val3 && val3 <= val2)
		return val3;
}

int main() {
	Rectangle <double> rect1(1.9, 2.9);
	Rectangle <double> rect2(300.89, 2.7);
	Rectangle <double> rect3(20, 9);

	mid(rect1, rect2, rect3);

}