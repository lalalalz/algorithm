#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> INFO[4][3][3][3];
unordered_map<string, int> MAP;

void setMAP()
{
    MAP["-"] = 0;
    // language
    MAP["cpp"] = 1;
    MAP["java"] = 2;
    MAP["python"] = 3;
    // job
    MAP["backend"] = 1;
    MAP["frontend"] = 2;
    // career
    MAP["junior"] = 1;
    MAP["senior"] = 2;
    // food
    MAP["chicken"] = 1;
    MAP["pizza"] = 2;
}

void setScore(string info)
{
    // info를 파싱한다.
    int setIndex[4];
    int infoIndex[4];
    string language, job, career, food, score;

    stringstream ss(info);
    ss >> language >> job >> career >> food >> score;

    infoIndex[0] = MAP[language];
    infoIndex[1] = MAP[job];
    infoIndex[2] = MAP[career];
    infoIndex[3] = MAP[food];

    // info를 모든 경우에 대해 점수를 셋팅한다.
    for (int i = 0; i < (1 << 4); ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if(i & (1 << j))
            {
                setIndex[j] = infoIndex[j];
            }
            else
            {
                setIndex[j] = 0;
            }
        }
        INFO[setIndex[0]][setIndex[1]][setIndex[2]][setIndex[3]].push_back(stoi(score));
    }
}

int getNumber(string query)
{
    string language, job, career, food, score, temp;
    stringstream ss(query);

    ss >> language >> temp >> job >> temp >> career >> temp >> food >> score;

    auto& list = INFO[MAP[language]][MAP[job]][MAP[career]][MAP[food]];
    vector<int>::iterator low = lower_bound(list.begin(), list.end(), stoi(score));

    return list.end() - low;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;

    // 맵을 셋팅한다.
    setMAP();
    // 점수를 설정한다.
    for (auto one: info)
    {
        setScore(one);
    }

    // 정렬을 한다.
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                for (int l = 0; l < 3; ++l)
                {
                    sort(INFO[i][j][k][l].begin(), INFO[i][j][k][l].end());
                }
            }
        }
    }

    // 쿼리를 처리한다.
    for (auto one : query)
    {
        answer.push_back(getNumber(one));
    }

    // 결과를 반환한다.
    return answer;
}

int main()
{
    solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"},
             {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});

    return 0;
}