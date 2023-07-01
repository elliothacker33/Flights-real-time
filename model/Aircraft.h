#include<iostream>
#include<string> 
using namespace std;
class Aircraft{
public:	
	string hexCode() const;
	string iataCode() const;
	string icaoCode() const;
	string manufacturer() const;
private:
	string hexCode;
	string iataCode;
	string icaoCode;
	string manufacturer;

};
