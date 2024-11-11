#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
    vector<int> numberdoc(no_doctors, 0);
    vector<string> speciality2(no_doctors);
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality2[i];
    }
    for (int i = 0; i < no_problems; i++)
    {
        int ok = 0;
        for (int j = 0; j < no_doctors; j++)
        {
            if (speciality1[i] == speciality2[j] && numberdoc[j] == 0)
            {
                cout << name_prob[i] << " " << "Acceptat" << endl;
                numberdoc[j] = 1;
                ok = 1;
            }
        }
        if (ok == 0) cout << name_prob[i] << " " << "Respins" << endl;
    }
    return 0;
}