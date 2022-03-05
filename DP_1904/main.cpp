#include <iostream>
using namespace std;

#define L 15764

int N;
int CACHE[1000001]; // 8 * 1M = 8MB

int func()
{
    CACHE[1] = 1;
    CACHE[2] = 2;

    for (int i = 3; i <= N; ++i)
    {
        CACHE[i] = (CACHE[i - 1] + CACHE[i - 2]) % L;
    }

    return CACHE[N];
}
int main()
{
    cin >> N;

    cout << func();

    return 0;
}