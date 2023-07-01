#include<iostream>
#include<string> 
using namespace std;
class Aircraft{
public:	
	string getHexCode() const;
	string getIataCode() const;
	string getIcaoCode() const;
	string getManufacturer() const;
private:
	string hexCode;
	string iataCode;
	string icaoCode;
	string manufacturer;

};
