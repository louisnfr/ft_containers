#pragma once

namespace ft {
template<class Iterator>
struct iterator_traits {

}

template<class T>
struct iterator_traits<T*> {

}

template<class T>
struct iterator_traits<const T*> {

}
}  // namespace ft
