#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <numeric>

using namespace std;

class ReadingManager {
public:
  ReadingManager()
      : user_page_counts_(MAX_USER_COUNT_ + 1, 0),
        sorted_users_(),
        user_positions_(MAX_USER_COUNT_ + 1, -1) {}

  void Read(int user_id, int page_count) {
    if (user_page_counts_[user_id] == 0) {
      AddUser(user_id);
    }
    user_page_counts_[user_id] = page_count;
    int& position = user_positions_[user_id];
    while (position > 0 && page_count > user_page_counts_[sorted_users_[position - 1]]) {
      SwapUsers(position, position - 1);
    }
  }

  double Cheer(int user_id) const {
    if (user_page_counts_[user_id] == 0) {
      return 0;
    }
    const int user_count = GetUserCount();
    if (user_count == 1) {
      return 1;
    }
    const int page_count = user_page_counts_[user_id];
    int position = user_positions_[user_id];
    while (position < user_count &&
      user_page_counts_[sorted_users_[position]] == page_count) {
      ++position;
    }
    if (position == user_count) {
        return 0;
    }
    return (user_count - position) * 1.0 / (user_count - 1);
  }

private:
  static const int MAX_USER_COUNT_ = 100'000;

  vector<int> user_page_counts_;
  vector<int> sorted_users_;
  vector<int> user_positions_;

  int GetUserCount() const {
    return sorted_users_.size();
  }
  void AddUser(int user_id) {
    sorted_users_.push_back(user_id);
    user_positions_[user_id] = sorted_users_.size() - 1;
  }
  void SwapUsers(int lhs_position, int rhs_position) {
    const int lhs_id = sorted_users_[lhs_position];
    const int rhs_id = sorted_users_[rhs_position];
    swap(sorted_users_[lhs_position], sorted_users_[rhs_position]);
    swap(user_positions_[lhs_id], user_positions_[rhs_id]);
  }
};

typedef int userId;
typedef int pageNum;

class ReadingManagerFast{
public:
	ReadingManagerFast(): d_pageRatings(MAX_PAGES_COUNT + 1, 0){
	}

	void Read(userId i_userId, pageNum i_pageNum){
		if (d_pagesForUsers.count(i_userId) > 0){
			for (int i = d_pagesForUsers.at(i_userId) + 1; i <= i_pageNum; i++)
				d_pageRatings[i]--;
		}
		else {
			for (int i = i_pageNum + 1; i <= MAX_PAGES_COUNT; i++)
						d_pageRatings[i]++;
		}
		d_pagesForUsers[i_userId] = i_pageNum;
	}

	double Cheer(userId i_userId){
		if (d_pagesForUsers.count(i_userId) == 0) return 0.0;
		if (d_pagesForUsers.size() == 1 && d_pagesForUsers.count(i_userId) == 1) return 1.0;
		return d_pageRatings[d_pagesForUsers.at(i_userId)] * 1.0/ (d_pagesForUsers.size() - 1.0);
	}
private:
	static const int MAX_PAGES_COUNT = 1000;
	map<userId, pageNum> d_pagesForUsers;
	vector<int> d_pageRatings;
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManagerFast manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}
