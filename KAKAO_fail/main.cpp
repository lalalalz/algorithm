#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const pair<double, int>& a, const pair<double, int>& b)
{
    if(a.first ==  b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    int sum = stages.size();
    vector<int> answer;
    vector<int> proceeding(N + 1);
    vector<pair<double, int>> fail;

    for (auto e: stages)
    {
        proceeding[e]++;
    }

    for (int i = 1; i < proceeding.size(); ++i)
    {
        if(sum <= 0)
        {
            fail.push_back(make_pair(0, i));
        }
        else
        {
            fail.push_back(make_pair((double)proceeding[i] / (sum), i));
        }
        sum -= proceeding[i];
    }

    sort(fail.begin(), fail.end(), compare);

    for (auto e : fail)
    {
        answer.push_back(e.second);
    }

    return answer;
}

int main()
{
    solution(5, {2, 1, 2, 6, 2, 4, 3, 3});

    return 0;
}