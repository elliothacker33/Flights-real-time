#include<iostream>
#include<string>

using namespace std;

class Airport{
public:
	string getName() const;
	string getIataCode() const;
	string getIcaoCode() const;
	double getLatitude() const;
	double getLongitude() const;
private:
	string name;
	string iata_code;
	string icao_code;
	double lat;
};

