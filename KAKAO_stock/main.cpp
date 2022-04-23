#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size(), 0);
    stack<int> s;

    for (int i = 0; i < prices.size() - 1; ++i)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty())
    {
        prices[s.top()] = prices.size() - s.top() - 1;
        s.pop();
    }

    return answer;
}
