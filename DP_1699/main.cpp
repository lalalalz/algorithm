#include <iostream>
using namespace std;

#define MAX 100000

int N;
int CACHE[100001]; // 0.1 M * 8 B = 0.8MB
int func(int n)
{
    if(n   <   0)  return MAX;
    if(n   ==  0)  return 0;

    int& ret = CACHE[n];
    if(ret < MAX)  return ret;

    for (int i = 1; i * i <= n; ++i)
    {
        ret = min(ret, func(n - i * i) + 1);
    }

    return ret;
}

int main()
{
    cin >> N;

    for (int i = 0; i <= N; ++i)
    {
        CACHE[i] = MAX;
    }

    cout << func(N);

    return 0;
}