#include <vector>
#include <algorithm>
using namespace std;

vector<int> first = {1,2,3,4,5};
vector<int> second = {2,1,2,3,2,4,2,5};
vector<int> third = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> scores(3);

    for (int i = 0; i < answers.size(); ++i)
    {
        if(answers[i] == first[i % 5]) scores[0]++;
        if(answers[i] == second[i % 8]) scores[1]++;
        if(answers[i] == third[i % 10]) scores[2]++;
    }

    int maxScore = *max_element(scores.begin(), scores.end());
    for (int i = 0; i < scores.size(); ++i)
    {
        if (maxScore != scores[i])  continue;
        answer.push_back(i + 1);
    }

    return answer;
}