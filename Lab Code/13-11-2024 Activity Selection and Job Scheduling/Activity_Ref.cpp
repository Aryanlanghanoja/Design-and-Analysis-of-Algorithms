#include <iostream>
#include <algorithm>
using namespace std;

// Activity class to represent an activity with start and finish times
class Activity {
public:
    int start, finish;

    // // Default constructor
    // Activity() {}

    // Constructor
    Activity(int start = 0, int finish = 0) : start(start), finish(finish) {}
};

// Comparator function to sort activities by their finish times
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// ActivitySelection class that contains methods to perform activity selection
class ActivitySelection {
public:
    // Method to print the maximum set of activities
    void printMaxActivities(Activity activities[], int n) {
        // Sort activities based on finish time
        sort(activities, activities + n, compare);
        cout << "Following activities are selected:" << endl;

        // The first activity is always selected
        int i = 0;
        cout << "(" << activities[i].start << ", " << activities[i].finish << ")";

        // Consider the rest of the activities
        for (int j = 1; j < n; j++) {
            // If the start time of this activity is greater or equal to the finish time of the previously selected activity
            if (activities[j].start >= activities[i].finish) {
                cout << ", (" << activities[j].start << ", " << activities[j].finish << ")";
                i = j;
            }
        }
        cout << endl;
    }
};

int main() {
    // Initialize the array of activities with start and finish times
    // Activity activities[] = {
    //     Activity(5, 9),
    //     Activity(1, 2),
    //     Activity(3, 4),
    //     Activity(0, 6),
    //     Activity(5, 7),
    //     Activity(8, 9)
    // };

    // int n = sizeof(activities) / sizeof(activities[0]);

    int n;

    cout << "Enter the number of activities: ";
    cin >> n;

    Activity activities[n];

    for (int i = 1; i <= n; i++) {
        cout << "Enter start time of activity " << i << ": ";
        cin >> activities[i - 1].start;

        cout << "Enter finish time of activity " << i << ": ";
        cin >> activities[i - 1].finish;
        cout << endl;
        // activities[i - 1] = Activity(start_time, finish_time);
    }

    // Create an object of ActivitySelection and call printMaxActivities
    ActivitySelection selector;
    selector.printMaxActivities(activities, n);

    return 0;
}
