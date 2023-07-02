#include<iostream>
#include "controller/Controller.h"

int main(){
    Controller c;
    auto v=c.get_Airports();
    for(auto x: v)
        cout<<x.second->getName()<<x.second->getCountry()<<endl;
    return 0;
}