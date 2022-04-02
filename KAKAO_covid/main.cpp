#include <string>
#include <vector>
using namespace std;

bool isConnected(int i, int j, vector<string> map)
{
    int nextY, nextX;
    int dir[8][2] = {{0,  1},
                     {1,  0},
                     {0,  -1},
                     {-1, 0},
                     {-1, -1},
                     {-1, 1},
                     {1,  -1},
                     {1,  1}};

    for (int k = 0; k < 8; ++k)
    {
        nextY = i + dir[k][0];
        nextX = j + dir[k][1];

        if(nextX >= 0 && nextY >= 0 && nextX < 5
        && nextY < 5 && map[nextY][nextX] == 'P')  return true;
    }

    return false;
}
bool isOkay(vector<pair<int, int>> person, vector<string> map)
{
    for (int i = 0; i < person.size(); ++i)
    {
        if(isConnected(person[i].first, person[i].second, map))  return false;
    }
    return true;
}
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (auto place : places)
    {
        vector<pair<int, int>> person;

        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if(place[i][j] == 'P') person.push_back(make_pair(i, j));
            }
        }

        if(isOkay(person, place)) answer.push_back(1);
        else{                       answer.push_back(0);}
    }

    return answer;
}