// 배달
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500000 * 2000

vector<int> cache;
vector<pair<int, int>> dist[51];

void dijkstra()
{
    queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));
    cache[1] = 0;

    while (!pq.empty())
    {
        int now  =  pq.front().second;
        int cost = -pq.front().first;
        pq.pop();

        for (int i = 0; i < dist[now].size(); ++i)
        {
            int next     = dist[now][i].first;
            int distance = dist[now][i].second;

            if (cache[next] > cost + distance)
            {
                cache[next] = cost + distance;
                pq.push(make_pair(-cache[next], next));
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K)
{
    cache.resize(N + 1, MAX);
    for (auto r : road)
    {
        int from     = r[0];
        int to       = r[1];
        int distance = r[2];

        dist[from].push_back(make_pair(to, distance));
        dist[to].push_back(make_pair(from, distance));
    }

    dijkstra();

    int answer = 0;
    for (auto c : cache)
    {
        if(c > K) continue;
        answer++;
    }

    return answer;
}