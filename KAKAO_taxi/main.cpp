#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000 * 200 * 100

bool visited[201];
int cache[201][201];
int matrix[201][201];

// x -> y로 가는 최소 요금
int dfs(int now, int dest, int n)
{
    int ret = MAX;

    if(now == dest)  return 0;

    for (int i = 1; i <= n; ++i)
    {
        if(i == now || visited[i] || matrix[now][i] == 0)  continue;
        visited[now] = true;
        ret = min(ret, dfs(i, dest, n) + matrix[now][i]);
        visited[now] = false;
    }

    return ret;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int ans;

    for (auto fare : fares)
    {
        matrix[fare[0]][fare[1]] = fare[2];
        matrix[fare[1]][fare[0]] = fare[2];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if(i == j)  continue;
            cache[i][j] = dfs(i, j, n);
        }
    }

    ans = cache[s][a] + cache[s][b];
    for (int i = 1; i <= n ; ++i)
    {
        if (cache[s][i] < MAX && cache[i][a] < MAX && cache[i][b] < MAX)
        {
            ans = min(ans, cache[s][i] + cache[i][a] + cache[i][b]);
        }
    }

    return ans;
}