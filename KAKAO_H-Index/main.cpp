#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end());

    for (int h = 0; h <= *max_element(citations.begin(), citations.end()); ++h)
    {
        vector<int>::iterator lower = lower_bound(citations.begin(), citations.end(), h);

        if (citations.end() - lower >= h)
        {
            answer = max(h, answer);
        }
    }

    return answer;
}