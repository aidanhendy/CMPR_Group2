#include "Scheduler.h"
#include <iostream>
using namespace std;

Scheduler::Scheduler() {}

int Scheduler::difficultyToHours(int diff) {
    if (diff <= 3) return 1;
    if (diff <= 5) return 2;
    if (diff <= 8) return 3;
    return 4;
}

void Scheduler::pushTask(Task t) {
    tasks.push(t);
}

void Scheduler::scheduleAll(Day &day) {
    while (!tasks.empty()) {
        Task t = tasks.top();
        tasks.pop();

        // Allocate task on heap to preserve pointer
        Task* tPtr = new Task(t);

        int hoursNeeded = difficultyToHours(t.getDifficulty());
        int filled = 0;

        for (int i = 0; i < 24 && filled < hoursNeeded; i++) {
            if (day.scheduleHour(i, tPtr)) {
                filled++;
            }
        }

        if (filled < hoursNeeded) {
            cout << "Warning: Not enough available slots for task: " << t.getName() << endl;
        }
    }
}
