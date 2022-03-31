#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    int target;
    string resolved;
    vector<string> answer;

    for (int i = 0; i < arr1.size(); ++i)
    {
        resolved = "";
        target = arr1[i] | arr2[i];

        for(int j = 0; j < n; ++j)
        {
            if(target & (1 << j))   resolved = "#" + resolved;
            else                    resolved = " " + resolved;
        }

        answer.push_back(resolved);
    }

    return answer;
}

int main()
{
    cout << (3 | 2);

    return 0;
}