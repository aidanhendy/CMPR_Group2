#include "Day.h"
#include <iostream>
using namespace std;

Day::Day() {
    for (int i = 0; i < 24; i++) {
        hours[i].name = "FREE";
        hours[i].type = "FREE";
        hours[i].taskPtr = nullptr;
    }
}

bool Day::isFree(int time) 
{
    return hours[time].type == "FREE";
}

bool Day::canOverride(int time, Task* t) {
    if (hours[time].type == "FREE") return true;
    if (hours[time].type != "TASK") return false; // immutable
    if (hours[time].taskPtr->getPriority() < t->getPriority()) 
    {
        return true;
    }

    return false;
}

bool Day::scheduleHour(int time, Task* t) {
    if (time < 0 || time >= 24) return false;

    if (canOverride(time, t)) {
        Task* displaced = hours[time].taskPtr;

        hours[time].name = t->getName();
        hours[time].type = "TASK";
        hours[time].taskPtr = t;

        if (displaced != nullptr) {
            bool rescheduled = false;
            for (int i = 0; i < 24; i++) {
                if (i == time) continue;
                if (scheduleHour(i, displaced)) {
                    rescheduled = true;
                    break;
                }
            }
            if (!rescheduled) {
                cout << "Task removed due to no available slots: " << displaced->getName() << endl;
            }
        }
        return true;
    }
    return false;
}

// Sleep, meals, exercise, commute, events are immutable
void Day::setSleep(int start, int duration) 
{
    for (int i = 0; i < duration; i++) 
    {
        int hr = (start + i) % 24;
        hours[hr].name = "SLEEP";
        hours[hr].type = "SLEEP";
        hours[hr].taskPtr = nullptr;
    }
}

void Day::setMeal(int time) 
{
    hours[time].name = "MEAL";
    hours[time].type = "MEAL";
    hours[time].taskPtr = nullptr;
}

void Day::setExercise(int start, int duration) 
{
    for (int i = 0; i < duration; i++) {
        int hr = (start + i) % 24;
        hours[hr].name = "EXERCISE";
        hours[hr].type = "EXERCISE";
        hours[hr].taskPtr = nullptr;
    }
}

void Day::setCommute(int start, int duration) 
{
    for (int i = 0; i < duration; i++) {
        int hr = (start + i) % 24;
        hours[hr].name = "COMMUTE";
        hours[hr].type = "COMMUTE";
        hours[hr].taskPtr = nullptr;
    }
}

void Day::setEvent(int start, int duration, string name) 
{
    for (int i = 0; i < duration; i++) {
        int hr = (start + i) % 24;
        hours[hr].name = name;
        hours[hr].type = "EVENT";
        hours[hr].taskPtr = nullptr;
    }
}

void Day::printDay() {
    for (int i = 0; i < 24; i++) {
        cout << i << ":00 - " << hours[i].name;
        if (hours[i].type == "TASK" && hours[i].taskPtr != nullptr)
            cout << " (Priority: " << hours[i].taskPtr->getPriority() << ")";
        cout << " (" << hours[i].type << ")" << endl;
    }
}

