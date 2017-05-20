#include "AbstrSet.h"
#include <functional>
#include <string.h>

struct LimitOverflowException {};

template<typename T, size_t Limit> 
class BoundedSet : public AbstrSet<T> {
private:
	T _data[Limit];
public:
	BoundedSet() : AbstrSet<T>() {};
	BoundedSet(const BoundedSet<T, Limit>& other) {
		this->_size = other.size();
		memcpy(this->_data, other._data, sizeof(T) * this->_size);
	};
	~BoundedSet() {};
	virtual bool add(const T& elem) {
		if(this->in(elem))
			return false;
		if(this->_size == Limit)
			throw LimitOverflowException();
		this->_data[this->_size++] = elem;
		return true;
	}
	virtual bool del(const T& elem) {
		for(size_t i = 0; i < this->_size; i++) {
			if(this->_data[i] == elem) {
				this->_size--;
				for(size_t j = i; j < this->_size; j++) {
					this->_data[j] = this->_data[j + 1];
				}
				return true;
			}
		}
		return false;
	}

	virtual void for_each(std::function< void(T) >& f) const {
		for(size_t i = 0; i < this->_size; i++) {
			f(this->_data[i]);
		}
	}
};