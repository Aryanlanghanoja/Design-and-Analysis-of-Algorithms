#include <bits/stdc++.h>
using namespace std;

class Job {
public:
    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit)
        : id(id), deadline(deadline), profit(profit) {
    }
};

pair<int, long long> Job_Scheduling(vector<Job> jobs) {

    long long Max_Profit = 0.0;
    int count_of_jobs = 0;
    int max_deadline = -1;

    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
        });

    for (const Job& job : jobs) {
        max_deadline = max(max_deadline, job.deadline);
    }

    vector<int> selectedJobs(max_deadline + 1, -1);

    for (int i = 0; i < jobs.size(); i++) {
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (selectedJobs[j] == -1) {
                selectedJobs[j] = jobs[i].id;
                count_of_jobs++;
                Max_Profit += jobs[i].profit;
                break;
            }
        }
    }

    return { count_of_jobs , Max_Profit };
}

int main() {
    vector<Job> jobs;
    vector<int> deadline = { 2,1,2,1,3};
    vector<int> profit = {100,19,27,25,15};

    for (int i = 0; i < deadline.size(); i++) {
        jobs.push_back(Job(i + 1, deadline[i], profit[i]));
    }

    pair<int, long long> Count_and_profit = Job_Scheduling(jobs);

    cout << "We can Perform " << Count_and_profit.first << " and Earn Profit of Rs. " << Count_and_profit.second << " ." << endl;

    return 0;

}
