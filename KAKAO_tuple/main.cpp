#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}
vector<int> solution(string s)
{
    vector<int> answer;
    map<string, int> m;
    string number = "";

    for (int i = 0; i < s.size(); ++i)
    {
        if(isdigit(s[i]))
        {
            number += s[i];
        }
        else if(number.size() > 0)
        {
            m[number]++;
            number = "";
        }
    }

    vector<pair<string, int>> converted(m.begin(), m.end());
    sort(converted.begin(), converted.end(), compare);

    for (auto e : converted)
    {
        answer.push_back(stoi(e.first));
    }

    return answer;
}