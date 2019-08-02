#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	if (range_end - range_begin < 2) return;
	vector<typename RandomIt::value_type> elements(range_begin, range_end);

	int N = elements.size()/2;
	MergeSort(elements.begin(), elements.begin() + N);
	MergeSort(elements.begin() + N, elements.end());
	auto elementIt = elements.begin();
	merge(elements.begin(), elements.begin() + N,
	      elements.begin() + N elements.end(), elementIt);
	range_begin = elements.begin();
	range_end = elements.end();

}


int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
