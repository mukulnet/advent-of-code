#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream infile("input2.txt");
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
    vector<unsigned int> sums;
    unsigned int horizontal = 0;
    unsigned int depth = 0;
    string direction;

    while (infile >> direction >> unit)
    {
        cout << direction << endl;
        cout << unit << endl;
        position temp_position {direction, unit};

        positions.push_back(temp_position);
    }

    cout << "Size: " << positions.size() << endl;

    for (int i = 0; i < positions.size(); i++)
    {
        if (positions[i].direction == "forward")
        {
            horizontal += positions[i].unit;
        }
        if (positions[i].direction == "up")
        {
            depth -= positions[i].unit;
        }
        if (positions[i].direction == "down")
        {
            depth += positions[i].unit;
        }
    }


    //    for (int i = 1; i < sums.size(); i++)
    //    {
    //        if (sums[i] > sums[i - 1])
    //        {
    //            count++;
    //        }
    //    }

    cout << "Results: " << horizontal << "  and " << depth << endl;
    cout << "Output: " << horizontal * depth << endl;
    return 0;
}