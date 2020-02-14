#include <iostream>
#include <cassert>
#include <string>
#include <map>
#include <list>

using namespace std;

const int codeLength = 3;

struct time_struct{
    int hour; //Hour (24 hour clock)
    int minute; //0-59
};

struct flight{
    int flight_number;
    string depart_airline_code; 
    string arrive_airline_code; 
    time_struct depart_time;
    time_struct arrive_time;
};

struct airport{
    string code; //length 3, dictionary key
    list<flight> flights; //List of all flights departing from this airport
};

airport sarasota = {
    "SIA",
    {
        {
            5800,
            "SIA",
            "AAA",
            {8,55},
            {18,27}
        },
    }
};

airport aaaland = {
    "AAA",
    {
        {
            4800,
            "AAA",
            "SIA",
            {1,25},
            {8,15}
        },
        {
            4801,
            "AAA",
            "SIA",
            {5,25},
            {12,15}
        },
    }
};

map<string, airport> airports;


void flight_list_to_print(list<flight> flights);
int main(){
    airports[sarasota.code] = sarasota;
    airports[aaaland.code] = aaaland;
    flight_list_to_print(airports["AAA"].flights);
}

void flight_list_to_print(list<flight> flights){
    for(flight f : flights){
        cout << "Flight " << (f.flight_number) << " is leaving from " << (f.depart_airline_code)
        << " at "<<(f.depart_time.hour) << ":" << (f.depart_time.minute) << " heading to "
        << (f.arrive_airline_code) <<" at "<<(f.arrive_time.hour) << ":" << (f.arrive_time.minute) << '\n';
    }
}