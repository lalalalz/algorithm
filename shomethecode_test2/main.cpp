#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


int N;
int A[20001];
int B[20001];
//long long sumOfA[20001];
//long long sumOfB[20001];

bool isSame(int start, int end)
{
    int sumOfA = 0;
    int sumOfB = 0;

    for (int i = start; i <= end; ++i)
    {
        sumOfA += A[i];
    }

    for (int i = start; i <= end; ++i)
    {
        sumOfB += B[i];
    }

    return sumOfA == sumOfB;
}

int main()
{
    int answer = 0;

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        cin >> B[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i; j <= N; ++j)
        {
            if(isSame(i, j)) answer++;
        }
    }

    cout << answer;

    return 0;
}

