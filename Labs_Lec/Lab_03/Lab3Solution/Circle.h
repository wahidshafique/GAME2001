template<typename T>

class Circle {
public:
	Circle()
	{}
	Circle(T radius) {
		this->radius = radius;
	}
	T GetRadius() {
		return radius;
	}
	bool operator <(Circle target) {
		return (radius < target.GetRadius());
	}
	bool operator ==(Circle target) {
		return (radius == target.GetRadius());
	}
	bool operator >(Circle target) {
		return (radius > target.GetRadius());
	}
	template<typename T>
	friend std::ostream& operator<< (std::ostream& out, const Circle<T> &target);
	
private:
	T radius;
};