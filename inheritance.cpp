#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal(string i_name):
		Name(i_name)
{}
  const string Name;
};


class Dog: public Animal {
public:
	Dog(string i_name) : Animal(i_name){}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
