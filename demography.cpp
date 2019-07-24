#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;
  Gender gender;
  bool is_employed;
};


template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons)
{
/*Median age = 40
  Median age for females = 40
  Median age for males = 55
  Median age for employed females = 40
  Median age for unemployed females = 80
  Median age for employed males = 55
  Median age for unemployed males = 78
 */
	cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
	auto femaleIt = partition(persons.begin(), persons.end(), [&](Person curPerson)
			{return curPerson.gender == Gender::FEMALE;});
	cout << "Median age for female = " << ComputeMedianAge(persons.begin(), femaleIt) << endl;
	cout << "Median age for male = " << ComputeMedianAge(femaleIt, persons.end()) << endl;

	auto emplFemaleIt = partition(persons.begin(), persons.end(), [&](Person curPerson)
			{return curPerson.gender == Gender::FEMALE && curPerson.is_employed;});
	cout << "Median age for employed females = " <<  ComputeMedianAge(persons.begin(), emplFemaleIt) << endl;
	auto unemplFemaleIt = partition(persons.begin(), persons.end(), [&](Person curPerson)
			{return curPerson.gender == Gender::FEMALE && !curPerson.is_employed;});
	cout << "Median age for unemployed females = " <<  ComputeMedianAge(persons.begin(), unemplFemaleIt) << endl;

	auto emplMaleIt = partition(persons.begin(), persons.end(), [&](Person curPerson)
			{return curPerson.gender == Gender::MALE && curPerson.is_employed;});
	cout << "Median age for employed males = " <<  ComputeMedianAge(persons.begin(), emplMaleIt) << endl;
	auto unemplMaleIt = partition(persons.begin(), persons.end(), [&](Person curPerson)
			{return curPerson.gender == Gender::MALE && !curPerson.is_employed;});
	cout << "Median age for unemployed males = " <<  ComputeMedianAge(persons.begin(), unemplMaleIt) << endl;
}

int main() {
	  vector<Person> persons = {
	      {31, Gender::MALE, false},
	      {40, Gender::FEMALE, true},
	      {24, Gender::MALE, true},
	      {20, Gender::FEMALE, true},
	      {80, Gender::FEMALE, false},
	      {78, Gender::MALE, false},
	      {10, Gender::FEMALE, false},
	      {55, Gender::MALE, true},
	  };
	  PrintStats(persons);
	return 0;
}
