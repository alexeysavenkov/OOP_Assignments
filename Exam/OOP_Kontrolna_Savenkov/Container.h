#ifndef CONTAINER_H
#define CONTAINER_H
#include <functional>

template<typename T> class Container {
	virtual void for_each(std::function< void(T) >& f) const = 0;
};

#endif