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
    int difficultyToHours(int diff);

    void pushTask(Task t);          // Add task to priority queue
    void scheduleAll(Day &day);     // Schedule all tasks in priority order
};

#endif
