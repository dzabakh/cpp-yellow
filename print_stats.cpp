void PrintStats(vector<Person> persons)
{
	cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
	auto femaleIt = partition(persons.begin(), persons.end(), [&](Person curPerson)
			{return curPerson.gender == Gender::FEMALE;});
	cout << "Median age for females = " << ComputeMedianAge(persons.begin(), femaleIt) << endl;
	cout << "Median age for males = " << ComputeMedianAge(femaleIt, persons.end()) << endl;

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
