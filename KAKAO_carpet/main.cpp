#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    int i, j;
    vector<int> answer;

    // 세로, 가로
    for (i = 1; i * i<= yellow; ++i)
    {
        if(yellow % i != 0)  continue;

        j = yellow / i;
        if ((j + 2) * (i + 2) - yellow == brown)
        {
            answer.push_back(j + 2);
            answer.push_back(i + 2);
            break;
        }
    }

    return answer;
}