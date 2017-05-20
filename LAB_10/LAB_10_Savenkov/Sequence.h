template<typename Elem> class Sequence{
public:
	class BadIndex {};
	explicit Sequence(const size_t capacity=_default) : _capacity(capacity), _size(0) {
		this->_allocator = new Elem[capacity];
	}
	~Sequence() {
		delete[] this->_allocator;
	}
	size_t capacity() const {
		return this->_capacity;
	}
	size_t size() const {
		return this->_size;
	}
	bool empty() const {
		return !this->_size;
	}
	bool full() const {
		return this->size() == this->capacity();
	}
	Sequence& clear() {
		this->_size = 0;
		this->_capacity = 0;
	}
	const Elem& operator[](const size_t index) const {
		if(index < 0 || index >= this->size())
			throw Sequence<Elem>::BadIndex;
		return this->_allocator[index];
	}
	Elem& operator[]( const  size_t index) {
		if(index < 0 || index >= this->size())
			throw Sequence<Elem>::BadIndex();
		return this->_allocator[index];
	}
	Sequence& add(const Elem& elem) {
		if(this->full())
			this->enlarge();
		this->_allocator[this->_size++] = elem;
		return *this;
	}
	Sequence& insert(const Elem& elem, const  size_t index) {
		if(this->full())
			this->enlarge();
		for(size_t i = this->_size++; i > index; i--) {
			this->_allocator[i] = this->_allocator[i-1];
		}
		this->_allocator[index] = elem;
		return *this;
	}
	Sequence& cut() {
		for(size_t i = 1; i <= this->size(); i++) {
			this->_allocator[i-1] = this->_allocator[i];
		}
		this->_size--;
		if(this->_capacity/this->_size >= 2)
			this->reduce();
		return *this;
	}
	Sequence& remove(size_t index) {
		for(size_t i = index + 1; i <= this->size(); i++) {
			this->_allocator[i-1] = this->_allocator[i];
		}
		this->_size--;
		if(this->_capacity/this->_size >= 2)
			this->reduce();
		return *this;
	}
	bool contains(const Elem & elem) {
		for(size_t i = 0; i < this->size(); i++) {
			if(this->_allocator[i] == elem)
				return true;
		}
		return false;
	}
	Sequence (const Sequence&);
	Sequence& operator=(const Sequence& seq) {
		this->_capacity = seq.capacity();
		this->_size = seq.size();
		this->_allocator = new Elem[this->_capacity()];
		for(int i = 0; i < this->_size; i++) {
			this->_allocator[i] = seq[i];
		}
		return *this;
	}
	private:
	size_t _size, _capacity;
	static const size_t _default=0;
	Elem* _allocator;
	void reduce(const size_t times=2) {
		this->_capacity /= times;
		Elem* newAllocator = new Elem[this->capacity()];
		for(size_t i = 0; i < this->_size; i++) {
			newAllocator[i] = this->_allocator[i];
		}
		delete[] this->_allocator;
		this->_allocator = newAllocator;
	}
	void enlarge(const size_t times=2) {
		if(this->_capacity)
			this->_capacity *= times;
		else
			this->_capacity = 2;

		Elem* newAllocator = new Elem[this->_capacity];
		for(size_t i = 0; i < this->_size; i++) {
			newAllocator[i] = this->_allocator[i];
		}
		delete[] this->_allocator;
		this->_allocator = newAllocator;
	}
};