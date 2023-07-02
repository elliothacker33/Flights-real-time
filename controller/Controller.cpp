#include "Controller.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
Controller::Controller(){
    this->readAirports();
    this->readAirlines();
}
Controller::~Controller(){
    for(auto x: airports)
        delete x.second;
    for(auto x:airlines)
        delete x.second;
    for(auto x:aircrafts){
        delete x.second;
    }
}
void Controller::readAirports(){
    string url="https://flight-radar1.p.rapidapi.com/airports/list";
    callApi(url,1);
}
void Controller::readAirlines(){
    string url="https://flight-radar1.p.rapidapi.com/airlines/list";
    callApi(url,2);
    url="https://flight-radar1.p.rapidapi.com/airlines/get-logos";
    callApi(url,3);
}
// Function to process the JSON response
void Controller::ProcessAirports(string response){
    // Parse Json Airport Data
    cout<<"Hello";
    json responseData = json::parse(response);
    json rows = responseData["rows"];

    for (const auto& row : rows) {
        string name=row["name"].get<string>();
        string iata_code=row["iata"].get<string>();
        string icao_code=row["icao"].get<string>();
        double lat=row["lat"].get<double>();
        double lon=row["lon"].get<double>();
        string city=row["city"].get<string>();
        string country=row["country"].get<string>();
        Airport* airport= new Airport(name,iata_code,icao_code,country,city,lat,lon);
        airports.insert({name,airport});
    }

}
void Controller::ProcessAirlines(string response){
    // Parse Json Airport Data
    json responseData = json::parse(response);
    json airlines_= responseData["rows"];

    for (const auto& airline : airlines_) {
        string name=airline["Name"].get<string>();
        string icao_code=airline["ICAO"].get<string>();
        string callSign=airline["Code"].get<string>();
        Airline* airline_= new Airline(name,icao_code,callSign);
        airlines.insert({name,airline_});
    }

}
void Controller::ProcessAirlinesLogos(string response){
    json responseData = json::parse(response);
    json logos = responseData["result"]["response"]["airlines"]["logotypes"];
    for(const auto& logo:logos){
        string icaoCode=logo["file"]["name"].get<string>();
        stringstream ss(icaoCode);
        getline(ss,icaoCode,'_');
        getline(ss,icaoCode,'.');
        string url=logo["file"]["url"].get<string>();
        airlines_logos.insert({icaoCode,url});
    }
}
void Controller::imageRendering(string icaoCode) const{
    string url = airlines_logos.at(icaoCode);
    string command="feh "+url;
    system(command.c_str());
}
unordered_map<string,Airport*> Controller::get_Airports() const {
    return airports;
}
Airport* Controller::getAirport(string airport_name) const{
     return airports.at(airport_name);
}
vector<Airport*> Controller::getAirports(vector<string> airports_names) const{
        vector<Airport*> airs;
        for(auto x:airports_names){
           airs.push_back(airports.at(x));
        }
        return airs;
}
unordered_map<string,Airline*> Controller::get_Airlines() const {
    return airlines;
}
Airline* Controller::getAirline(string airline_name) const{
    return airlines.at(airline_name);
}
vector<Airline*> Controller::getAirlines(vector<string> airlines_names) const{
    vector<Airline*> airs;
    for(auto x:airlines_names){
        airs.push_back(airlines.at(x));
    }
    return airs;
}
unordered_map<string,string> Controller::getAirlinesLogos() const{
    return airlines_logos;
}
// Callback Function for response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response)  {
    size_t totalSize = size * nmemb;
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

void Controller::ProcessResponse( string response,int option) {
    switch(option){
        case 1:
            ProcessAirports(response);
            break;
        case 2:
            ProcessAirlines(response);
            break;
        case 3:
            ProcessAirlinesLogos(response);
        default:
            return;
    }
}
void Controller::get_api_key(string& api_key) const{
    ifstream in("../APIKEY.txt");
    getline(in,api_key);
    in.close(); // Close the file
}
void Controller::callApi(const string url,int option)  {
    string api_key;
    get_api_key(api_key);
    CURL* curl = curl_easy_init();
    if (curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Set the custom request type to GET
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");

        // Set the headers
        struct curl_slist* headers = NULL;
        string header = "X-RapidAPI-Key: " + api_key;
        cout<<header;
        headers = curl_slist_append(headers, header.c_str()); // API KEY HEADER
        headers = curl_slist_append(headers, "X-RapidAPI-Host: flight-radar1.p.rapidapi.com"); // Host Header
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Response data
        std::string response;

        // Set the write callback function to receive the response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Process the response data
            ProcessResponse(response,option);
        }

        // Clean up
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    } else {
        std::cerr << "Failed to initialize cURL" << std::endl;
    }
}
