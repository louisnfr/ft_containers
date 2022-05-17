#pragma once

namespace ft {
template <class T>
class random_access_iterator {
	public:
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T			value_type;
		typedef ptrdiff_t	difference_type;
		typedef T*			pointer;
		typedef T&			reference;
	private:
		pointer	_p;
};
} // namespace ft
