#include "Airline.h"
using namespace std;
Airline::Airline(string name, string icaoCode, string callSign){
    this->name=name;
    this->icaoCode=icaoCode;
    this->callSign=callSign;
}
string Airline::getName() const{
    return name;
};
string Airline::getIcaoCode() const{
    return icaoCode;
};
string Airline::getCallSign() const{
    return callSign;
};