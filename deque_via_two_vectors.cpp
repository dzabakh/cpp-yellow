#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class Deque {
private:
	std::vector<T> forwardVec;
	std::vector<T> backwardVec;
public:
	const bool Empty() const {return forwardVec.empty() && backwardVec.empty();}
	const size_t Size() const {return forwardVec.size() + backwardVec.size();}

	T& operator[](size_t index){
		return At(index);
	}

	const T& operator[] (size_t index) const{
		return At(index);
	}

	const T& At(size_t index) const {
			if (index > Size() - 1 || index < 0)
				throw std::out_of_range("Index out of range");
			else {
				if (index < backwardVec.size()) return backwardVec[backwardVec.size() - index - 1];
				else return forwardVec[index - backwardVec.size()];
			}
	}

	 T& At(size_t index) {
			if (index > Size() - 1 || index < 0)
				throw std::out_of_range("Index out of range");
			else {
				if (index < backwardVec.size()) return backwardVec[backwardVec.size() - index - 1];
				else return forwardVec[index - backwardVec.size()];
			}
	}

	 const T& Front() const { return At(0);}

	 T& Front() {return At(0);}

	 const T& Back() const { return At(Size() - 1);}

	 T& Back() {return At(Size() - 1);}

	 void PushFront(T i_data){ backwardVec.push_back(i_data); }

	 void PushBack(T i_data){ forwardVec.push_back(i_data); }

};