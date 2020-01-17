#include <iostream>
#include <list>
#include <algorithm>
#include <deque>
#include <unordered_map>

using namespace std;

int main(){
	int N;
	cin >> N;
	list<int> sportsmen;
	unordered_map<int, std::list<int>::iterator> sportsmen_pointers;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < N; ++i){
		int newSportsman;
		int prevSportsman;
		cin >> newSportsman >> prevSportsman;

		if (i == 0){
			sportsmen.push_back(newSportsman);
			sportsmen_pointers[newSportsman] = sportsmen.begin();
		}
		else {
			if (sportsmen_pointers.count(prevSportsman) == 0){
				sportsmen.push_back(newSportsman);
				sportsmen_pointers[newSportsman] = prev(sportsmen.end());
			}
			else{
				sportsmen.insert(sportsmen_pointers.at(prevSportsman), newSportsman);
				sportsmen_pointers[newSportsman] = prev(sportsmen_pointers.at(prevSportsman));
			}
		}
	}

	for (const auto sportsman: sportsmen)
		cout << sportsman << " ";

	return 0;
}
