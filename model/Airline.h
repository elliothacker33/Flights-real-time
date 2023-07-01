#include <iostream>
#include<string>
using namespace std;

class Airline{
public:
	string getName() const;
	string iataCode() const;
	string icaoCode() const;
	string callSign() const;
	Country* getCountry() const;
	int getProblems() const;
private:
	string name;
	string iataCode;
	string icaoCode;
	string callSign;
	Coutnry* country;
	int Problems; // Crashes or Accidents last 5 years
};
