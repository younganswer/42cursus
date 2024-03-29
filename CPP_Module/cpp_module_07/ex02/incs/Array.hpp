#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
	private:
		unsigned int	_size;
		T				*_arr;

	public:
		Array(void);
		~Array(void);
		Array(unsigned int n);
		Array(const Array<T> &ref);
		Array<T>	&operator=(const Array<T> &rhs);
		
		// Overload
		T	&operator[](unsigned int idx) throw(std::exception);
		T	&operator[](unsigned int idx) const throw(std::exception);

		// Util
		unsigned int	size(void) const;

		// Exception: Out of range
		class OutOfRangeException: public std::exception {
			public:
				OutOfRangeException(void);
				virtual ~OutOfRangeException(void) throw();
				virtual const char *what(void) const throw();
		};
};

template <typename T>
Array<T>::Array(void): _size(0), _arr(NULL) {}

template <typename T>
Array<T>::~Array(void) {
	if (this->_arr) {
		delete[] this->_arr;
	}
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n), _arr(new T[n]) {}

template <typename T>
Array<T>::Array(const Array<T> &ref): _arr(new T[ref.size()]), _size(ref.size()) {
	for (unsigned int i = 0; i < this->_size; i++) {
		this->_arr[i] = ref[i];
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs) {
	if (this != &rhs) {
		this->~Array();
		new (this) Array<T>(rhs);
	}
	return (*this);
}

// Overload
template <typename T>
T	&Array<T>::operator[](unsigned int idx) throw(std::exception) {
	if (0 < idx && this->_size <= idx) {
		throw typename Array<T>::OutOfRangeException();
	}
	return (this->_arr[idx]);
}

template <typename T>
T	&Array<T>::operator[](unsigned int idx) const throw(std::exception) {
	if (0 < idx && this->_size <= idx) {
		throw typename Array<T>::OutOfRangeException();
	}
	return (this->_arr[idx]);
}

// Util
template <typename T>
unsigned int	Array<T>::size(void) const { return (this->_size); }

// Exception: Out of range
template <typename T>
Array<T>::OutOfRangeException::OutOfRangeException(void) {}

template <typename T>
Array<T>::OutOfRangeException::~OutOfRangeException(void) throw() {}

template <typename T>
const char	*Array<T>::OutOfRangeException::what(void) const throw() {
	return ("Out of range");
}

#endif