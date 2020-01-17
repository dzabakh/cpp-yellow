#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix{
	private:
	vector<vector<int>> data;
	int num_rows_; int num_columns_;

	public:
	Matrix(){num_rows_ = 0; num_columns_ = 0;};
	Matrix(int num_rows, int num_cols){
		if (num_rows < 0 || num_cols < 0)
			throw std::out_of_range("Argument out of range");
		num_rows_ = num_rows;
		num_columns_ = num_cols;
	}
	void Reset(int num_rows, int num_cols){
		if (num_rows < 0 || num_cols < 0)
			throw std::out_of_range("Argument out of range");
		num_rows_ = num_rows;
		num_columns_ = num_cols;
		data = {};
	}

	int At(int num_row, int num_col) const{
		if (num_row < 0 || num_col < 0 || num_row > num_rows_ - 1 || num_col > num_columns_ - 1)
			throw std::out_of_range("Argument out of range");
		return data[num_row][num_col];
	}

	int& At(int num_row, int num_col) {
		if (num_row < 0 || num_col < 0 || num_row > num_rows_ - 1 || num_col > num_columns_ - 1)
			throw std::out_of_range("Argument out of range");
		return data[num_row][num_col];
		}

	int GetNumRows() const {return num_rows_;}
	int GetNumColumns() const {return num_columns_;}
};

bool operator==(const Matrix& one, const Matrix& two) {
  if (one.GetNumRows() != two.GetNumRows()) {
    return false;
  }

  if (one.GetNumColumns() != two.GetNumColumns()) {
    return false;
  }

  for (int row = 0; row < one.GetNumRows(); ++row) {
    for (int column = 0; column < one.GetNumColumns(); ++column) {
      if (one.At(row, column) != two.At(row, column)) {
        return false;
      }
    }
  }

  return true;
}

Matrix operator+(const Matrix& one, const Matrix& two) {
  if (one.GetNumRows() != two.GetNumRows()) {
    throw invalid_argument("Mismatched number of rows");
  }

  if (one.GetNumColumns() != two.GetNumColumns()) {
    throw invalid_argument("Mismatched number of columns");
  }

  Matrix result(one.GetNumRows(), one.GetNumColumns());
  for (int row = 0; row < result.GetNumRows(); ++row) {
    for (int column = 0; column < result.GetNumColumns(); ++column) {
      result.At(row, column) = one.At(row, column) + two.At(row, column);
    }
  }

  return result;
}

istream& operator>>(istream& in, Matrix& matrix) {
  int num_rows, num_columns;
  in >> num_rows >> num_columns;

  matrix.Reset(num_rows, num_columns);
  for (int row = 0; row < num_rows; ++row) {
    for (int column = 0; column < num_columns; ++column) {
      in >> matrix.At(row, column);
    }
  }

  return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
  out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
  for (int row = 0; row < matrix.GetNumRows(); ++row) {
    for (int column = 0; column < matrix.GetNumColumns(); ++column) {
      if (column > 0) {
        out << " ";
      }
      out << matrix.At(row, column);
    }
    out << endl;
  }

  return out;
}

