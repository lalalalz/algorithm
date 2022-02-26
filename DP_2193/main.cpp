#include <iostream>
using namespace std;

int N;
long long CACHE[91][2];

// 이전 값이 prev 일 때, n자리 이친수의 갯수
long long func(int n, int prev)
{
    long long& ret = CACHE[n][prev];

    // 첫번째 자리의 수는 1 이여야 하므로
    // 1일 땐 1을 0일 땐 0을 반환하기에 prev 값을 그대로 넘겨도 됨 -> 1일 때는 1가지의 이친수를 찾았으므로 1을 반환하는 것
    if(n  == 0)  return prev;
    if(ret > 0)  return ret;

    ret += func(n - 1, 0);
    if(prev == 0)  ret += func(n - 1, 1);

    return ret;
}

int main()
{
    cin >> N;

    cout << func(N, 0);

    return 0;
}