#include <iostream>
using namespace std;


int K;
int N;
int COIN[101];
int CACHE[10001];

int main()
{
    cin >> N >> K;

    for (int i = 0; i < N ; ++i)
    {
        cin >> COIN[i];
    }

    CACHE[0] = 1;
    for (int i = 0; i < N; ++i)
    {
        for(int k = 0; k <= K; ++k)
        {
            if(k - COIN[i] >= 0)
            {
                CACHE[k] += CACHE[k - COIN[i]];
            }
        }
    }

    cout << CACHE[K];

    return 0;
}