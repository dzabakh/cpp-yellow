#include "test_runner.h"
#include <stdexcept>

using namespace std;

template <typename T>
class Deque {
private:
	vector<T> forwardVec;
	vector<T> backwardVec;

public:
	bool Empty() const {return forwardVec.empty() && backwardVec.empty();}
	size_t Size() const {return forwardVec.size() + backwardVec.size();}

	T& operator[](size_t index){
		if (index < backwardVec.size()) return backwardVec[backwardVec.size() - index];
						else return forwardVec[index - backwardVec.size()];
	}

	const T& operator[] (size_t index) const{
		if (index < backwardVec.size()) return backwardVec[backwardVec.size() - index];
						else return forwardVec[index - backwardVec.size()];
	}

	const T& At(size_t index) const {
			if (index > Size() - 1)
				throw std::invalid_argument("Index out of range");
			else {
				if (index < backwardVec.size()) return backwardVec[backwardVec.size() - index];
				else return forwardVec[index - backwardVec.size()];
			}
	}

	 T& At(size_t index) {
			if (index > Size() - 1)
				throw std::invalid_argument("Index out of range");
			else {
				if (index < backwardVec.size()) return backwardVec[backwardVec.size() - index];
				else return forwardVec[index - backwardVec.size()];
			}
	}

	 const T& Front() const { return backwardVec.back();}

	 T& Front() {return backwardVec.back();}

	 const T& Back() const { return forwardVec.back();}

	 T& Back() {return forwardVec.back();}

	 void PushFront(T i_data){ backwardVec.push_back(i_data); }

	 void PushBack(T i_data){ forwardVec.push_back(i_data); }

};
