#include <string>
#include <algorithm>
using namespace std;

// k 진수로 변환
string convert(int n, int k)
{
    int q = n;
    string output;

    while(q > 0)
    {
        output.push_back('0' + q % k);
        q = q / k;
    }

    reverse(output.begin(), output.end());
    return output;
}

bool isPrimeNumber(string number, int start, int end)
{
    long long target = stoll(number.substr(start, end - start + 1));

    if(target <= 1)  return false;

    for (long long i = 2; i * i <= target; ++i)
    {
        if(target % i == 0)  return false;
    }

    return true;
}


int solution(int n, int k)
{
    int prev = 0;
    int result = 0;
    string number = convert(n, k);

    number.push_back('0');
    for (int now = 0; now < number.size(); ++now)
    {
        if(number[now] != '0')  continue;
        if(isPrimeNumber(number, prev, now - 1))  result++;
        prev = now;
    }

    return result;
}