#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
ifstream infile("input4.txt");
// ifstream infile("test.txt");

vector<unsigned int> called_numbers;

class card
{
    public:
        unsigned int index;
        vector<vector<unsigned int>> numbers;
        vector<vector<unsigned int>> card_all_rows;
        unsigned int bingo_pos;
        // vector<unsigned int> card_columns;

        void print_card();
        void generate_all_rows();
        void print_all_rows();
};

// struct card
// {
//     unsigned int index;
//     vector<vector<unsigned int>> numbers;
//     vector<unsigned int> card_rows;
//     vector<unsigned int> card_columns;
// };

void card::print_card()
{
    cout << "Index: " << index << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < numbers[i].size(); j++)
        {
            cout << numbers[i][j] << " ";
        }
        cout << endl;

    }
}

void card::print_all_rows()
{
    cout << "Printing all rows" << endl;
    for (int i = 0; i < card_all_rows.size(); i++)
    {
        for (int j = 0; j < card_all_rows[i].size(); j++)
        {
            cout << card_all_rows[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void card::generate_all_rows()
{
    card_all_rows = numbers;
    vector<unsigned int>* temp_row = new vector<unsigned int>;

    cout << "Generating rows" << endl;
    for (int i = 0; i < numbers[0].size(); i++)
    {
        for (int j = 0; j < numbers.size(); j++)
        {
            cout << numbers[j][i] << " ";
            (*temp_row).push_back(numbers[j][i]);
        }
        cout << endl;

        card_all_rows.push_back(*temp_row);
        temp_row->clear();
     }
}

int find_in_called_numbers(unsigned int item)
{
    for (int i = 0; i < called_numbers.size(); i++)
    {
        if (called_numbers[i] == item)
        {
            // cout << "Found item: " << item << endl;
            return i;
        }
    }

    return -1;
}

int check_if_bingo(vector<unsigned int> row)
{
    vector<unsigned int> indexes;
    unsigned hit_count = 0;
    // cout << "check if bingo" << endl;

    for (auto a : row)
    {
        // cout << a << " ";
    }
    cout << endl;
    for (int i = 0; i < row.size(); i++)
    {
        int ret = find_in_called_numbers(row[i]);
        if (ret != -1)
        {
            hit_count++;
            indexes.push_back(ret);
        }
    }

    if (hit_count == 5)
    {
        // This line is a bingo
        // cout << " Max index: " << *max_element(indexes.begin(), indexes.end()) << endl;
        return (*max_element(indexes.begin(), indexes.end()));
    }

    return -1;
}


int main()
{
    unsigned int unit;
    string line;
    vector<card> cards;

    //Input
    getline(infile, line);

    stringstream s_stream(line); //create string stream from the string
    while (s_stream.good())
    {
        string substr;
        getline(s_stream, substr, ','); 
        called_numbers.push_back(stoi(substr));
    }
    for (int i = 0; i < called_numbers.size(); i++)
    { 
        cout << called_numbers[i] << endl;
    }

    cout << endl;
    unsigned int i = 0;
    unsigned int card_index = 0;
    unsigned int a, b, c, d, e;
    card temp_card;
    temp_card.index = 0;

    while (infile >> a >> b >> c >> d >> e)
    {

        vector<unsigned int> card_row = {a, b, c, d, e};
        
        // for (auto j : card_row)
        //     cout << j << endl;
        // cout << "card_index: " << card_index << endl;

        temp_card.numbers.push_back(card_row);
    
        card_index = i / 5;
        temp_card.index = card_index;
        // cout << "card_index: " << card_index << endl;

        i++;

        if (i % 5 == 0)
        {
            cards.push_back(temp_card);
            temp_card.numbers.clear();
        }

    }

    // Print what was read
    for (auto my_card : cards)
    {
        my_card.print_card();
    }


    // Index where the last bingo happens
    int last_bingo_pos = 0;
    int bingo_card = 0;
    set<unsigned int> cards_bingoed;
    int last_bingo_card = -1;

    for (int ii = 0; ii < cards.size(); ii++)
    {
        card& my_card = cards[ii]; 
        my_card.generate_all_rows();

        int i = 0;
        cout << "Card: " << my_card.index << endl;
        cout << "Size: " << my_card.card_all_rows.size() << endl;;
        my_card.print_all_rows();
        my_card.bingo_pos = 101;

        for (int i = 0; i < my_card.card_all_rows.size(); i++)
        {
            int bingo_pos = check_if_bingo(my_card.card_all_rows[i]);

            if (bingo_pos != -1)
            {
                cout << "Card: " << my_card.index << " bingoed with " << called_numbers[bingo_pos] <<
                " at position " << bingo_pos << endl;

                if (bingo_pos < my_card.bingo_pos)
                {
                    my_card.bingo_pos = bingo_pos;
                }

                // if (cards_bingoed.find(my_card.index) == cards_bingoed.end())
                // {
                //     cards_bingoed.insert(my_card.index);
                //     last_bingo_card = my_card.index;
                //     last_bingo = bingo_pos;
                // }
            }

        }
        cout << "This card " << my_card.index << " Bingoed for the first time at " <<
         my_card.bingo_pos<< endl;

        cout << endl;
    }

    for (auto my_card : cards)
    {
        cout << "Bingo pos " << my_card.bingo_pos << endl;
        cout << "Last pos " << last_bingo_pos << endl;
        cout << "Is  " <<  my_card.bingo_pos << " > " << last_bingo_pos << endl;

        if (my_card.bingo_pos > last_bingo_pos)
        {
            cout << "yes it is ";
            last_bingo_card = my_card.index;
            last_bingo_pos = my_card.bingo_pos;
        }
    }
    cout << "Card is " << last_bingo_card << " at position " << last_bingo_pos << endl;
    cout <<  " with number: " << called_numbers[last_bingo_pos] << endl;

    cards[last_bingo_card].print_card();
    unsigned sum = 0;

    for (int i = 0; i < cards[last_bingo_card].numbers.size(); i++)
    {
        for (int j = 0; j < cards[last_bingo_card].numbers[0].size(); j++)
        {
            int number = cards[last_bingo_card].numbers[i][j];
            if (find_in_called_numbers(number) > last_bingo_pos)
            {
                sum += number;
           }
          }
    }

    cout << "Sum is: " << sum << endl;
    cout << "Solution is: " << sum * called_numbers[last_bingo_pos] << endl;
    return 0;
}