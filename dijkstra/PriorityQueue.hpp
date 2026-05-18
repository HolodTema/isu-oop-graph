#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <vector>

template<class T>
class PriorityQueue {
private:
	std::vector<T> vecElements_;

public:

	explicit PriorityQueue() = default;

	explicit PriorityQueue(size_t capacity) {
		vecElements_.reserve(capacity);
	}

	void push(const T& element) {
		auto it = vecElements_.begin();
		while ((it != vecElements_.end()) && (it->mark < element.mark)) {
			++it;
		}
		vecElements_.insert(it, element);
	}

	T pop() {
		T element = vecElements_.front();
		vecElements_.erase(vecElements_.begin());
		return element;
	}

	bool isEmpty() const {
		return vecElements_.empty();
	}

};

#endif