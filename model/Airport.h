#include<iostream>
#include<string>
#include<Country.h>
#include<City.h>
using namespace std;

class Airport{
public:
	string getName() const;
	string getIataCode() const;
	string getIcaoCode() const;
	Country* getCountry() const;
	City* getCity() const;
	double getLatitude() const;
	double getLongitude() const;
private:
	string name;
	string iata_code;
	string icao_code;
	Country* country;
	City* city;
	double lat;
	double long;
};

