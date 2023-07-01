#include<iostream>
#include<string>
using namespace std;
class City{
public:
	string getName() const;
	string getCityCode() const;
	Country* getCountry() const;
	int getPopulation() const;
private:
	string name;
	string city_code;
	Country* country;
	int population; // Will be used For Statistics

};
