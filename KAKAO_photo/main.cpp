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

        cout << A << " " << B << " : " << m[A] << " " << m[B] << endl;

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