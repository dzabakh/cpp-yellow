#include "test_runner.h"

using namespace std;

template <typename T>
class Table {
private:
	vector<vector<T>> data;

public:
	Table(size_t rows, size_t columns){
		Resize(rows, columns);
	}

	void Resize(size_t rows, size_t columns){
		data.resize(rows);
		for (auto& row: data)
			row.resize(columns);
	}

	vector<T>& operator[](size_t index){
		return data[index];
	}

	const vector<T>& operator[] (size_t index) const{
		return data[index];
	}

	pair<size_t, size_t> Size() const {return {data.size(), data.empty()? 0 : data[0].size()};}


};