#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<long long> NUMBER;
vector<char> OPERATOR;
vector<char> ORDER = {'*', '+', '-'};

void init(string expression)
{
    string number = "";

    NUMBER.clear();
    OPERATOR.clear();

    for (int i = 0; i <= expression.size(); ++i)
    {
        if(!isdigit(expression[i]))
        {
            OPERATOR.push_back(expression[i]);
            NUMBER.push_back(stoi(number));
            number = "";
        }

        else
        {
            number += expression[i];
        }
    }
}

void calc()
{
    for (auto oper: ORDER)
    {
        for (int i = 0; i < OPERATOR.size() - 1; ++i)
        {
            if(OPERATOR[i] != oper)  continue;
            if(oper == '+')  NUMBER[i] = NUMBER[i] + NUMBER[i + 1];
            if(oper == '*')  NUMBER[i] = NUMBER[i] * NUMBER[i + 1];
            if(oper == '-')  NUMBER[i] = NUMBER[i] - NUMBER[i + 1];

            OPERATOR.erase(OPERATOR.begin() + i);
            NUMBER.erase(NUMBER.begin() + i + 1);
            i--;
        }
    }
}

long long solution(string expression)
{
    long long answer = 0;

    do {

        init(expression);
        calc();
        answer = max(answer, abs(NUMBER[0]));

    } while(next_permutation(ORDER.begin(), ORDER.end()));

    return answer;
}

int main()
{


    solution("100-200*300-500+20");
}