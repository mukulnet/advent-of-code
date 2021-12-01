#include <fstream>
#include <iostream>
using namespace std;
ifstream infile("input1.txt");


int main()
{
    unsigned int depth;
    unsigned int previous = 0;
    unsigned int first_int = 0;
    unsigned int count = 0;
    string first;

    getline(infile, first);
    cout << "first " << first << endl;
    previous = stoi(first);
    // cout << "first int " << first_int << endl;
    while (infile >> depth)
    {
        cout << depth << endl;
        if (depth > previous)
        {
            count++;
        }
        previous = depth;
    }


cout << "Result: " << count << endl;
return 0;
}