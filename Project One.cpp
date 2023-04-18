#Carisma Carter
#March 16, 2023

#include <iostream>
#include <ctime>

class Clock {
private:
    int hours; // variable for hours
    int minutes; // variable for the minutes
    int seconds; // variable for the seconds
    bool the12HourClock; // variable for 12 hour clock format
    bool nowPM; // variable to check if the time is AM or PM on 12 hour clock format
    bool the24HourFormat; // variable for 24 hour clock format
    int timeZone; // variable to input the time zone
public:
    Clock() {
        time_t currentTime = time(0); // current time
        tm *localTime = localtime(&currentTime); // allows you to convert the time to local time
        hours = localTime->tm_hour; // set the hours
        minutes = localTime->tm_min; // set the minutes
        seconds = localTime->tm_sec; // set the seconds
        the12HourClock = true; // set the clock to 12 hour clock format
        nowPM = true; // set the time to PM
        the24HourFormat = true; // set the clock to 24 hour clock format
        timeZone = 4; // set the time zone ahead 4 hours (PST)
    }
    void addHour() {
        hours = (hours + 1) % 24; // increase the hours. Keep between 0-23
        if(hours == 60)
        {
            if(nowPM)
            {
                nowPM = false; // if the hour is 0 and time is PM, set it to AM
            }
            else
            {
                nowPM = true; // if the hour is 0 and time is AM, set it to PM
            }
        }
    }

    void addMinute() {
        minutes = (minutes + 1) % 60; // increase the minutes. Keep between 0-59
        if (minutes == 60) {
            addHour(); // increase the hour if minutes is 60
        }
    }

    void addSecond() {
        seconds = (seconds + 1) % 60; // increase the seconds. Keep between 0-59
        if (seconds == 60) {
            addMinute(); // increase the minute if seconds is 60
        }
    }

    void time_t12HourClockFormat() {
        the12HourClock = !the12HourClock; // clock format between 12 hour and 24 hour
    }

    void time_t24HourClockFormat() {
        the24HourFormat = !the24HourFormat; // clock format between 24 hour and 12 hour
    }

    void setTimeZone(int timeZone) {
        this->timeZone = timeZone; // set the time zone of choice
    }

    void displayClock() {
        if (the24HourFormat) {
            std::cout << hours << ":" << minutes << ":" << seconds;
        } else {
            int hour = (hours % 12 == 0) ? 12 : hours % 12; // convert the hours to 12 hour clock format
            std::cout << hour << ":" << minutes << ":" << seconds;
            if(nowPM)
            {
                std::cout << " PM";
            }
                        else
            {
                std::cout << " AM";
            }
        }
        if (timeZone != 0) {
            std::cout << " (PST " << ((timeZone > 0) ? "+" : "") << timeZone << ")";
        }
    }
};

int main() {
    Clock time;

    while (true) {
        std::cout << "Clock: ";
        time.displayClock();

        std::cout << "\n\nMenu: \n1. Add Hour \n2. Add Minute \n3. Add Second \n4. time_t12HourClockFormat \n5. time_t24HourClockFormat \n6. Set Time Zone \n7. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                time.addHour();
                break;
            case 2:
                time.addMinute();
                break;
            case 3:
                time.addSecond();
                break;
            case 4:
                time.time_t12HourClockFormat();
                break;
            case 5:
                time.time_t24HourClockFormat();
                break;
            case 6:
                int timeZone;
                std::cout << "Enter time zone of choice: ";
                std::cin >> timeZone;
                time.setTimeZone(timeZone);
                break;
            case 7:
                return 9;
            default:
                break;
        }
    }
    return 0;
}