#include "Airport.h"
using namespace std;
Airport::Airport(string name, string iata_code,string icao_code,string country,string city,double lat,double lon){
    this->name=name;
    this->iata_code=iata_code;
    this->icao_code=icao_code;
    this->country=country;
    this->city=city;
    this->lat=lat;
    this->lon=lon;
}

string Airport::getCity() const {
    return city;
}

string  Airport::getCountry() const {
    return country;
}

string Airport::getIataCode() const {
    return iata_code;
}

string Airport::getIcaoCode() const {
    return icao_code;
}

double Airport::getLatitude() const {
    return lat;
}

double Airport::getLongitude() const {
    return lon;
}

string Airport::getName() const {
    return name;
}