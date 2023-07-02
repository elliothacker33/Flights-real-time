#ifndef FLIGHTS_REAL_TIME_CONTROLLER_H
#define FLIGHTS_REAL_TIME_CONTROLLER_H

#include <cstddef>
#include <string>
#include<unordered_map>
#include "Airline.h"
#include "Airport.h"
#include "Aircraft.h"
#include <nlohmann/json.hpp>

using namespace std;

class Controller {
public:
    Controller();
    void callApi(const string url,int option) ;
    void get_api_key(string& url) const;
    void readAirports();
    void ProcessResponse(const string& response, int option)  ;
    void ProcessAirports(const string& response);


private:
    unordered_map<string,Airline*> airlines;
    unordered_map<string,Airport*> airports;
    unordered_map<string,Aircraft*> aircrafts;


};


#endif //FLIGHTS_REAL_TIME_CONTROLLER_H
