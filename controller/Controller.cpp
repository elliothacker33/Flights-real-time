#include "Controller.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
Controller::Controller(){

}
// Callback Function for response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) const {
    size_t totalSize = size * nmemb;
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// Function to process the JSON response
void ProcessResponse(const std::string& response) {
    // Parse the response JSON
    json responseData = json::parse(response);

    // Retrieve the airlines array from the parsed JSON
    json rows = responseData["rows"];

    // Iterate over the airlines and print the names
    for (const auto& row : rows) {
        std::cout << row["description"].get<std::string>() << std::endl;
    }
}

void Controller::callApi() const  {
    CURL* curl = curl_easy_init();
    if (curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://flight-radar1.p.rapidapi.com/aircrafts/list");

        // Set the custom request type to GET
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");

        // Set the headers
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "X-RapidAPI-Key: 78fbb0da29msh4839b0fc90f9f48p1b0d36jsn20d175b35c5d");
        headers = curl_slist_append(headers, "X-RapidAPI-Host: flight-radar1.p.rapidapi.com");
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
            std::cout<<"hello";
            ProcessResponse(response);
        }

        // Clean up
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    } else {
        std::cerr << "Failed to initialize cURL" << std::endl;
    }
}
