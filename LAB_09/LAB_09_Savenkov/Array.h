
template<typename T> class WriteCheck {
	T* _item;
public:
	WriteCheck(T* item) : _item(item) {}
	void operator =(T newValue) {
		*(this->_item) = newValue;
	}
	operator T () {
		return *this->_item;
	}
};

template<int n, typename T> class Array {
	T _data[n];

public:
	class IndexOutOfBoundsException {};

	WriteCheck<T> operator [] (int i) {
		if(i < 0 || i >= n)
			throw IndexOutOfBoundsException();
		return WriteCheck<T>(this->_data + i);
	}
};