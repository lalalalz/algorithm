#include <iostream>
using namespace std;

// 최대 봉지 수
#define MAX 50000

int N;              // 입력 킬로그램
int CACHE[5001];    // 캐시

// 설탕 n킬로그램을 배달하기 위해 필요한 최소 봉지 수
int func(int n)
{
    if(n  <  0)  return MAX;
    if(n  == 0)  return 0;

    int& ret = CACHE[n];
    if(ret > 0)  return ret;

    return ret = min(func(n - 3), func(n - 5)) + 1;
}

int main()
{
    cin >> N;

    if(func(N) >= MAX)  cout << -1;
    else                cout << func(N);

    return 0;
}