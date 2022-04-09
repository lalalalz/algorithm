//#include <map>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <iostream>
//using namespace std;

//vector<string> solution(vector<string> record)
//{
//    map<string, string> m;
//    vector<string> outputs;
//
//    for (int i = 0; i < record.size(); ++i)
//    {
//        stringstream ss(record[i]);
//        string action;
//        string uid;
//        string nickname;
//
//        ss >> action;
//
//        if (action == "Enter")
//        {
//            ss >> uid >> nickname;
//            m[uid] = nickname;
//        }
//        if (action == "Change")
//        {
//            ss >> uid >> nickname;
//            m[uid] = nickname;
//        }
//    }
//
//    for (int i = 0; i < record.size(); ++i)
//    {
//        stringstream ss(record[i]);
//        string action;
//        string uid;
//        string nickname;
//
//        ss >> action >> uid;
//
//        if (action == "Enter")
//        {
//            nickname = m[uid];
//            outputs.push_back(nickname + "님이 들어왔습니다.");
//        }
//        if (action == "Leave")
//        {
//            nickname = m[uid];
//            outputs.push_back(nickname + "님이 나갔습니다.");
//        }
//    }
//
//    return outputs;
//}

#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> nicknameMap;

vector<string> solution(vector<string> records)
{
    vector<string> answer;

    for(auto record : records)
    {
        string id;
        string action;
        string nickname;
        stringstream ss(record);

        ss >> action >> id >> nickname;

        if(action == "Enter")
        {
            nicknameMap[id] = nickname;
        }

        if(action == "Change")
        {
            nicknameMap[id] = nickname;
        }
    }

    for(auto record : records)
    {
        string id;
        string action;
        string nickname;
        stringstream ss(record);

        ss >> action >> id;

        if(action == "Enter" ) answer.push_back(nicknameMap[id] + "님이 들어왔습니다.");
        if(action == "Leave" ) answer.push_back(nicknameMap[id] + "님이 나갔습니다.");
    }

    return answer;
}

