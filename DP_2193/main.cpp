#include <iostream>
using namespace std;

int N;
long long CACHE[91][2];

//
long long func(int n, int prev)
{
    long long& ret = CACHE[n][prev];

    if(n  == N)  return 1;
    if(ret > 0)  return ret;

    ret += func(n + 1, 0);
    if(prev == 0)  ret += func(n + 1, 1);

    return ret;
}

int main()
{
    cin >> N;

    cout << func(1, 1);

    return 0;
}