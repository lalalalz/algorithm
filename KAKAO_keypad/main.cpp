#include <string>
#include <vector>
#include <iostream>
using namespace std;

int keypad[12][2] = {{0,  0}, // 0
                     {-1, 3}, // 1
                     {0,  3}, // 2
                     {1,  3}, // 3
                     {-1, 2}, // 4
                     {0,  2}, // 5
                     {1,  2}, // 6
                     {-1, 1}, // 7
                     {0,  1}, // 8
                     {1,  1}, // 9
                     {-1, 0}, // *
                     {1,  0}}; // #
int func(int left, int right, int number)
{
    int leftClosed = abs(keypad[left][0] - keypad[number][0]) + abs(keypad[left][1] - keypad[number][1]);
    int rightClosed = abs(keypad[right][0] - keypad[number][0]) + abs(keypad[right][1] - keypad[number][1]);

    if(leftClosed > rightClosed)  return 1;
    if(leftClosed < rightClosed)  return 0;
    return 2;
}
string solution(vector<int> numbers, string hand)
{
    int closed;
    int left = 10;
    int right = 11;
    string result = "";

    for (auto number : numbers)
    {
        if (number == 1 || number == 4 || number == 7)
        {
            left = number;
            result.push_back('L');
            continue;
        }

        if (number == 3 || number == 6 || number == 9)
        {
            right = number;
            result.push_back('R');
            continue;
        }

        // 2, 5, 8, 0
        closed = func(left, right, number);

        if (closed == 0)
        {
            result.push_back('L');
            left = number;
        }
        if(closed == 1)
        {
            result.push_back('R');
            right = number;
        }
        if(closed == 2)
        {
            if(hand == "right")
            {
                result.push_back('R');
                right = number;
            }
            else
            {
                result.push_back('L');
                left = number;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> input = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};

    cout << solution(input, "left");

    return 0;
}