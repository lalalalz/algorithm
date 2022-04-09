#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K)
    {
        if (pq.size() == 1)
        {
            answer = -1;
            break;
        }

        int m = pq.top(); pq.pop();
        int n = pq.top(); pq.pop();

        pq.push(m + n * 2);
        answer++;
    }

    return answer;
}