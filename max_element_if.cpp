#include <algorithm>
using namespace std;


template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(
  ForwardIterator first, ForwardIterator last, UnaryPredicate pred){
	ForwardIterator maxElemIt = find_if(first, last, pred);
	for (ForwardIterator it = maxElemIt; it != last; ++it){
		if (*it > *maxElemIt && pred(*it) && it != maxElemIt)
			maxElemIt = it;
	}
	return maxElemIt;
}