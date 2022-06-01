#pragma once

/*
**	https://www32.cplusplus.com/reference/utility/pair/
*/

namespace ft
{
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
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

		// initialization constructor

		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		pair	&operator=(const pair &pr) {
			first = pr.first;
			second = pr.second;
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
} // namespace ft
