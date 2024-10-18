#include <bits/stdc++.h>
using namespace std;

int Knapsack_0_1(vector<int>& Profit, vector<int>& Weigth, int total_weight) {
    vector<pair<double, int>> Profit_weight;

    for (int i = 0; i < Profit.size(); i++) {
        Profit_weight.push_back({ (double)Profit[i] / Weigth[i], Weigth[i] });
    }

    sort(Profit_weight.begin(), Profit_weight.end(), [](pair<double, int>& a, pair<double, int>& b) {
        return a.first > b.first;
        });

    int max_profit = 0;

    for (int i = 0; i < Profit_weight.size(); i++) {
        if (Profit_weight[i].second <= total_weight) {
            max_profit += Profit_weight[i].first * Profit_weight[i].second;
            total_weight -= Profit_weight[i].second;
        }
        else {
            break;
        }
    }

    return max_profit;
}

int main() {
    vector<int> Profit = { 60,100,120,90 };
    vector<int> Weight = { 10,20,20,15 };
    int total_weight = 40;

    int total_profit = Knapsack_0_1(Profit, Weight, total_weight);

    cout << "Total Profit Is : " << total_profit << endl;

    return 0;
}
