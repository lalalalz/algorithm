#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M;
int K;
int cnt;
int CACHE[101][101];

int func(int n, int m)
{
    if(n == 0 && m == 0)  return 1;
    if(n <  0 || m <  0)  return 0;

    int& ret = CACHE[n][m];
    if(ret > 0)  return ret;

    ret += func(n - 1, m);
    ret = min(ret, 1000000000);
    ret += func(n, m - 1);
    ret = min(ret, 1000000000);

    return ret;
}


void makeString(int n, int m, string str)
{
    if(K       <      0)  return;
    if(n == 0 && m == 0)
    {
        K--;
        if(K == 0)  cout << str;
        return;
    }

    // 문자열이 포함되어 있는 경우
    if(func(n, m) >= K)
    {
        if(n > 0)  makeString(n - 1, m, str + "a");
        if(m > 0)  makeString(n, m - 1, str + "z");
    }

    // 문자열이 포함되어 있지 않은 경우
    else
    {
        K -= func(n, m);
    }
}
int main()
{

    cin >> N >> M >> K;

    if(func(N, M) < K)
    {
        cout << -1;
    }

    else
    {
        makeString(N, M, "");
    }

    return 0;
}