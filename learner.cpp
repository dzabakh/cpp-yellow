#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
	  const int size_before = dict.size();
	  for (const auto& word: words){
		  dict.emplace(word);
	  }
	  const int size_after = dict.size();
	  return size_after - size_before;
  }

  vector<string> KnownWords() {
	  vector<string> result;
	  copy(dict.begin(), dict.end(), back_inserter(result));
	  return result;
  }
};