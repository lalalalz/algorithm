#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> days;
    vector<int> answer;

    for (int i = 0; i < progresses.size(); ++i)
    {
        int remainingTask = 100 - progresses[i];
        int day = remainingTask / speeds[i];

        if(remainingTask % speeds[i] > 0)  day++;
        days.push_back(day);
    }

    while(!days.empty())
    {
        int count = 0;
        int finished = days.front();

        for (int i = 0; i < days.size(); ++i)
        {
            if(days[i] > finished)  break;
            days.erase(days.begin() + i);
            count++;
            i--;
        }

        answer.push_back(count);
    }

    return answer;
}