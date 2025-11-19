#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include "Task.h"
#include "Day.h"
using namespace std;

class Scheduler {
private:
    priority_queue<Task> tasks;

public:
    Scheduler();

    void addTask(Task t, Day &day);
    int difficultyToHours(int diff);
};

#endif
