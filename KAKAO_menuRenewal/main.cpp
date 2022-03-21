#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int CNT[11];
unordered_map<string, int> MAP;

void func(string str, int idx, string result)
{
    if (result.length() >= 2)
    {
        MAP[result]++;
        CNT[result.length()] = max(CNT[result.length()], MAP[result]);
    }

    for (int i = idx + 1; i < str.length(); ++i)
    {
        func(str, i, result + str[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> courses)
{
    vector<string> answer;

    for (int j = 0; j < orders.size(); ++j)
    {
        sort(orders[j].begin(), orders[j].end());
        func(orders[j], -1, "");
    }

    for (auto course : courses)
    {
        if (CNT[course] <= 1)  continue;
        for (auto e : MAP)
        {
            if (course == e.first.length() && CNT[course] == e.second)
            {
                answer.push_back(e.first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2, 3, 4};

    solution({"ABCD", "ABCD", "ABCD"}, {2,3,4});
    return 0;
}