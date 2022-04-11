// 후보키
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool hasMinimal(vector<int> candidate, int n)
{
    for (int i = 0; i < candidate.size(); ++i)
    {
        if ((candidate[i] & n) == candidate[i]) return false;
    }

    return true;
}
int solution(vector<vector<string>> relations)
{
    vector<int> candidate;

    for (int i = 1; i < (1 << relations[0].size()); ++i)
    {
        unordered_set<string> s;

        for (int j = 0; j < relations.size(); ++j)
        {
            string key = "";

            for (int k = 0; k < relations[0].size(); ++k)
            {
                if(i & (1 << k))
                {
                    key += relations[j][k];
                    key += " ";
                }
            }

            s.insert(key);
        }

        if (s.size() == relations.size() && hasMinimal(candidate, i))
        {
            candidate.push_back(i);
        }
    }

    return candidate.size();
}
