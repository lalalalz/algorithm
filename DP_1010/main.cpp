#include <iostream>
#include <string.h>
using namespace std;

int T;
int N;
int M;
int CACHE[31][31];
int func(int idx, int prev)
{
    int& ret = CACHE[idx][prev];

    if(ret  > -1)  return ret;
    if(idx  >  N)  return 1;

    ret = 0;
    for (int i = prev + 1; i <= M; ++i)
    {
        ret += func(idx + 1, i);
    }

    return ret;
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> N >> M;

        memset(CACHE, -1, sizeof(CACHE));

        cout << func(1, 0) << '\n';
    }

    return 0;
}
