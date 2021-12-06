#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

using namespace std;
ifstream infile("input5_mod.txt");
// ifstream infile("test.txt");

vector<vector<unsigned int>> bed(991, vector<unsigned int>(991, 0));
// vector<vector<unsigned int>> bed(10, vector<unsigned int>(10, 0));

void draw_bed()
{
    for (int i = 0; i < bed.size(); i++)
    {
        for (int j = 0; j < bed[0].size(); j++)
        {
            cout << bed[i][j] << " ";
        }
        cout << endl;
    }
}

class line
{
    public:
        pair<int, int> start;
        pair<int, int> end;

        line(int x1, int y1, int x2, int y2);
        void print();
        bool isstraight();
        void draw_straight_line();
        bool isdiagonal();
        void draw_diagonal_line();
};


line::line(int x1, int y1, int x2, int y2)
{
    start.first = x1;
    start.second = y1;
    end.first = x2;
    end.second = y2;
}

bool line::isstraight()
{
    if ((start.first == end.first) || (start.second == end.second))
    {
        return true;
    }

    return false;
}

bool line::isdiagonal()
{
    if (abs(start.first - start.second) == abs(end.first - end.second))
    {
        return true;
    }
    if ((start.first + start.second) == (end.first + end.second))
    {
        return true;
    }

    return false;
}


void line::print()
{
    cout << start.first << ", " << start.second << " -> " << end.first <<
    ", " << end.second << endl;
}


void line::draw_straight_line()
{
    // Vertical Line
    if (start.first == end.first)
    {
        // cout << "Drawing Vertical " << start.first << endl;
        // cout << "Drawing Vertical " << start.second << " to " << end.second<< endl;

        int smaller = min(start.second, end.second);
        int bigger = max(start.second, end.second);

        for (int i = smaller; i <= bigger; i++)
        {
            // cout << "y: " << i << "x: " << start.first << endl;
            bed[i][start.first]++;
        }
    }


    // Horizontal Line
    if (start.second == end.second)
    {
        // cout << "Drawing Horizontal " << start.second << endl;

        int smaller = min(start.first, end.first);
        int bigger = max(start.first, end.first);

        for (int i = smaller; i <= bigger; i++)
        {
            // cout << "x: " << i << "y: " << start.second << endl;
            (bed[start.second][i])++;
        }
    }

    // draw_bed();
    // cout << endl << endl;

}


void line::draw_diagonal_line()
{
    // Going Down \ both ways
    // X increasing, Y increasing
    // Or
    // X decreasing, Y decreasing

    cout << "Drawing Diagonal " << start.first << "," << start.second
    << " to " << end.first << "," << end.second<< endl;

    if (start.first < end.first && start.second < end.second)
    {
        for (int i = start.first, j = start.second; i <= end.first, j <= end.second; i++, j++)
        {
            bed[j][i]++;
        }
    }

    if (start.first > end.first && start.second > end.second)
    {
        for (int i = start.first, j = start.second; i >= end.first, j >= end.second; i--, j--)
        {
            bed[j][i]++;
        }
    }

    // Going up / both ways
    // X increasing, Y decreasing
    // Or
    // X decreasing, Y increasing
    if (start.first < end.first && start.second > end.second)
    {
        for (int i = start.first, j = start.second; i <= end.first, j >= end.second; i++, j--)
        {
            bed[j][i]++;
        }
    }

    if (start.first > end.first && start.second < end.second)
    {
        for (int i = start.first, j = start.second; i >= end.first, j <= end.second; i--, j++)
        {
            bed[j][i]++;
        }
    }
}

int main()
{
    string inline1;
    vector<line> lines;
    int max_coordinate = 0;
    //Input

  while (getline(infile, inline1))
  {
      stringstream s_stream(inline1); //create string stream from the string

      vector<int> coordinates;
      while (s_stream.good())
      {
          string substr;
          getline(s_stream, substr, ',');
          coordinates.push_back(stoi(substr));
          if (stoi(substr) > max_coordinate)
          {
              max_coordinate = stoi(substr);
          }
      }

      line temp_line(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
      temp_line.print();
      lines.push_back(temp_line);
  }

    cout << "Max: " << max_coordinate << endl;
    

    for (int i = 0; i < lines.size(); i++)
    {
        lines[i].draw_straight_line();

        if (lines[i].isdiagonal())
        {
            // lines[i].print();
            lines[i].draw_diagonal_line();
        }
    }

    // Print the Bed Map
    draw_bed();

    cout << endl;

    int count = 0;
    for (int i = 0; i < bed.size(); i++)
    {
        for (int j = 0; j < bed[0].size(); j++)
        {
            if (bed[i][j] > 1)
            {
                count++;
            }
            cout << j << "," << i << " ";
        }
        cout  << endl;
    }

    cout << "Count is: " << count << endl;
    // cout << "Solution is: " << sum * called_numbers[last_bingo_pos] << endl;
    return 0;
}