#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time  = 1;
    int index = 0;
    int totalCount  = 0;
    int totalWeight = 0;

    queue<pair<int, int>> q;
    q.push(make_pair(truck_weights[index], bridge_length));
    totalCount  += 1;
    totalWeight += truck_weights[index++];

    while (!q.empty())
    {
        if (q.front().second == time)
        {
            totalCount  -= 1;
            totalWeight -= q.front().first;
            q.pop();
        }

        if (index + 1 <= truck_weights.size()
        && totalWeight + truck_weights[index] <= weight
        && totalCount + 1 <= bridge_length)
        {
            q.push(make_pair(truck_weights[index], bridge_length + time));
            totalCount  += 1;
            totalWeight += truck_weights[index++];
        }

        time++;
    }

    return time;
}