#ifndef LIST_H
#define LIST_H
#include "Container.h"

template<typename T> class List : public Container<T> {
protected:
	T *_data;
	size_t _size;
	size_t _capacity;
	void resize(size_t newSize) {
		T* newData = new T[newSize];
		memcpy(newData, this->_data, newSize * sizeof(T));
		delete[] this->_data;
		this->_data = newData;
		this->_capacity = newSize;
	}
public:
	List(int initialCapacity = 1) : _capacity(initialCapacity), _size(0) {
		this->_data = new T[this->_capacity];
	};
	List(const List<T>& other) {
		this->_size = other.size();
		this->_capacity = other._capacity;
		this->_data = new T[this->_capacity];
		memcpy(this->_data, other._data, sizeof(T) * this->_size);
	};
	~List() {
		delete[] this->_data;
	};
	virtual void push_back(const T& elem) {
		if(this->_size == this->_capacity)
			this->resize(this->_capacity * 2);
		this->_data[this->_size++] = elem;
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

	virtual bool empty() const {
		return this->_size == 0;
	}

	virtual size_t size() const {
		return this->_size;
	}
};

#endif