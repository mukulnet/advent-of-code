#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

using namespace std;
ifstream infile("input6.txt");
// ifstream infile("test.txt");


int main()
{
    string inline1;
    vector<unsigned int> fish;

   //Input

   getline(infile, inline1);
  
   stringstream s_stream(inline1); //create string stream from the string

    while (s_stream.good())
    {
        string substr;
        getline(s_stream, substr, ',');
        fish.push_back(stoi(substr));
    }

    for (auto a : fish)
    {
        cout << a << endl;
    }
    cout << fish.size() << endl;


    for (int day = 0; day < 80; day++)
    {
        unsigned int school = fish.size();
        for (int i = 0; i < school; i ++)
        {
            if (fish[i] == 0)
            {
                fish[i] = 6;
                fish.push_back(8);
            } else {
                fish[i]--;
            }
        }
    }

    cout << "Afterwards" << endl;
    // for (auto a : fish)
    // {
    //     cout << a << endl;
    // }
    cout << fish.size() << endl;
    // cout << "Count is: " << count << endl;
    return 0;
}