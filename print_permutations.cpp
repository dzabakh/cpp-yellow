#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	vector<string> vec;
	cin >> N;
	for (int i = 1; i<=N; i++)
		vec.push_back(to_string(i));

	reverse(vec.begin(), vec.end());

	do{
		for (const auto str: vec)
			cout << str << ' ';
		cout << endl;
	}while(prev_permutation(vec.begin(), vec.end()));

	return 0;
}
