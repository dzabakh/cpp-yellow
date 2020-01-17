#include "test_runner.h"
//#include "profile.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <deque>
#include <unordered_set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate(){
	  if (!deallocated.empty()){
		  auto obj = deallocated.front();
		  allocated.insert(obj);
		  deallocated.pop_front();
		  return obj;
	  }
	  else {
		  auto newObjT = new T;
		  allocated.insert(newObjT);
		  return newObjT;
	  }
  }
  T* TryAllocate(){
	  if (!deallocated.empty()){
		  auto obj = deallocated.front();
		  allocated.insert(obj);
		  deallocated.pop_front();
		  return obj;
	  }
	  else {
		  return nullptr;
	  }
  }

  void Deallocate(T* object){
	  const auto objToDeallocateIt = allocated.find(object);
	  if (objToDeallocateIt == allocated.end()) {
		  throw std::invalid_argument("Object to deallocate not found");
	  } else{
		  deallocated.push_back(*objToDeallocateIt);
		  allocated.erase(objToDeallocateIt);
	  }
  }

  ~ObjectPool(){
	  for (auto allocatedObj: allocated){
		  delete allocatedObj;
	  }
	  for (auto deallocatedObj: deallocated){
		  delete deallocatedObj;
	  }
  };

private:

  unordered_set<T*> allocated;
  deque<T*> deallocated;
};

void TestObjectPool() {
 /* ObjectPool<string> pool;
  std::vector<string*> vec;
  {
	  LOG_DURATION("Fill Array");
	  for (int i = 0; i<100000; i++){
		  vec.push_back(pool.Allocate());
		  *vec[i] = i;
	  }
  }

  {
	  LOG_DURATION("Clear Array");
	  for (int i = 25000; i<75000; i++)
		  pool.Deallocate(vec[i]);

  }*/

  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
	//TestObjectPool();
  return 0;
}
