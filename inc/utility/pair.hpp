#pragma once

/*
**	https://www32.cplusplus.com/reference/utility/pair/
*/

namespace ft {
template <class T1, class T2>
class pair {
	public:
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		// default constructor
		pair(void) : first(first_type()), second(second_type()) {}

		// copy constructor
		template<class U, class V>
		pair(const pair<U, V> &rhs) {
			if (this != &rhs) {
				first = rhs.first;
				second = rhs.second;
			}
		}

		// initialization constructor
		pair(first_type a, second_type b) {
			first = a;
			second = b;
		}

		~pair(void) {}

		pair	&operator=(const pair &x) {
			if (this != &x) {
				first = x.first;
				second = x.second;
			}
			return *this;
		}
};
	// relational operators
	template <class T1, class T2>
	bool	operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (lhs.first == rhs.first) && (lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool	operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool	operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (lhs.first < rhs.first) ||
			(!(rhs.first < lhs.first) && (lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool	operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool	operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool	operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y) {
		return pair<T1, T2>(x, y);
	}

	template <typename T, typename U>
	std::ostream	&operator<<(std::ostream &o, pair<T, U> const &rhs) {
		o << rhs.first << "(" << rhs.second << ")";
		return o;
	}

} // namespace ft
