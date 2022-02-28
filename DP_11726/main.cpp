#include <iostream>
using namespace std;

#define L 10007

int N;
int CACHE[1001];
// 2 * n 직사각형을 2 * 1 또는 1 * 2 타일로 채울 수 있는 경우의 수
int func(int n)
{
    if(n  <  0)  return 0;
    if(n  == 0)  return 1;

    int& ret = CACHE[n];
    if(ret > 0)  return ret;

    return ret = (func(n - 1) + func(n - 2)) % L;
}
int main()
{
    cin >> N;

    cout << func(N);

    return 0;
}