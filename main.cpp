#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;

    inFile >> no_problems;
    vector<string> name_prob(no_problems);
    vector<string> speciality1(no_problems);
    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name_prob[i];
        inFile >> speciality1[i];
    }

    inFile >> no_doctors;
    vector<string> numberdoc(no_doctors);
    vector<string> speciality2(no_doctors);
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> numberdoc[i];
        inFile >> speciality2[i];
    }
    for (int i = 0; i < no_problems; i++)
    {
        auto spec = speciality1[i];
        auto it = find(speciality2.begin(), speciality2.end(), spec);
        if (it != speciality2.end())
        {
            cout << numberdoc[i] << " " << speciality1[i]<<endl;
        }
        
    }
    return 0;
}