#include <iostream>
using namespace std;

int T;
int N;
int CACHE[100000][3];
int SCORE[100000][2];

// prev : 0 (위), 1(아래), 2(안고름)
int func(int idx, int prev)
{
    if(idx >= N)  return 0;

    int& ret = CACHE[idx][prev];
    if(ret > -1)  return ret;

    ret = func(idx + 1, 2);
    if(prev == 0 || prev == 2)  ret = max(ret, func(idx + 1, 1) + SCORE[idx][1]);
    if(prev == 1 || prev == 2)  ret = max(ret, func(idx + 1, 0) + SCORE[idx][0]);

    return ret;
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> N;

        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                cin >> SCORE[k][j];

                CACHE[k][0] = -1;
                CACHE[k][1] = -1;
                CACHE[k][2] = -1;
            }
        }

        cout << func(0, 2) << '\n';
    }

    return 0;
}