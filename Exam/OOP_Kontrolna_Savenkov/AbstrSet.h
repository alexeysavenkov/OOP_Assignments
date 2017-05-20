#ifndef ABSTR_SET_H
#define ABSTR_SET_H

#include <ostream>
#include <functional>
#include <type_traits>
#include "Container.h"

template<typename T> class AbstrSet : public Container<T> {
protected:
	size_t _size;
public:
	AbstrSet() : _size(0) {}
	virtual bool add(const T& elem) = 0;

	template<typename Cont>
	void addAll(Cont elems) {
		std::function<void(T)> f = [this](T elem) {
			this->add(elem);
		};
		elems.for_each(f);
	}
	virtual bool del(const T& elem) = 0;
	virtual bool in(const T& elemToFind) const {
		bool res = false;
		std::function<void(T)> f = [&res, &elemToFind](T elem) {
			if(elem == elemToFind) {
				res = true;
			}
		};
		this->for_each(f);
		return res;
	}
	bool empty() const {
		return this->_size == 0;
	}
	size_t size() const {
		return this->_size;
	}
	void show() const {
		std::cout << *this;
	}
	virtual void for_each(std::function< void(T) >&) const = 0;
	
	template<typename SetType> 
	SetType operator + (const SetType& other) {
		SetType res;
		std::function<void(T)> f = [&res](const T& elem) { res.add(elem); };
		this->for_each(f);
		other.for_each(f);
		return res;
	}

	template<typename SetType> 
	SetType operator * (const SetType& other) {
		SetType res;
		std::function<void(T)> f = [&res, &other](const T& elem) { 
			if(other.in(elem))
				res.add(elem);
		};
		this->for_each(f);
		return res;
	}
};

template<typename T> std::ostream& operator << (std::ostream& out, const AbstrSet<T>& set) {
	std::function<void(T)> f = [&out](const T& elem) { out << elem << ' '; };
	set.for_each(f);
	out << std::endl;
	return out;
}

#endif