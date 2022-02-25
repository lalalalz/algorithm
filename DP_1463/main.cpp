#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000001 * 8;

int N;
int CACHE[1000001]; // 8 * 1,000,000 = 8MB

// x를 1로 만들기 위해 필요한 최소 횟수
int func(int x)
{
    int& ret = CACHE[x];

    if (x <   1)  return MAX;
    if (x ==  1)  return 0;
    if (ret > 0)  return ret;

    ret = MAX;
    if (x % 3 >  0 ||
        x % 2  > 0)  ret = min(ret, func(x - 1) + 1);
    if (x % 3 == 0)  ret = min(ret, func(x / 3) + 1);
    if (x % 2 == 0)  ret = min(ret, func(x / 2) + 1);

    return ret;
}


int main()
{
    cin >> N;

    cout << func(N);

    return 0;
}