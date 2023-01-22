#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array() : _array(new T[0]), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array &src) : _array(new T[src._size]), _size(src._size) {
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		~Array() { delete [] _array; }

		Array &operator=(const Array &rhs) {
			if (this != &rhs) {
				delete [] _array;
				_array = new T[rhs._size];
				_size = rhs._size;
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		}

		T &operator[](unsigned int i) {
			if (i >= _size)
				throw OutOfRangeException();
			return _array[i];
		}

		unsigned int size() const { return _size; }

		class OutOfRangeException : public std::exception {
			const char *what() const throw() { return "Index is Out of range"; }
		};
};

#endif