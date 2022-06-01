#pragma once

namespace ft {
template <class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<std::pair<const Key, T> >
> class map {
	public:
		typedef Key		key_type;
		typedef T		mapped_type;
		typedef std::pair<const Key, T> value_type;
		typedef Compare	value_compare;
		typedef Alloc	allocator_type;

		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		// typedef ft::random_access_iterator<T>			iterator;
		// typedef ft::random_access_iterator<const T>		const_iterator;
		// typedef ft::reverse_iterator<iterator>			reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t		size_type;

	private:

		// destructor

		virtual ~map(void) {}

};
} // namespace ft
