#include "../incs/Point.hpp"

Point::Point(void): _x(0), _y(0) {}
Point::Point(const float x, const float y): _x(x), _y(y) {}
Point::Point(const Fixed &x, const Fixed &y): _x(x), _y(y) {}
Point::Point(const Point &point): _x(point._x), _y(point._y) {}
Point::~Point(void) {}

Point	&Point::operator=(const Point &point) {
	if (this != &point) {
		this->~Point();
		new (this) Point(point);
	}
	return (*this);
}

// Getter
Fixed		Point::getX(void) { return (this->_x); }
Fixed		Point::getY(void) { return (this->_y); }
const Fixed	&Point::getX(void) const { return (this->_x); }
const Fixed	&Point::getY(void) const { return (this->_y); }

bool			bsp(const Point a, const Point b, const Point c, const Point point);
static float	cross_product(const Point &p1, const Point &p2);

// Utils
bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	float	direction;

	return (
		(0 != (direction = cross_product(b-a, point-a)) && \
		0 < (direction * cross_product(c-b, point-b)) && \
		0 < (direction * cross_product(a-c, point-c)))
	);
}

static float	cross_product(const Point &p1, const Point &p2) {
	return (Fixed(p1.getX()*p2.getY() - p1.getY()*p2.getX()).toFloat());
}

// Operator Overload
const Point	Point::operator-(const Point &point) const {
	return (Point(this->_x-point._x, this->_y-point._y));
}