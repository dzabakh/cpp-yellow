#pragma once

#include <stdexcept>
#include <array>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0): datasize(0){
	  if (a_size > N) {throw std::invalid_argument("size bigger than capacity");}
	  datasize = a_size;
  }

  T& operator[](size_t index){return data[index];}
  const T& operator[](size_t index) const {return data[index];}

  auto begin(){return data.begin();}
  auto end(){return data.begin() + datasize;}
  const auto begin() const {return data.begin();}
  const auto end() const {return data.begin() + datasize;}

  size_t Size() const {return datasize;}
  size_t Capacity() const{return data.size();}

  void PushBack(const T& value){
	  if (datasize == N) {throw std::overflow_error("cannot push_back");}
	  data[datasize] = value;
	  datasize++;
  }

  T PopBack(){if (datasize == 0) {
	  throw std::underflow_error("nothing to pop_back");}
  	  datasize--;
  	  return data[datasize];
  }

private:
  std::array<T, N> data;
  size_t datasize;
};
