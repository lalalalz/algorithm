#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<string, int> A;
unordered_map<string, int> B;
unordered_set<string> C;

void set(string str, unordered_map<string, int>& target)
{
    string temp;
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (int i = 0; i < str.size() - 1; ++i)
    {
        temp = str.substr(i, 2);
        if(isalpha(temp[0]) && isalpha(temp[1]))
        {
            target[temp]++;
            C.insert(temp);
        }
    }
}

int solution(string str1, string str2)
{
    int i = 0;
    int u = 0;
    int answer;

    set(str1, A);
    set(str2, B);

    for (auto &e: C)
    {
        i += min(A[e], B[e]);
        u += max(A[e], B[e]);
    }

    if(u == 0)  answer = 65536;
    else        answer = ((double)i / u) * 65536;

    return answer;
}

int main()
{
    solution("E=M*C^2", "e=m*c^2");

    return 0;
}