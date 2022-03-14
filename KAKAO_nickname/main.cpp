#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record)
{
    map<string, string> m;
    vector<string> outputs;

    for (int i = 0; i < record.size(); ++i)
    {
        stringstream ss(record[i]);
        string action;
        string uid;
        string nickname;

        ss >> action;

        if (action == "Enter")
        {
            ss >> uid >> nickname;
            m[uid] = nickname;
        }
        if (action == "Change")
        {
            ss >> uid >> nickname;
            m[uid] = nickname;
        }
    }

    for (int i = 0; i < record.size(); ++i)
    {
        stringstream ss(record[i]);
        string action;
        string uid;
        string nickname;

        ss >> action >> uid;

        if (action == "Enter")
        {
            nickname = m[uid];
            outputs.push_back(nickname + "님이 들어왔습니다.");
        }
        if (action == "Leave")
        {
            nickname = m[uid];
            outputs.push_back(nickname + "님이 나갔습니다.");
        }
    }

    return outputs;
}

int main()
{
    vector<string> recode = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo",
                             "Change uid4567 Ryan"};

    solution(recode);

    return 0;
}