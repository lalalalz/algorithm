#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> INFO[4][3][3][3];

int convert(string str)
{
    if(str == "-")        return 0;
    if(str == "cpp")      return 1;
    if(str == "java")     return 2;
    if(str == "python")   return 3;
    if(str == "backend")  return 1;
    if(str == "frontend") return 2;
    if(str == "junior")   return 1;
    if(str == "senior")   return 2;
    if(str == "chicken")  return 1;
    if(str == "pizza")    return 2;
}

void setScore(int i, int j, int k, int l, int score)
{
    INFO[i][j][k][l].push_back(score);

    cout << i << j << k << l << endl;

    if(i == 0 && j == 0 && k == 0 && l == 0)  return;

    for (int m = 0; m < 4; ++m)
    {
        if(m == 0 && i != 0) setScore(0, j, k, l, score);
        if(m == 1 && j != 0) setScore(i, 0, k, l, score);
        if(m == 2 && k != 0) setScore(i, j, 0, l, score);
        if(m == 3 && l != 0) setScore(i, j, k, 0, score);
    }
}
vector<int> solution(vector<string> info, vector<string> query)
{
    string 언어;
    string 직군;
    string 경력;
    string 소울푸드;
    string 점수;
    string 그리고;
    int count;
    vector<int> answer;

    for (string i : info)
    {
        stringstream ss(i);
        ss >> 언어 >> 직군 >> 경력 >> 소울푸드 >> 점수;
        setScore(convert(언어),convert(직군),convert(경력),convert(소울푸드), stoi(점수));
    }

    for (auto q: query)
    {
        stringstream ss(q);
        ss >> 언어 >> 그리고 >> 직군 >> 그리고 >> 경력 >> 그리고 >> 소울푸드 >> 점수;
        count = 0;

        for (int i = 0; i < INFO[convert(언어)][convert(직군)][convert(경력)][convert(소울푸드)].size(); ++i)
        {
            if (INFO[convert(언어)][convert(직군)][convert(경력)][convert(소울푸드)][i] >= stoi(점수))
            {

                cout << INFO[convert(언어)][convert(직군)][convert(경력)][convert(소울푸드)][i] << ":" << stoi(점수) << endl;
                count++;
            }
        }
        cout << count << endl;

        answer.push_back(count);
    }

    return answer;
}

int main()
{
    solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"},
             {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});

    return 0;
}