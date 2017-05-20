
#include "List.h"
#include "AbstrSet.h"

template<typename T>
class SetOnListComposit : public AbstrSet<T> {
private:
	List<T> *_list;
public:
	SetOnListComposit(int initialCapacity = 1) {
		_list = new List<T>(initialCapacity);
	};
	SetOnListComposit(const SetOnListComposit<T>& other) {
		_list = new List<T>(*(other._list));
	};
	~SetOnListComposit() { 
		delete _list;
	};
	virtual bool add(const T& elem) {
		if(this->in(elem))
			return false;
		_list->push_back(elem);
		return true;
	}
	virtual bool del(const T& elem) {
		return _list->del(elem);
	}

	virtual void for_each(std::function< void(T) >& f) const {
		_list->for_each(f);
	}

	virtual bool empty() const {
		return _list->empty();
	}

	virtual size_t size() const {
		return _list->size();
	}
};