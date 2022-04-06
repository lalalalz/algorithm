#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_set<string> jewel;
unordered_map<string, int> purchase;

vector<int> solution(vector<string> gems)
{
    vector<int> answer(2);
    int min   = 100001;
    int start = 0;
    int end   = 0;

    for (auto j : gems)
    {
        jewel.insert(j);
    }

    while(start < gems.size())
    {
        if(purchase.size() < jewel.size() && end < gems.size())
        {
            purchase[gems[end]]++;
            end++;
            continue;
        }

        if(purchase.size() == jewel.size() && min > end - start)
        {
            min = end - start;
            answer[0] = start + 1;
            answer[1] = end;
        }

        purchase[gems[start]]--;
        if(purchase[gems[start]] == 0)
        {
            purchase.erase(gems[start]);
        }
        start++;
    }

    return answer;
}
int main()
{
    solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
    return 0;
}