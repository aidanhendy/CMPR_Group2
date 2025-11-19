#include <iostream>
#include <string>
#include "Task.h"
#include "Day.h"
#include "Scheduler.h"

using namespace std;

int main() {
    Day day;
    Scheduler scheduler;

    // --- Sleep ---
    int sleepStart, sleepDuration;
    cout << "Sleep start hour (0-23): ";
    cin >> sleepStart;
    cout << "Sleep duration hours: ";
    cin >> sleepDuration;
    day.setSleep(sleepStart, sleepDuration);

    // --- Meals ---
    int meals;
    cout << "How many meals today? ";
    cin >> meals;
    for (int i = 0; i < meals; i++) {
        int t;
        cout << "Meal time (0-23): ";
        cin >> t;
        day.setMeal(t);
    }

    // --- Exercise ---
    char ex;
    cout << "Do you exercise? (y/n) ";
    cin >> ex;
    if (ex == 'y') {
        int t, d;
        cout << "Exercise start: ";
        cin >> t;
        cout << "Duration hours: ";
        cin >> d;
        day.setExercise(t, d);
    }

    // --- Commute ---
    char com;
    cout << "Do you commute? (drive > 1 hour) (y/n) ";
    cin >> com;
    if (com == 'y') {
        int t, d;
        cout << "Commute start: ";
        cin >> t;
        cout << "Commute duration: ";
        cin >> d;
        day.setCommute(t, d);
    }

    // --- Events ---
    char ev;
    cout << "Any events today? (y/n) ";
    cin >> ev;
    if (ev == 'y') {
        int numEvents;
        cout << "How many events today? ";
        cin >> numEvents;
        cin.ignore();

        for (int i = 0; i < numEvents; i++) {
            string name;
            int start, duration;
            cout << "\nEvent " << i + 1 << " name: ";
            getline(cin, name);
            cout << "Start time (0-23): ";
            cin >> start;
            cout << "Duration in hours: ";
            cin >> duration;
            cin.ignore();

            day.setEvent(start, duration, name);
        }
    }

    // --- Tasks ---
    char more = 'y';
    cin.ignore();
    while (more == 'y') {
        string name;
        int diff, pri;

        cout << "\nTask name: ";
        getline(cin, name);

        cout << "Difficulty (1-10): ";
        cin >> diff;
        cout << "Priority (1-10): ";
        cin >> pri;
        cin.ignore();

        Task t(name, pri, diff);
        scheduler.pushTask(t);

        cout << "More tasks? (y/n) ";
        cin >> more;
        cin.ignore();
    }

    // Schedule all tasks in priority order
    scheduler.scheduleAll(day);

    cout << "\n===== FINAL DAY SCHEDULE =====\n";
    day.printDay();

    

    return 0;
}
