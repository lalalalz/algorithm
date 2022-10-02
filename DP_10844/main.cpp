#include <iostream>
using namespace std;

#define L 1000000000

int N;
int CACHE[102][10];
int func(int n, int prev)
{
    int& ret = CACHE[n][prev];

    if(n  == N)  return 1;
    if(ret > 0)  return ret;

    if(prev + 1 <= 9)  ret = (ret + func(n + 1, prev + 1)) % L;
    if(prev - 1 >= 0)  ret = (ret + func(n + 1, prev - 1)) % L;

    
    
    return ret;
}

int main()
{
    int sum = 0;

    cin >> N;

    for(int i = 1; i < 10; ++i)
    {
        sum = (sum + func(1, i)) % L;
    }

    cout << sum;

    return 0;
}
