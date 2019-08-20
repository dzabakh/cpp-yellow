#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
	Person(string i_name, string i_personType): Name(i_name), PersonType(i_personType){}

	virtual void Walk(string destination) const {
		cout << PersonType << ": " << Name << " walks to: " << destination << endl;
	} ;

	string getPersonType() const {return PersonType;}
	string getName() const {return Name;}
protected:
	const string Name;
	const string PersonType;
};

class Student: public Person {
public:
    Student(string name, string favouriteSong):
    	Person(name, "Student"),
		FavouriteSong(favouriteSong) {}

    void Learn() {
        cout << PersonType << ": " << Name << " learns" << endl;
    }

    void Walk(string destination) const override{
        cout << PersonType << ": " << Name << " walks to: " << destination << endl;
        cout << PersonType << ": " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << PersonType << ": " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher: public Person {
public:

    Teacher(string name, string subject): Person(name, "Teacher"), Subject(subject) {}

    void Teach() {
        cout << PersonType << ": " << Name << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman: public Person {
public:
    Policeman(string name): Person(name, "Policeman") {}

    void Check(Person p) {
    	cout << PersonType << ": " << Name << " checks " << p.getPersonType() << ". " <<
    			p.getPersonType() << "'s name is: " << p.getName() << endl;
    }
};


void VisitPlaces(const Person& per, vector<string> places) {
	for (const auto& p: places)
		per.Walk(p);
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
