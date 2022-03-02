#include <iostream>
#include <algorithm>
using namespace std;

#define MIN -300 * 10001

int N;
int floor[301];
int CACHE[301][3];
int func(int idx, int acc)
{
    if(idx >  N)  return MIN;
    if(acc >  2)  return MIN;
    if(idx == N)  return floor[idx];

    int& ret = CACHE[idx][acc];
    if(ret >  0)  return ret;

    return ret = max(func(idx + 1, acc + 1),
                     func(idx + 2, 1)) + floor[idx];
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> floor[i];
    }

    cout << func(0, 0);

    return 0;
}