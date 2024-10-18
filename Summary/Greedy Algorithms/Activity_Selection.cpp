#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities are: " << endl;
    int lastSelected = 0;
    cout << "(" << activities[lastSelected].start << ", " << activities[lastSelected].finish << ")" << endl;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= activities[lastSelected].finish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")" << endl;
            lastSelected = i;
        }
    }
}

int main() {
    vector<Activity> activities = { {5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9} };

    activitySelection(activities);

    return 0;
}
