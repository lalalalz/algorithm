#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000 * 1001

int N;
int COST[1000][4];
int CACHE[1000][4];

// 현재 idx 색칠해야하고, 이전 집의 색이 prevColor일 때, N - idx개의 집을 색칠할 수 있는 최소 비용
int func(int idx, int prevColor)
{
    if(idx == N)  return 0;

    int& ret = CACHE[idx][prevColor];
    if(ret != MAX)  return ret;

    for (int i = 1; i <= 3; ++i)
    {
        if(i == prevColor)  continue;
        ret = min(ret, func(idx + 1, i) + COST[idx][i]);
    }

    return ret;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> COST[i][1] >> COST[i][2] >> COST[i][3];

        CACHE[i][0] = MAX;
        CACHE[i][1] = MAX;
        CACHE[i][2] = MAX;
        CACHE[i][3] = MAX;
    }

    cout << func(0, 0);

    return 0;
}