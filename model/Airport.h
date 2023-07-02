#include<iostream>
#include<string>
using namespace std;

class Airport{
public:
    Airport(string name, string iata_code, string icao_code, string country, string city,double lat,double lon);

    string getName() const;
	string getIataCode() const;
	string getIcaoCode() const;
	double getLatitude() const;
	double getLongitude() const;
    string getCountry() const;
    string getCity() const;
private:
	string name;
	string iata_code;
	string icao_code;
	double lat;
    double lon;
    string country;
    string city;
};

