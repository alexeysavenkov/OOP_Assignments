
#include "List.h"
#include "AbstrSet.h"

template<typename T>
class SetOnListInherit : public AbstrSet<T>, private List<T> {
public:
	SetOnListInherit(int initialCapacity = 1) : List<T>(initialCapacity) { };
	SetOnListInherit(const SetOnListInherit<T>& other) : List<T>(other) { };
	~SetOnListInherit() { };
	virtual bool add(const T& elem) {
		if(this->in(elem))
			return false;
		List<T>::push_back(elem);
		return true;
	}
	virtual bool del(const T& elem) {
		return List<T>::del(elem);
	}

	virtual void for_each(std::function< void(T) >& f) const {
		List<T>::for_each(f);
	}

	virtual bool empty() const {
		return List<T>::empty();
	}

	virtual size_t size() const {
		return List<T>::size();
	}
};