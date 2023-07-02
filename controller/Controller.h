#ifndef FLIGHTS_REAL_TIME_CONTROLLER_H
#define FLIGHTS_REAL_TIME_CONTROLLER_H

#include <cstddef>
#include <string>
#include<unordered_map>
#include "../model/Airline.h"
#include "../model/Airport.h"
#include "../model/Aircraft.h"

#include <nlohmann/json.hpp>

using namespace std;

class Controller {
public:
    Controller();
    ~Controller();
    void callApi(const string url,int option);
    void get_api_key(string& url) const;
    void readAirports();
    void readAirlines();
    Airport* getAirport(string airport_name) const;
    void ProcessResponse(string response,int option);
    void ProcessAirports(string response);
    void ProcessAirlines(string response);
    void ProcessAirlinesLogos(string response);
    unordered_map<string,Airport*> get_Airports() const;
    unordered_map<string, Airline *> get_Airlines() const;
    vector<Airport*> getAirports(vector<string> airports_names) const;
    Airline *getAirline(string airline_name) const;
    unordered_map<string, string> getAirlinesLogos() const;
    vector<Airline *> getAirlines(vector<string> airlines_names) const;
    void imageRendering(string callSign) const ;
private:
    unordered_map<string,Airline*> airlines;
    unordered_map<string,Airport*> airports;
    unordered_map<string,Aircraft*> aircrafts;
    unordered_map<string,string> airlines_logos;
};


#endif //FLIGHTS_REAL_TIME_CONTROLLER_H
