#include <iostream>
#include<string>
using namespace std;

class Airline{
public:
	string getName() const;
	string getIataCode() const;
	string getIcaoCode() const;
	string getCallSign() const;
	int getProblems() const;
private:
	string name;
	string iataCode;
	string icaoCode;
	string callSign;
	int Problems; // Crashes or Accidents last 5 years
};
