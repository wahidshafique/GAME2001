#include <iostream>

using namespace std;

template<typename T>
T min(T lVal, T rVal) {
	if (lVal < rVal)
		return lVal;
	return rVal;
}

template<typename T>
T max(T lVal, T rVal) {
	if (lVal > rVal)
		return lVal;
	return rVal;
}

template<typename P>
class Circle
{
	private: 
		P radius;
	public:
		Circle() {
			//radius = 0;
		}
		Circle(P radiusValue) {
			radius = radiusValue;
		}
		P GetRadius() {
			return radius;
		}
		void SetRadius(P radiusValue) {
			radius = radiusValue;
		}
		bool operator >(Circle &circle) {
			return radius > circle.GetRadius();
		}
		bool operator <(Circle &circle) {
			return radius < circle.GetRadius();
		}
};


template<typename S>
int binarySearch(S arr[], int arrSize, S& key) {
	int lo = 0, mid, hi = arrSize - 1;
	S midVal;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		midVal = arr[mid];
		if (key < midVal)
			hi = mid - 1;
		else if (midVal < key)
			lo = mid + 1;
		else return mid;
	}
	return -1;
}

int main() {
	Circle<int> c1 = Circle<int>(5);
	Circle<int> c2 = Circle<int>(3);
	Circle<int> minCircle = min(c1, c2);
	Circle<int> maxCircle = max(c1, c2);
	cout << "Smallest circle is " << minCircle.GetRadius() << endl;
	cout << "Largest circle is " << maxCircle.GetRadius() << endl << endl;
	
	int myArray[5] = { 3, 4, 11, 14, 19 };
	int searchValue = 11;
	cout << "Position of " << searchValue << " is " << binarySearch(myArray, 5, searchValue) << endl;
	searchValue = 12;
	cout << "Position of " << searchValue << " is " << binarySearch(myArray, 5, searchValue) << endl;
	return 0;
}