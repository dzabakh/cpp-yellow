#pragma once
#include <iostream>
#include <cstdlib>

template <typename T>
class SimpleVector {
public:
  SimpleVector(): data(nullptr), size_(0), valids_(0){}

  explicit SimpleVector(size_t size):
		  size_(size),
		  valids_(size)
  {
	  data = new T[size_];
  }
  ~SimpleVector(){
	  delete[] data;
  }

  T& operator[](size_t index){
	  return *(data + index);
  }

  T* begin(){
	  return data;
  }
  T* end(){
	  return data + valids_;
  }

  size_t Size() const{
	  return valids_;
  }
  size_t Capacity() const{
	  return size_;
  }

  void PushBack(const T& value){
	  if (valids_ == size_){
		  size_t newSize = (size_ == 0) ? 1 : size_ * 2;
		  T* newData = new T[newSize];
		  size_ = newSize;
		  for (size_t i = 0; i < valids_; ++i)
			  *(newData + i) = *(data + i);
		  delete[] data;
		  data = newData;
	  }
	  *(data + valids_) = value ;
	  valids_++;
  }

private:
  T* data;
  size_t size_;
  size_t valids_;

};
