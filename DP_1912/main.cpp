#include <iostream>
#include <algorithm>
using namespace std;

#define MIN -1000 * 100001

int N;
int CACHE[100001];
int arr[100000];

// idx에서 시작하여 연속된 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 반환
int func(int idx)
{
    int& ret = CACHE[idx];

    if(ret > MIN)  return ret;
    if(idx ==  N)  return 0;
    
    return ret = max(func(idx + 1) + arr[idx], arr[idx]);
}

int main()
{
    int ret = MIN;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        CACHE[i] = MIN;
    }

    func(0);

    // 시작점 N개 중에서 시작하는 최대합 중 가장 최대값을 구함
    for (int i = 0; i < N; ++i)
    {
        ret = max(ret, CACHE[i]);
    }

    cout << ret;

    return 0;
}