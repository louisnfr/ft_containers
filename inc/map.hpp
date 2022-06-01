#pragma once

/*
**	https://m.cplusplus.com/reference/map/map
*/

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
		typedef Compare	key_compare;
		typedef Alloc	allocator_type;

		class value_compare {
			friend class map;
			protected:
				Compare comp;
				explicit value_compare(Compare c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator()(const value_type& x, const value_type& y) const {
					return comp(x.first, y.first);
				}
		};

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
		allocator_type	_alloc;
		key_compare		_key_compare;
		size_type		_size;
		pointer			_root;

	public:
		// empty constructor

		explicit map(const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _key_compare(comp), _root(NULL), _size(0) {}

		// destructor

		virtual ~map(void) {}
};
} // namespace ft
