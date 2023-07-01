#include "Controller.h"
#include <curl/curl.h>
#include<fstream>
#include<iostream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}
int main() {
    CURL* curl;
    CURLcode res;
    std::string url = "https://airlabs.co/api/v9/countries?code=US&api_key=2446811c-3379-4690-a062-7a6302ad09bd";
    std::string response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    // Parse the response JSON
    json responseData = json::parse(response);

    // Retrieve the county_code from the parsed JSON
    std::string countyCode = responseData["county_code"];

    std::cout << "County Code: " << countyCode << std::endl;

    return 0;
}