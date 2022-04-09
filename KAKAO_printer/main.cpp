// 프린터
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<int> q;

    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push(i);
    }

    while (true)
    {
        int now = q.front();
        q.pop();

        if(priorities[now] >= *max_element(priorities.begin(), priorities.end()))
        {
            priorities[now] = -1;
            answer++;
            if(now == location)  break;
        }
        else
        {
            q.push(now);
        }
    }

    return answer;
}