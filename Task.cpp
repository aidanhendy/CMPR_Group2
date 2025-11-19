#include "Task.h"

Task::Task() {
    name = "";
    priority = 1;
    difficulty = 1;
}

Task::Task(string n, int p, int d) {
    name = n;
    priority = p;
    difficulty = d;
}

string Task::getName() const { return name; }
int Task::getPriority() const { return priority; }
int Task::getDifficulty() const { return difficulty; }

bool Task::operator<(const Task &other) const {
    return priority < other.priority; // max-heap
}
