#include <iostream>
#include <cassert>
#include <string>

using namespace std;


const int MIN_PER_HOUR = 60;
enum month_enum {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};



struct date_struct{
        month_enum month; //What month it is
        int day; //1-31
        int year; //4 digits, C.E.
    };

struct time_struct{
    int hour; //Hour (24 hour clock)
    int minute; //0-59
};

struct datetime{
    date_struct date; //the current date
    time_struct time; //the current time
};

int time_difference(time_struct starttime, time_struct endtime){
    if(starttime.hour > endtime.hour){
        cout << "Error! The starttime is hours after the endtime!" << '\n';
        assert(starttime.hour <= endtime.hour);
    }else if(starttime.hour == endtime.hour){
        if(starttime.minute > endtime.minute){
            cout << "Error! The starttime is minutes after the endtime!" << '\n';
            assert(starttime.minute <= endtime.minute);
        }
        return endtime.minute - starttime.minute;
    }
    else{
        int minutes = endtime.minute - starttime.minute;
        minutes += MIN_PER_HOUR*(endtime.hour-starttime.hour);
        return minutes;
    }
}

void time_difference_test(datetime start, datetime end){
    cout << "Testing time difference: "<< '\n';
    if(start.time.minute < 10)
        cout << "Start time: "<< start.time.hour << ":0" << start.time.minute <<'\n';
    else
        cout << "Start time: "<< start.time.hour << ":" << start.time.minute <<'\n';
    if(end.time.minute < 10)
        cout << "End time: "<< end.time.hour << ":0" << end.time.minute <<'\n';
    else
        cout << "End time: "<< end.time.hour << ":" << end.time.minute <<'\n';
    cout << "Difference in minutes: " << time_difference(start.time, end.time) << '\n';
}

int time_difference(time_struct, time_struct);
void time_difference_test(datetime, datetime);
int main(){
    datetime start = {
        {
            JANUARY,
            8,
            2020,
        },
        {
            12,
            30
        }
    };
    datetime end = {
        {
            JANUARY,
            8,
            2020,
        },
        {
            15,
            26
        }
    };
    time_difference_test(start, end);
    start.time.hour = -1;
    while(start.time.hour < 0 || start.time.hour > 23){
        cout << "Now its your turn. Enter an start hour: ";
        cin >> start.time.hour;
        if(start.time.hour < 0 || start.time.hour > 23)
            cout << "Invalid hour! Make sure the hour is between 0 and 23." << '\n';
    }
    start.time.minute = -1;
    while(start.time.minute < 0 || start.time.minute > 59){
        cout << '\n' << "Enter a start minute. ";
        cin >> start.time.minute;
        if(start.time.minute < 0 || start.time.minute > 59)
            cout << "Invalid minute! Make sure the minute is between 0 and 59." << '\n';
    }
    end.time.hour = -1;
    while(end.time.hour < 0 || end.time.hour > 23){
        cout << '\n' << "Enter an end hour: ";
        cin >> end.time.hour;
        if(end.time.hour < 0 || end.time.hour > 23)
            cout << "Invalid hour! Make sure the hour is between 0 and 23." << '\n';
    }
    end.time.minute = -1;
    while(end.time.minute < 0 || end.time.minute > 59){
        cout << '\n' << "Enter an end minute. ";
        cin >> end.time.minute;
        if(end.time.minute < 0 || end.time.minute > 59)
            cout << "Invalid minute! Make sure the minute is between 0 and 59." << '\n';
    }
    time_difference_test(start, end);

}