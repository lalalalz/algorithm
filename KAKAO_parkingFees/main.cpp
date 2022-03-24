#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<string, vector<int>[2]> MAP;

int convert(string time)
{
    string hour = time.substr(0, 2);
    string minute = time.substr(3, 2);
ㄹ
    return stoi(hour) * 60 + stoi(minute);
}
vector<int> solution(vector<int> fees, vector<string> records) {

    int time;
    int fee;
    vector<int> answer;

    for (auto record: records)
    {
        string time, car, type;
        stringstream ss(record);

        ss >> time >> car >> type;

        if(type == "IN") MAP[car][0].push_back(convert(time));
        else             MAP[car][1].push_back(convert(time));
    }

    for (auto& record: MAP)
    {
        fee = 0;
        time = 0;

        for (int i = 0; i < record.second[0].size(); ++i)
        {
            if(record.second[1].size() <= i)  time += convert("23:59") - record.second[0][i];
            else                              time += record.second[1][i] - record.second[0][i];
        }

        if(time >= fees[0])  fee = fees[1] + ceil((double)(time - fees[0]) / fees[2]) * fees[3];
        else                 fee = fees[1];

        answer.push_back(fee);
    }

    return answer;
}

int main()
{
    vector<int> fees = {120, 0, 60, 591};
    vector<string> records = {"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"};

    solution(fees, records);
    return 0;
}