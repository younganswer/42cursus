#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		Fixed	_x;
		Fixed	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &point);
		~Point(void);
		Point	&operator=(const Point &point);

		// Getter
		Fixed		getX(void);
		Fixed		getY(void);
		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;

		// Operator Overload
		const Point	operator-(const Point &point) const;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif