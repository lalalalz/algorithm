#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int CACHE[1001][1001];
int arr[1001];
  
// idx ~ N 크기 수열의 부분수열 중 가장 길이가 긴 증가 부분수열
int func(int idx, int prev) 
{
    int& ret = CACHE[idx][prev];

    if(idx == N)  return 0;
    if(ret > -1)  return ret;

    // 현재 값을 선택하지 않고, 진행
    ret = func(idx + 1, prev);
    // 현재 값을 선택하여 진행
    if(prev < arr[idx])
    {
        ret = max(ret, func(idx + 1, arr[idx]) + 1);
    }

    return ret;
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    memset(CACHE, -1, sizeof(CACHE));

    cout << func(0, 0);

    return 0;
}
