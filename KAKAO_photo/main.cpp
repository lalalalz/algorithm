#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// n이름에 멤버가 있는 idx 위치
unordered_map<char, int> m;
bool visited[8];
char name[8] = {'A', 'C', 'F', 'J',
                'M', 'N', 'R', 'T'};

bool check(vector<string>& data)
{
    for(auto e : data)
    {
        int dis = (e[4] - '0') + 1;
        char A = e[0], B = e[2], oper = e[3];

        if(oper == '=' && abs(m[A] - m[B]) != dis)  return false;
        if(oper == '<' && abs(m[A] - m[B]) >= dis)  return false;
        if(oper == '>' && abs(m[A] - m[B]) <= dis)  return false;
    }

    return true;
}
int func(int idx, vector<string>& data)
{
    int ret = 0;

    if(idx >= 8)  return check(data) ? 1 : 0;

    for(int i = 0; i < 8; ++i)
    {
        if(!visited[i])
        {
            visited[i] = true;
            m[name[i]] = idx;
            ret += func(idx + 1, data);
            m[name[i]] = -1;
            visited[i] = false;
        }
    }

    return ret;
}
int solution(int n, vector<string> data)
{
    return func(0, data);
}
int main()
{
    solution(2, {"N~F=0", "R~T>2"});
    return 0;
}

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char, int> m;
int solution(int n, vector<string> data)
{
    int answer = 0;
    vector<char> positions = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    do
    {
        for (int i = 0; i < positions.size(); ++i)
        {
            m[positions[i]] = i;
        }

        bool isOkay = true;

        for (auto condition : data)
        {
            char A    =  condition[0];
            char B    =  condition[2];
            char oper =  condition[3];
            int  dist = (condition[4] - '0') + 1;

            if(oper == '=' && abs(m[A] - m[B]) == dist)  continue;
            if(oper == '>' && abs(m[A] - m[B]) >  dist)  continue;
            if(oper == '<' && abs(m[A] - m[B]) <  dist)  continue;

            isOkay = false;
            break;
        }

        if(isOkay)  answer++;

    } while (next_permutation(positions.begin(), positions.end()));

    return answer;
}
