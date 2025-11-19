#include "Day.h"
#include <iostream>
using namespace std;

Day::Day() {
    for (int i = 0; i < 24; i++)
        hours[i] = "FREE";
}

void Day::setSleep(int start, int duration) {
    for (int i = 0; i < duration; i++) {
        int hour = (start + i) % 24;
        hours[hour] = "SLEEP";
    }
}

void Day::setMeal(int time) {
    if (time >= 0 && time < 24)
        hours[time] = "MEAL";
}

void Day::setExercise(int start, int duration) {
    for (int i = 0; i < duration; i++) {
        int hour = (start + i) % 24;
        hours[hour] = "EXERCISE";
    }
}

void Day::setCommute(int start, int duration) {
    for (int i = 0; i < duration; i++) {
        int hour = (start + i) % 24;
        hours[hour] = "COMMUTE";
    }
}

void Day::setEvent(int start, int duration, string name) {
    for (int i = 0; i < duration; i++) {
        int hour = (start + i) % 24;
        hours[hour] = name;
    }
}

bool Day::isFree(int time) {
    return hours[time] == "FREE";
}

void Day::blockHour(int time, string label) {
    if (time >= 0 && time < 24)
        hours[time] = label;
}

void Day::printDay() {
    for (int i = 0; i < 24; i++) {
        cout << i << ":00 - " << hours[i] << endl;
    }
}
