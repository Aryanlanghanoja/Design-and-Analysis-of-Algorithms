#include <bits/stdc++.h>
using namespace std;

class Activity
{
public:
    int id;
    int start;
    int end;

    Activity(int id, int start, int end) : id(id), start(start), end(end) {}
};

vector<Activity> Activity_Selection(vector<Activity> &activities)
{
    vector<Activity> selected_activities;

    sort(activities.begin(), activities.end(), [](Activity a, Activity b)
         {
        if (a.end == b.end) {
            return a.start < b.start;
        } 
        return a.end < b.end; });

    selected_activities.push_back(activities[0]);
    int last_activity_end = selected_activities.back().end;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].start >= last_activity_end)
        {
            selected_activities.push_back(activities[i]);
            last_activity_end = selected_activities.back().end;
        }
    }

    return selected_activities;
}

int main()
{
    vector<Activity> activities;
    vector<int> start_time = {5, 1, 3, 0, 5, 8, 6};
    vector<int> end_time = {9, 2, 4, 6, 7, 9, 9};

    for (int i = 0; i < start_time.size(); i++)
    {
        activities.push_back(Activity(i + 1, start_time[i], end_time[i]));
    }

    vector<Activity> selected_activities = Activity_Selection(activities);

    cout << "Selected Activities are:" << endl;
    for (auto activity : selected_activities)
    {
        cout << "Activity ID: " << activity.id
             << ", Start Time: " << activity.start
             << ", End Time: " << activity.end << endl;
    }

    return 0;
}
