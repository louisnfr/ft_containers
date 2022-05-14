#pragma once

namespace ft {
template<class Iterator>
class iterator_traits {
	public:
		
};

template<class T>
class iterator_traits<T*> {

};

template<class T>
class iterator_traits<const T*> {

};
}  // namespace ft
