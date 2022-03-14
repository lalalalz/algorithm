#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isCorrectString(string str)
{
    stack<char> stack;

    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i] == '(')         stack.push(str[i]);
        else if(!stack.empty())   stack.pop();
        else                      return false;
    }

    return true;
}

vector<string> getBalancedString(string str)
{
    int pos   = 0;
    int left  = 0;
    int right = 0;
    vector<string> result;

    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i] == '(')  left++;
        if(str[i] == ')')  right++;
        if(left == right)
        {
            pos = i;
            break;
        }
    }

    result.push_back(str.substr(0, pos + 1));
    result.push_back(str.substr(pos + 1));

    return result;
}

string solution(string w)
{
    if(w == "")  return w;

    vector<string> balancedStrings = getBalancedString(w);
    string newString;

    if(!isCorrectString(balancedStrings.front()))
    {
        newString.push_back('(');
        newString += solution(balancedStrings.back());
        newString.push_back(')');

        for (int i = 1; i < balancedStrings.front().length() - 1; ++i)
        {
            if(balancedStrings.front()[i] == '(')  newString += ')';
            else                                   newString += '(';
        }
    }
    else
    {
        newString = balancedStrings.front() + solution(balancedStrings.back());
    }

    return newString;
}

int main()
{

    cout << solution("()))((()");

    return 0;
}