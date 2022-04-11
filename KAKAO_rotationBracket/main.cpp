#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isRight(string str)
{
    stack<char> s;

    for (auto c : str)
    {
        if(c == '{' || c == '(' || c == '[')
        {
            s.push(c);
        }
        else if(!s.empty())
        {
            if(c == '}' && s.top() == '{') s.pop();
            if(c == ')' && s.top() == '(') s.pop();
            if(c == ']' && s.top() == '[') s.pop();
        }
        else
        {
            return false;
        }
    }

    return s.empty();
}
int solution(string s) 
{
    int answer = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        s.push_back(s.front());
        s.erase(s.begin());

        if(isRight(s)) answer++;
    }
    
    return answer;
}