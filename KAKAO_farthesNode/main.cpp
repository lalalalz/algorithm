// 가장 먼 노드
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

int getFarthestDistance(vector<vector<int>> connection)
{
    int result   = 0;
    int farthest = 0;
    int visited[20001];
    queue<pair<int, int>> q;

    memset(visited, -1, sizeof(visited));
    q.push(make_pair(1, 0));
    visited[1] = 0;

    while (!q.empty())
    {
        int cur  = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int i = 0; i < connection[cur].size(); ++i)
        {
            int next = connection[cur][i];

            if(visited[next] < 0)
            {
                visited[next] = dist + 1;
                farthest = max(farthest, visited[next]);
                q.push(make_pair(next, visited[next]));
            }
        }
    }

    for (int i = 1; i <= connection.size(); ++i)
    {
        if(visited[i] == farthest) result++;
    }

    return result;
}
int solution(int n, vector<vector<int>> edge)
{
    int answer;

    vector<vector<int>> connection(n + 1);

    for (auto e : edge)
    {
        int from = e[0];
        int to   = e[1];
        connection[from].push_back(to);
        connection[to].push_back(from);
    }

    answer = getFarthestDistance(connection);

    return answer;
}
int main()
{
    solution(6, {{3, 6},
              {4, 3},
              {3, 2},
              {1, 3},
              {1, 2},
              {2, 4},
              {5, 2}});

    return 0;
}