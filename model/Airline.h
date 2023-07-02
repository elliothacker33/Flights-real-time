#include <iostream>
#include<string>
using namespace std;

class Airline{
public:
    Airline(string name,string icaoCode,string callSign);
	string getName() const;
	string getIcaoCode() const;
	string getCallSign() const;
private:
	string name;
	string icaoCode;
	string callSign;
};
