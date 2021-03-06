#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct operation{
	char symbol;
	int operand;
};

int main() {
	//std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);

	int start;
	cin >> start;
	deque<char> output;


	string startStr = to_string(start);
	for (const char curChar: startStr)
		output.push_back(curChar);

	int N;
	cin >> N;
    if (N > 0){
        output.push_front('(');
        output.push_back(')');
        for (int i = 0; i < N; i++){
            operation op;
            cin >> op.symbol; cin >> op.operand;
            output.push_back(' ');
            output.push_back(op.symbol);
            output.push_back(' ');
            string operand = to_string(op.operand);
            for (const char curChar: operand)
                output.push_back(curChar);
            if (i != N-1){
                output.push_front('(');
                output.push_back(')');
            }
        }
    }
	for (const auto str:output)
		cout << str;
  return 0;
}
