#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& Profit, vector<int>& Weight, int total_weight) {
    vector<pair<double, int>> Profit_weight;

    for (int i = 0; i < Profit.size(); i++) {
        Profit_weight.push_back({ (double)Profit[i] / Weight[i], Weight[i] });
    }

    sort(Profit_weight.begin(), Profit_weight.end(), [](pair<double, int>& a, pair<double, int>& b) {
        return a.first > b.first;
        });

    double max_profit = 0.0;

    for (int i = 0; i < Profit_weight.size(); i++) {
        if (Profit_weight[i].second <= total_weight) {
            max_profit += Profit_weight[i].first * Profit_weight[i].second;
            total_weight -= Profit_weight[i].second;
        }
        else {
            max_profit += Profit_weight[i].first * total_weight;
            break;
        }
    }

    return max_profit;
}

int main() {
    vector<int> Profit = { 60, 100, 120 };
    vector<int> Weight = { 10, 20, 40 };
    int total_weight = 40;

    double total_profit = fractionalKnapsack(Profit, Weight, total_weight);

    cout << "Total Profit Is : " << total_profit << endl;

    return 0;
}
