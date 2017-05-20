#include "AbstrSet.h"
#include <functional>
#include <string.h>

template<typename T> 
class UnboundedSet : public AbstrSet<T> {
private:
	T *_data;
	size_t _capacity;
	void resize(size_t newSize) {
		T* newData = new T[newSize];
		memcpy(newData, this->_data, newSize * sizeof(T));
		delete[] this->_data;
		this->_data = newData;
		this->_capacity = newSize;
	}
public:
	UnboundedSet(int initialCapacity = 1) : AbstrSet<T>(), _capacity(initialCapacity) {
		this->_data = new T[this->_capacity];
	};
	UnboundedSet(const UnboundedSet<T>& other) {
		this->_size = other.size();
		this->_capacity = other._capacity;
		this->_data = new T[this->_capacity];
		memcpy(this->_data, other._data, sizeof(T) * this->_size);
	};
	~UnboundedSet() {
		delete[] this->_data;
	};
	virtual bool add(const T& elem) {
		if(this->in(elem))
			return false;
		if(this->_size == this->_capacity)
			this->resize(this->_capacity * 2);
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
				if(this->_size < this->_capacity / 2) {
					this->resize(this->_capacity / 2);
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