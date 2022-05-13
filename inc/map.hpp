#ifndef INC_MAP_HPP_
#define INC_MAP_HPP_

namespace ft {
template <class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<std::pair<const Key, T> > // change std::pair by ft::pair
>
class map {
	public:
		typedef Key key_type;

};
} // namespace ft

#endif // INC_MAP_HPP_
