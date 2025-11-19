#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
private:
    string name;
    int priority;    // 1-10, bigger = more important
    int difficulty;  // 1-10

public:
    Task();
    Task(string n, int p, int d);

    string getName() const;
    int getPriority() const;
    int getDifficulty() const;

    // For priority_queue ordering
    bool operator<(const Task &other) const;
};

#endif
