#include <bits/stdc++.h>
using namespace std;

struct Job {
    string jobName;  // Job name
    int deadline;    // Deadline of the job
    int profit;      // Profit if the job is completed before or on the deadline
};

// Comparator function to sort jobs according to profit in decreasing order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs) {
    // Sort all jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find the maximum deadline to create a timeline array
    int maxDeadline = 0;
    for (Job job : jobs) {
        if (job.deadline > maxDeadline) {
            maxDeadline = job.deadline;
        }
    }

    // Create a timeline to keep track of scheduled jobs
    vector<string> timeline(maxDeadline + 1, "");

    int totalProfit = 0;

    for (Job job : jobs) {
        // Find a free time slot for the job (starting from its deadline)
        for (int j = job.deadline; j > 0; j--) {
            if (timeline[j] == "") {
                timeline[j] = job.jobName;
                totalProfit += job.profit;
                break;
            }
        }
    }

    // Print the scheduled jobs and the total profit
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (timeline[i] != "") {
            cout << timeline[i] << " ";
        }
    }
    cout << endl;

    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    // List of jobs with job name, deadline, and profit
    vector<Job> jobs = { {"Job1", 2, 100}, {"Job2", 1, 19}, {"Job3", 2, 27}, {"Job4", 1, 25}, {"Job5", 3, 15} };

    jobScheduling(jobs);

    return 0;
}
