#include <iostream>
#include <cassert>
#include <string>
#include <map>
#include <list>
#include <algorithm> //allows use of std::transform

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
    string name;
    string code; //length 3, dictionary key
    list<flight> flights; //List of all flights departing from this airport
};

airport sarasota = {
    "Sarasota International",
    "SIA",
    {
        {
            5800,
            "SIA",
            "AAA",
            {8,55},
            {18,27}
        },
        {
            5801,
            "SIA",
            "GRA",
            {12,17},
            {23,59}
        },
        {
            5802,
            "SIA",
            "ENT",
            {14,30},
            {15,32}
        },
    }
};

airport aaaland = {
    "Aland Aviation",
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
        {
            4802,
            "AAA",
            "SIA",
            {9,25},
            {16,15}
        },
        {
            4803,
            "AAA",
            "GMM",
            {12,38},
            {22,18}
        },
        {
            4804,
            "AAA",
            "SIA",
            {13,25},
            {20,15}
        },
    }
};

airport galar = {
    "Galar Regional",
    "GRA",
    {
        {
            1299,
            "GRA",
            "SIA",
            {0,38},
            {13,10}
        },
        {
            1300,
            "GRA",
            "GMM",
            {8,55},
            {10,38}
        },
        {
            1301,
            "GRA",
            "ENT",
            {12,45},
            {15,47}
        },
    }
};

airport enterprise = {
    "Enterprise NX-01",
    "ENT",
    {
        {
            1008,
            "ENT",
            "SIA",
            {2,30},
            {3,30}
        },
        {
            1009,
            "ENT",
            "GRA",
            {8,15},
            {11,18}
        },
        {
            1009,
            "ENT",
            "GMM",
            {13,58},
            {20,27}
        },
        {
            1010,
            "ENT",
            "SIA",
            {15,30},
            {23,30}
        },
        {
            1011,
            "ENT",
            "GRA",
            {18,15},
            {18,37}
        },
    }
};

airport fodlan = {
    "Garreg Mach Monastery",
    "GMM",
    {
        {
            9996,
            "GMM",
            "GRA",
            {8,17},
            {10,30}
        },
        {
            9996,
            "GMM",
            "ENT",
            {12,38},
            {15,24}
        },
        {
            9996,
            "GMM",
            "SIA",
            {18,10},
            {23,11}
        },
    }
};


map<string, airport> airports;


void flight_list_to_print(list<flight> flights);
int main(){
    airports[sarasota.code] = sarasota;
    airports[aaaland.code] = aaaland;
    airports[galar.code] = galar;
    airports[enterprise.code] = enterprise;
    airports[fodlan.code] = fodlan;
    //flight_list_to_print(airports["AAA"].flights);
    
    cout << "The following airports are avaliable: \n";
    for(map<string, airport>::iterator airports_iterator = airports.begin(); 
        airports_iterator != airports.end(); ++airports_iterator){
            cout << airports_iterator->second.name << " Airport : " << airports_iterator->first <<"\n"; 
    }
    string input_code = "";
    string code_0 = "";
    string code_1 = "";
    string adjective = "first";
    while(code_0 == "" || code_1 == ""){
        cout << "Enter the " << adjective << " airport to get a list of all flights leaving from it today. \n";
        cin >> input_code;
        transform(input_code.begin(), input_code.end(), input_code.begin(), ::toupper); //performs toupper on each char in the string
        if(input_code.length() != codeLength){
            cout << "Error! The code you entered is the wrong length. All airport codes must be exactly 3 characters.\n";
            //return(2);
        }
        else if(airports.find(input_code) == airports.end()){
            cout << "Error! You entered an invalid airport code. Please refer back to the airport list.\n";
            //return(3);
        }
        else if(code_0 == input_code){
            cout << "You already chose this airport, please chose another.\n";
        }
        else{
            if(code_0 == ""){
                code_0 = input_code;
                adjective = "second";
            }
            else
            {
                code_1 = input_code;
            }
        }
    }
    flight_list_to_print(airports[code_0].flights);
    flight_list_to_print(airports[code_1].flights);
}

void flight_list_to_print(list<flight> flights){
    for(flight f : flights){
        cout << "Flight " << (f.flight_number) << " is leaving from " << (f.depart_airline_code)
        << " at "<<(f.depart_time.hour) << ":" << (f.depart_time.minute) << " heading to "
        << (f.arrive_airline_code) <<" at "<<(f.arrive_time.hour) << ":" << (f.arrive_time.minute) << '\n';
    }
}