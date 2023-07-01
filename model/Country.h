#include<iostream>
#include<string>
using namespace std;
class Country{
public:
	string getName() const;
	string getCode() const;
	string getContinent() const;
	int getPopulation() const;
private:
	string name;
	string code;
	string continent;
	int population;
}

