#pragma once

namespace ft {
template <class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key, T> >
>
class map {
	public:
		typedef Key key_type;

};
} // namespace ft
