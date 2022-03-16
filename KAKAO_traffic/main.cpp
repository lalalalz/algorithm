#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<pair<int, int>> convert(vector<string> lines)
{
    int start, end;
    vector<pair<int, int>> result;
    string hour, minutes, seconds, microseconds, process;

    for (auto line : lines)
    {
        hour = line.substr(11, 2);
        minutes = line.substr(14, 2);
        seconds = line.substr(17, 2);
        microseconds = line.substr(20, 3);
        process = line.substr(24);

        end = stoi(hour) * 60 * 60 * 1000 + stoi(minutes) * 60 * 1000 + stoi(seconds) * 1000 + stoi(microseconds);
        start = end - (stod(process.substr(0, process.find("s"))) * 1000 - 1);

        result.push_back(make_pair(start, end));
    }

    return result;
}

int getMax(vector<pair<int, int>> logs)
{
    int pivot;
    int start;
    int count;
    int result = 0;

    for (int i = 0; i < logs.size(); ++i)
    {
        count = 1;
        pivot = logs[i].second + 1000;

        for (int j = i + 1; j < logs.size(); ++j)
        {
            start = logs[j].first;

            if (start < pivot)
            {
                count++;
            }
        }

        result = max(result, count);
    }

    return result;
}

int solution(vector<string> lines)
{
    return getMax(convert(lines));
}

int main()
{
    vector<string> input = {
            "2016-09-15 20:59:57.421 0.351s",
            "2016-09-15 20:59:58.233 1.181s",
            "2016-09-15 20:59:58.299 0.8s",
            "2016-09-15 20:59:58.688 1.041s",
            "2016-09-15 20:59:59.591 1.412s",
            "2016-09-15 21:00:00.464 1.466s",
            "2016-09-15 21:00:00.741 1.581s",
            "2016-09-15 21:00:00.748 2.31s",
            "2016-09-15 21:00:00.966 0.381s",
            "2016-09-15 21:00:02.066 2.62s"
    };


    cout << solution(input);

    return 0;
}