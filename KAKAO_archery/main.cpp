#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 11

int maxDiff;
vector<int> answer(11);
vector<int> ryonScores(11);
vector<int> peachScores;

bool isBetter()
{
    for (int i = 10; i >= 0; --i)
    {
        if(ryonScores[i] < answer[i])  return false;
        if(ryonScores[i] > answer[i])  return true;
    }
}

void check()
{
    int diff;
    int ryon = 0;
    int peach = 0;

    for (int i = 0; i < MAX; ++i)
    {
        if(ryonScores[i] >  peachScores[i])  ryon += 10 - i;
        else if(peachScores[i] > 0)          peach += 10 - i;
    }

    diff = ryon - peach;

    if (diff > 0 && diff >= maxDiff)
    {
        if (diff == maxDiff && !isBetter())  return;

        maxDiff = diff;
        for (int i = 0; i < MAX; ++i)
        {
            answer[i] = ryonScores[i];
        }
    }
}
void func(int idx, int n)
{
    if(n == 0)
    {
        check();
        return;
    }
    if(idx >= MAX)  return;


    for (int i = 0; i <= n; ++i)
    {
        ryonScores[idx] = i;
        func(idx + 1, n - i);
        ryonScores[idx] = 0;
    }
}

vector<int> solution(int n, vector<int> info)
{
    peachScores = info;

    func(0, n);

    if(info[0] == n || maxDiff == 0)
    {
        return vector<int> {-1};
    }

    return answer;
}

int main()
{
    vector<int> input = {
            0,0,0,0,0,0,0,0,3,4,3
    };

    solution(10, input);

    return 0;
}