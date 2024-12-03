#include <iostream>
#include <algorithm>
using namespace std;

class Job {
public:
    int id, deadline, profit;

    // Constructor
    Job(int id = 0, int deadline = 0, int profit = 0)
        : id(id), deadline(deadline), profit(profit) {
    }
};

class JobScheduling {
public:
    // Function to schedule jobs and maximize profit
    void scheduleJobs(Job jobs[], int n) {
        // Step 1: Sort jobs by profit in descending order
        sort(jobs, jobs + n, [](Job a, Job b) {
            return a.profit > b.profit;
            });

        // Find the maximum deadline to determine the number of slots needed
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            if (jobs[i].deadline > maxDeadline) {
                maxDeadline = jobs[i].deadline;
            }
        }

        // Step 2: Initialize an array to keep track of free time slots
        int* result = new int[maxDeadline]; // To store job ids in selected time slots
        bool* slot = new bool[maxDeadline]; // Track occupied slots
        fill(slot, slot + maxDeadline, false);

        int totalProfit = 0;

        // Step 3: Iterate through all jobs
        for (int i = 0; i < n; i++) {
            // Find a free slot for this job (starting from the last possible slot)
            for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
                if (!slot[j]) { // If the slot is free
                    result[j] = jobs[i].id; // Assign the job id to the slot
                    slot[j] = true; // Mark the slot as occupied
                    totalProfit += jobs[i].profit; // Add the profit
                    break;
                }
            }
        }

        // Print selected jobs and total profit
        cout << "Jobs scheduled: ";
        for (int i = 0; i < maxDeadline; i++) {
            if (slot[i]) {
                cout << "Job " << result[i] << " ";
            }
        }
        cout << "\nTotal Profit: " << totalProfit << endl;

        // Clean up dynamically allocated arrays
        delete[] result;
        delete[] slot;
    }
};

int main() {
    // // Array of jobs (id, deadline, profit)
    // Job jobs[] = {
    //     Job(1, 2, 100),
    //     Job(2, 1, 19),
    //     Job(3, 2, 27),
    //     Job(4, 1, 25),
    //     Job(5, 3, 15)
    // };
    // int n = sizeof(jobs) / sizeof(jobs[0]);

    // // Create an instance of JobScheduling and schedule jobs
    // JobScheduling scheduler;
    // scheduler.scheduleJobs(jobs, n);

    int n;
    cout << "Enter the number of jobs :- ";
    cin >> n;

    Job jobs[n];

    for (int i = 1; i <= n; i++) {
        int deadline;
        int profit;

        cout << "Enter deadline for job " << i << ": ";
        cin >> deadline;

        cout << "Enter profit for job " << i << ": ";
        cin >> profit;

        jobs[i-1] = Job(i+1  , deadline, profit);
    }

    JobScheduling scheduler;
    scheduler.scheduleJobs(jobs, n);
    return 0;
}
