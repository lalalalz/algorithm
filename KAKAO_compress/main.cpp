#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) 
{
    int idx = 1;
    vector<int> answer;
    map<string, int> dictionary;

    // 사전 초기화
    for (int i = 0; i < 26; ++i)
    {
        char c = 'A' + i;
        dictionary[string(1, c)] = idx++;
    }

    while(msg != "")
    {
        for (int i = msg.size(); i >= 1; --i)
        {
            string subString = msg.substr(0, i);

            if(dictionary[subString] > 0)
            {
                msg.erase(0, i);
                answer.push_back(dictionary[subString]);
                if (msg.size() > 0)  dictionary[subString + msg[0]] = idx++;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    solution("KAKAO");

    return 0;
}