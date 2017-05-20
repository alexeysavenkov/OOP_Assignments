#include "BoundedSet.h"


template<typename T, size_t Limit>
virtual void BoundedSet<T, Limit>::add(const T& elem) {
	
}

template<typename T, size_t Limit>
virtual bool BoundedSet<T, Limit>::del(const T& elem) {
	
}

template<typename T, size_t Limit>
virtual void BoundedSet<T, Limit>::for_each(void (*f)(const T&)) const {
	s
}

template class BoundedSet<int, 5>;