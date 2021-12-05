#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream infile("input3.txt");
// ifstream infile("test.txt");

struct position
{
    string direction;
    unsigned int unit;
};

char find_majority(vector<string> input, unsigned int bit_position)
{
    unsigned int onecount = 0;
    for (int i = 0; i < input.size(); i++)
    {
            cout << "input: " << input[i] << endl;
            if (input[i][bit_position] == '1')
            {
                onecount++;
            }
    }

    cout << "onecount at " << bit_position << " is: " << onecount << " and size: " << input.size() << endl;
    if (onecount > (input.size() / 2.0) || onecount == (input.size() / 2.0))
    {
        cout << "returning 1" << endl;
        return '1';
    } else {
        return '0';
    }
}

char find_minority(vector<string> input, unsigned int bit_position)
{
    unsigned int onecount = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i][bit_position] == '1')
        {
            onecount++;
        }
    }

    cout << "minority onecount at " << bit_position << " is: " << onecount << endl;
    if (onecount > (input.size() / 2.0) || onecount == (input.size() / 2.0))
    {
        return '0';
    }
    else
    {
        return '1';
    }
}

int main()
{
    unsigned int unit;
    vector<string> reports;
    vector<string> o2;
    vector<string> co2;
    vector<unsigned int> onecounts(12);
    string gamma;
    string epsilon;
    string report;

    while (infile >> report)
    {
        // cout << report << endl;
        reports.push_back(report);
    }

    cout << "Size: " << reports.size() << endl;

    o2 = co2 = reports;
    cout << "Oxygen size: " << o2.size() << endl;

    for (int i = 0; i < 12; i++)
    {
        char c = find_majority(o2, i);
        cout << "Majority: " << c << endl;
        for (auto itr = o2.begin(); itr != o2.end() && (o2.size() > 1);)
        {
            if ((*itr)[i] != c)
            {
                itr = o2.erase(itr);
            } else {
                itr++;
            }
        }
    }

    for (int i = 0; i < 12; i++)
    {
        char c = find_minority(co2, i);
        cout << "Minorrity: " << c << endl;
        for (auto itr = co2.begin(); itr != co2.end() && (co2.size() > 1);)
        {
            if ((*itr)[i] != c)
            {
                itr = co2.erase(itr);
            }
            else
            {
                itr++;
            }
        }
    }
   
    cout << "o2: " << o2[0] << " and size: " << o2.size() << endl;
    cout << "co2: " << co2[0] << " and size: " << co2.size() << endl;
    cout << "Output: " << stoull(o2[0], 0, 2) * stoull(co2[0], 0, 2) << endl;
    return 0;
}