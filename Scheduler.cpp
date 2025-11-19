#include "Scheduler.h"

Scheduler::Scheduler() {}

int Scheduler::difficultyToHours(int diff) {
    if (diff <= 3) return 1;
    if (diff <= 5) return 2;
    if (diff <= 8) return 3;
    return 4;
}

void Scheduler::addTask(Task t, Day &day) {
    int hoursNeeded = difficultyToHours(t.getDifficulty());
    int filled = 0;

    for (int i = 0; i < 24 && filled < hoursNeeded; i++) {
        if (day.isFree(i)) {
            day.blockHour(i, t.getName());
            tasks.push(t);  // STL priority_queue push
            filled++;
        }
    }
}
