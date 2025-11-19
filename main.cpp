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
    cout << "What time do you go to sleep? (0-23): ";
    cin >> sleepStart;
    cout << "How many hours do you sleep? ";
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
        cout << "Exercise start time: ";
        cin >> t;
        cout << "Duration hours: ";
        cin >> d;
        day.setExercise(t, d);
    }

    // --- Commute ---
    char com;
    cout << "Do you commute? (y/n) ";
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
    cout << "Any events? (y/n) ";
    cin >> ev;
    if (ev == 'y') {
        int t, d;
        string name;
        cout << "Event name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Start time: ";
        cin >> t;
        cout << "Duration hours: ";
        cin >> d;
        day.setEvent(t, d, name);
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
        scheduler.addTask(t, day);

        cout << "More tasks? (y/n) ";
        cin >> more;
        cin.ignore();
    }

    // --- Print final schedule ---
    cout << "\n===== FINAL DAY SCHEDULE =====\n";
    day.printDay();

    return 0;
}
