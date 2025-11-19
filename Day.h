#ifndef DAY_H
#define DAY_H

#include <string>
#include "Task.h"
using namespace std;

struct HourSlot {
    string name;
    string type; // "FREE", "SLEEP", "MEAL", "EXERCISE", "COMMUTE", "EVENT", "TASK"
    Task* taskPtr; // pointer to task (nullptr if not a task)
};

class Day {
private:
    HourSlot hours[24];

public:
    Day();

    bool isFree(int time);
    bool canOverride(int time, Task* t);
    bool scheduleHour(int time, Task* t); // schedule task considering collisions

    void setSleep(int start, int duration);
    void setMeal(int time);
    void setExercise(int start, int duration);
    void setCommute(int start, int duration);
    void setEvent(int start, int duration, string name);

    void printDay();
};

#endif
