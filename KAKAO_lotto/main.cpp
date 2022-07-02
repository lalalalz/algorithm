#include <string>
#include <vector>
using namespace std;

vector<int> getCounts(vector<int> lottos, vector<int> win_nums)
{
    int zero = 0;
    int hits = 0;
    vector<int> result;

    for (int i = 0; i < win_nums.size(); ++i)
    {
        if(lottos[i] == 0)  zero++;
        for (int j = 0; j < lottos.size(); ++j)
        {
            if(lottos[j] == win_nums[i])
            {
                hits++;
                break;
            }
        }
    }

    result.push_back(hits);
    result.push_back(zero);
    return result;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    vector<int> counts = getCounts(lottos, win_nums);

    int max = (7 - counts[0] + counts[1]) < 6 ? (7 - counts[0] + counts[1]) : 6;
    int min = (7 - counts[0]  < 6) ? (7 - counts[0]) : 6;

    answer.push_back(max);
    answer.push_back(min);

    return answer;
}

