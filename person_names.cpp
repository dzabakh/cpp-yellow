#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

string FindNameByYear(const map<int, string>& i_names, int i_year){
	auto yearIt = i_names.upper_bound(i_year);
	if (yearIt == i_names.begin()) return "";
	else return (--yearIt)->second;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    firstNamesChanges[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  lastNamesChanges[year] = last_name;
  }
  string GetFullName(int year) {
	  string firstName = FindNameByYear(firstNamesChanges, year);
	  string lastName = FindNameByYear(lastNamesChanges, year);
	  if (firstName == "" && lastName == "")
		  return "Incognito";
	  else if (firstName == "")
		  return lastName + " with unknown first name";
	  else if (lastName == "")
		  return firstName + " with unknown last name";
	  else return firstName + " " + lastName;
  }
private:
  map<int, string> firstNamesChanges;
  map<int, string> lastNamesChanges;
};