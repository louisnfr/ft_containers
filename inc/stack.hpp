#ifndef INC_STACK_HPP_
#define INC_STACK_HPP_

#include "inc/vector.hpp"

namespace ft {
template <class T, class Container = ft::vector<T> >
class stack {
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	protected:
		container_type	under_ctr;

	public:
		explicit stack(const container_type &c = container_type()) : under_ctr(c) {}
};
}  // namespace ft

#endif  // INC_STACK_HPP_
