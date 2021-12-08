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
    vector<char> fish;

    vector<unsigned long long> fish_count(9);

   //Input

   getline(infile, inline1);
  
   stringstream s_stream(inline1); //create string stream from the string

    while (s_stream.good())
    {
        string substr;
        getline(s_stream, substr, ',');
        fish_count[stoi(substr)]++;
    }

    for (auto a : fish_count)
    {
        cout << a << endl;
    }
    cout << "Size: " << fish_count.size() << endl;


    for (int day = 0; day < 256; day++)
    {
        unsigned long long zero_count = fish_count[0];
        for (int i = 1; i < fish_count.size(); i++)
        {
            fish_count[i-1] = fish_count[i];
        }
   
        fish_count[6] += zero_count;
        fish_count[8] = zero_count;
        cout << "Changed fish count of 8 to " << zero_count << endl;
    }

    for (auto a : fish_count)
    {
        cout << a << endl;
    }

    cout << "Afterwards" << endl;
    unsigned long long sum = 0;
    for (auto a : fish_count)
    {
        cout << a << endl;
        sum += a;
    }
    cout << sum << endl;
    // cout << "Count is: " << count << endl;
    return 0;
}