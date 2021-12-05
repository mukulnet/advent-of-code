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


int main()
{
    unsigned int unit;
    unsigned int count = 0;
    vector<position> positions;
    vector<string> reports;
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

    for (int i = 0; i < reports.size(); i++)
    {
      for (int j = 0; j < 12; j++)
      {
         if (reports[i][j] == '1')
         {
             onecounts[j]++;
         }
      }
    }

    for (int i = 0; i < onecounts.size(); i++)
    {
        cout << onecounts[i] << endl;
        // cout << (reports.size() / 2) << endl;
        if (onecounts[i] > (reports.size()  / 2))
        {
            gamma.push_back('1');
            epsilon.push_back('0');
            
        } else {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
    } 


    cout << "Rates: " << gamma << "  and " << epsilon << endl;
    cout << "Output: " << stoull(gamma, 0, 2) * stoull(epsilon, 0, 2) << endl;
    return 0;
}