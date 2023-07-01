#include <iostream>
#include<string>
#include<Country.h>
using namespace std;

class Airline{
public:
	string getName() const;
	string getIataCode() const;
	string getIcaoCode() const;
	string getCallSign() const;
	Country* getCountry() const;
	int getProblems() const;
private:
	string name;
	string iataCode;
	string icaoCode;
	string callSign;
	Country* country;
	int Problems; // Crashes or Accidents last 5 years
};
