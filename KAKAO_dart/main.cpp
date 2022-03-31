#include <string>

using namespace std;

int solution(string dartResult)
{
    int sum = 0;
    int now = 0;

    for(int i = 0; i < dartResult.size(); ++i)
    {
        if(dartResult[i] == '*' && i >= 3)
        {
            dartResult.insert(i - 3, "*");
        }
    }

    dartResult += "0";
    for (int i = 0; i < dartResult.size(); ++i)
    {
        if(dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            sum += now;

            if(dartResult[i + 1] == '0')
            {
                now = 10;
                i++;
            }
            else
            {
                now = dartResult[i] - '0';
            }
        }
        if(dartResult[i] == 'S') now = now;
        if(dartResult[i] == 'D') now = now * now;
        if(dartResult[i] == 'T') now = now * now * now;

        if(dartResult[i] == '*') now = now * 2;
        if(dartResult[i] == '#') now = now * (-1);
    }

    return sum;
}