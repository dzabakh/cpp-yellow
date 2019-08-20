#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

class Figure{
public:
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

class Triangle: public Figure{
public:
	Triangle(int i_a, int i_b, int i_c): a(i_a), b(i_b), c(i_c){}
	string Name(){return "TRIANGLE";}
	double Perimeter(){return a+b+c;}
	double Area(){return sqrt(Perimeter()/2 * (Perimeter()/2 - a) * (Perimeter()/2 - b) * (Perimeter()/2 - c));}
private:
	int a;
	int b;
	int c;
};


class Rect: public Figure{
public:
	Rect(int i_a, int i_b): a(i_a), b(i_b){}
	string Name(){return "RECT";}
	double Perimeter(){return (a+b)*2;}
	double Area(){return a*b;}
private:
	int a;
	int b;
};

class Circle: public Figure{
public:
	Circle(int i_r): r(i_r){}
	string Name(){return "CIRCLE";}
	double Perimeter(){return 3.14*r*2;}
	double Area(){return 3.14 * r * r;}
private:
	int r;
};

shared_ptr<Figure> CreateFigure(std::istringstream& is){
	string name;
	is >> name;
	if (name == "RECT"){
		int a, b;
		is >> a >> b;
		return make_shared<Rect>(a,b);
	}
	else if (name == "CIRCLE"){
		int r;
		is >> r;
		return make_shared<Circle>(r);
	}
	else {
		int a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(a,b,c);
	}
}
