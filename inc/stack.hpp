#ifndef INC_STACK_HPP_
#define INC_STACK_HPP_

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
		container_type	c;

	public:
	// constructor

		explicit stack(const container_type &ctnr = container_type())
			: c(ctnr) {}

	// destructor

		virtual ~stack(void) {}

	// member functions

		// bool empty() const {}
		// size_type size() const {}
		// value_type& top() {}
		// const value_type& top() const {}
		// void push(const value_type& val) {}
		// void pop() {}

	// non-member function overloads

		// template <class T, class Container>
		// bool operator== (const stack<T,Container>& lhs,
		// 	const stack<T,Container>& rhs) {}

		// template <class T, class Container>
		// bool operator!= (const stack<T,Container>& lhs,
		// 	const stack<T,Container>& rhs) {}

		// template <class T, class Container>
		// bool operator<  (const stack<T,Container>& lhs,
		// 	const stack<T,Container>& rhs) {}

		// template <class T, class Container>
		// bool operator<= (const stack<T,Container>& lhs,
		// 	const stack<T,Container>& rhs) {}

		// template <class T, class Container>
		// bool operator>  (const stack<T,Container>& lhs,
		// 	const stack<T,Container>& rhs) {}

		// template <class T, class Container>
		// bool operator>= (const stack<T,Container>& lhs,
		// 	const stack<T,Container>& rhs) {}
};
}  // namespace ft

#endif  // INC_STACK_HPP_
