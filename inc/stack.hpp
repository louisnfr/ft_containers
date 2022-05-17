#pragma once

#include "inc/vector.hpp"

namespace ft {
template <class T, class Container = ft::vector<T> >
class stack {
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;

	protected:
		container_type	_c;

	public:
	// constructor

		explicit stack(const container_type &ctnr = container_type())
			: _c(ctnr) {}

	// destructor

		virtual ~stack(void) {}

	// member functions

		bool empty(void) const {
			return (_c.empty());
		}

		size_type size(void) const {
			return (_c.size());
		}

		value_type& top(void) {
			return (_c.back());
		}

		const value_type& top(void) const {
			return (_c.back());
		}

		void push(const value_type& val) {
			_c.push_back(val);
		}

		void pop() {
			_c.pop_back();
		}

	// non-member function overloads

		friend bool operator==(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs) {
				return (lhs.container == rhs.container);
		}

		friend bool operator!=(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs) {
				return (lhs.container == rhs.container);
		}

		friend bool operator<(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs) {
				return (lhs.container == rhs.container);
		}

		friend bool operator<=(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs) {
				return (lhs.container == rhs.container);
		}

		friend bool operator>(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs) {
				return (lhs.container == rhs.container);
		}

		friend bool operator>=(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs) {
				return (lhs.container == rhs.container);
		}
};


} // namespace ft
