cmake_minimum_required(VERSION 3.25)
project(Flights_real_time)

set(CMAKE_CXX_STANDARD 14)

include_directories(model)
include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.2
)
FetchContent_MakeAvailable(json)
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

add_executable(Flights_real_time
        model/Aircraft.h
        model/Airline.h
        model/Airport.h
        main.cpp controller/Controller.cpp controller/Controller.h
        )

target_link_libraries(Flights_real_time PRIVATE nlohmann_json::nlohmann_json
         ${CURL_LIBRARIES})