// 짝지어 제거하기
#include <string>
#include <stack>
using namespace std;

int solution(string str)
{
    stack<char> s;

    for (auto c : str)
    {
        if(s.size() > 0 && s.top() == c) s.pop();
        else                             s.push(c);
    }

    return s.empty() ? 1 : 0;
}
