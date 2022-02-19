#include <iostream>
#include <string.h>
using namespace std;

int T;
int N;
int CACHE[11];

// N을 1, 2, 3의 합으로 나타낼 수 있는 경우의 수
// 중복 O
int func(int n)
{
    if(n  <  0)  return 0;
    if(n  == 0)  return 1;

    int& ret = CACHE[n];
    if(ret > 0)  return ret;

    for (int i = 1; i <= 3; ++i)
    {
        ret += func(n - i);
    }

    return ret;
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> N;

        memset(CACHE, 0, sizeof(CACHE));

        cout << func(N) << '\n';
    }

    return 0;
}