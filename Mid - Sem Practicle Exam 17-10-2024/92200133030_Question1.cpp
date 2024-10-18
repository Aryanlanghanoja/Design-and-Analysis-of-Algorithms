#include <bits/stdc++.h>
using namespace std;

int Vaccine = 0;

class Region {
public:
    int Region_Id;
    string Region_Name;
    long population;
    int Riskfactor;
    bool need_vaccine;
    long vaccinated;

    Region(int Region_Id, int Region_Name, int population, int Riskfactor) {
        this->Region_Id = Region_Id;
        this->Region_Name = Region_Name;
        this->population = population;
        this->Riskfactor = Riskfactor;
        this->need_vaccine = true;
        vaccinated = 0;
    }
};

void Add_Region_Data(int Region_Id, int Region_Name, int population, int Riskfactor) {
    Region *region = new Region(Region_Id, Region_Name, population, Riskfactor);
    cout << "Region added successfully!" << endl;
    return;
}

void Update_Vaccine(int change) {
    cout << change << "doeses added into the vaccine" << endl;
    Vaccine += change;
    return;
}

void Greedy_Allocation_of_Vaccines(vector<Region>& Regions, vector <pair<string, int>> &report) {
    sort(Regions.begin(), Regions.end(), [](const Region& a, const Region& b) {

        if (a.Riskfactor == b.Riskfactor) {
            return a.population > b.population;
        }

        return a.Riskfactor > b.Riskfactor;
        });

    for (auto& region : Regions) {
        if (Vaccine > 0 && region.need_vaccine) {

            if (Vaccine >= region.population - region.vaccinated) {
                region.need_vaccine = false;
                cout << "Region " << region.Region_Name << " received " << region.population - region.vaccinated << " doses of vaccine." << endl;
                report.push_back({ region.Region_Name  , region.population - region.vaccinated });
                region.vaccinated = region.population;
                Vaccine -= region.population;
            }

            else {
                cout << "Region " << region.Region_Name << " received " << Vaccine << " doses of vaccine." << endl;
                report.push_back({ region.Region_Name  , Vaccine });
                region.vaccinated += Vaccine;
                Vaccine = 0;
            }
        }
    }

    return;
}

void Generate_Distribution_Report(vector<Region>& Regions, vector <pair<string, int>>& report, vector<string, int>& needed) {

    for (auto& region : Regions) {
        if (region.need_vaccine) {
            needed.push_back({ region.Region_Name, region.population });
        }
    }

    for (auto& i : report) {
        cout << "Region -  "<< i.first << " Received " << i.second << " Vaccines." << endl;
    }

    for (auto& region : Regions) {
        if (region.need_vaccine) {
            needed.push_back({ region.Region_Name  , region.population - region.vaccinated });

            cout << "The Region" << region.Region_Name << " needed " << region.population - region.vaccinated << " Vaccines ." << endl;
        }
    }

    cout << "The Remaining vaccines are " << Vaccine << endl;

    for (auto& region : Regions) {
        cout << "Region -  " << region.Region_Name << " has " << region.vaccinated << " and " << (((region.population - region.vaccinated) / region.population) * 100) << endl;
    }
}

int main() {
    vector<Region> Regions;
    vector <pair<string, int>> report;
    vector<string, int> needed;


    return 0;
}