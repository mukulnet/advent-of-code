#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream infile("input1.txt");

int main()
{
    unsigned int depth;
    unsigned int count = 0;
    vector<unsigned int> depths;
    vector<unsigned int> sums;

    while (infile >> depth)
    {
        // cout << depth << endl;
        depths.push_back(depth);
    }

    cout << "Size: " << depths.size() << endl;

    for (int i = 0; i < (depths.size() - 2); i++)
    {
        sums.push_back(depths[i] + depths[i + 1] + depths[i + 2]);
        cout << "Depths[i] " << depths[i] << endl;
        cout << "Sums: " << sums.back() << endl;
   }

   for (int i = 1; i < sums.size(); i++)
   {
       if (sums[i] > sums[i - 1])
       {
           count++;
       }
   }

cout << "Result: " << count << endl;
return 0;
}