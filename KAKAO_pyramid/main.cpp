#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> revenue;
unordered_map<string, string> parent;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    int insentive;
    string child;
    vector<int> answer;

    // 부모 및 수익 초기화하기
    for (int i = 0; i < referral.size(); ++i)
    {
        parent[enroll[i]] = referral[i];
        revenue[enroll[i]] = 0;
    }

    // 다단계 처리하기
    for (int i = 0; i < seller.size(); ++i)
    {
        child = seller[i];
        insentive = amount[i] * 100;
        revenue[child] += amount[i] * 100;

        while(child != "-")
        {
            insentive = insentive * 0.1;
            if(insentive < 1)  break;

            revenue[child] -= insentive;
            revenue[parent[child]] += insentive;
            child = parent[child];
        }
    }

    for (auto name : enroll)
    {
        answer.push_back(revenue[name]);
    }

    return answer;
}