#ifndef DAY_H
#define DAY_H

#include <string>
using namespace std;

class Day {
private:
    string hours[24];

public:
    Day();

    void setSleep(int start, int duration);
    void setMeal(int time);
    void setExercise(int start, int duration);
    void setCommute(int start, int duration);
    void setEvent(int start, int duration, string name);

    bool isFree(int time);
    void blockHour(int time, string label);
    void printDay();
};

#endif
