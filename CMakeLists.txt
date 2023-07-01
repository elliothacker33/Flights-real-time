cmake_minimum_required(VERSION 3.25)
project(Flights_real_time)

set(CMAKE_CXX_STANDARD 14)

include_directories(model)

add_executable(Flights_real_time
        model/Aircraft.h
        model/Airline.h
        model/Airport.h
        model/City.h
        model/Country.h
        main.cpp)
