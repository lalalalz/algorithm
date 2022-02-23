#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int MAP[501][501];
int CACHE[501][501];

int func(int y, int x)
{
    int& ret = CACHE[y][x];

    if(ret    >    -1)  return ret;
    if(y > N || x > N)  return 0;

    return ret = max(func(y + 1, x), func(y + 1, x + 1)) + MAP[y][x];
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> MAP[i][j];
        }
    }

    memset(CACHE, -1 , sizeof(CACHE));

    cout << func(1, 1);

    return 0;
}