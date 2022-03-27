#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int map[101][101];
//int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//
//int rotation(int y1, int x1, int y2, int x2)
//{
//    int nowy;
//    int nowx;
//    int idx = 0;
//    int output;
//    vector<int> temp;
//    int size[4] = { x2 - x1, y2 - y1, x2 - x1, y2 - y1};
//
//    nowy = y1;
//    nowx = x1;
//    output = map[y1][x1];
//    temp.push_back(map[y1 + 1][x1]);
//    for (int i = 0; i < 4; ++i)
//    {
//        for (int j = 0; j < size[i]; ++j)
//        {
//            output = min(output, map[nowy][nowx]);
//            temp.push_back(map[nowy][nowx]);
//            nowy += dir[i][0];
//            nowx += dir[i][1];
//        }
//    }
//
//    nowy = y1;
//    nowx = x1;
//    for (int i = 0; i < 4; ++i)
//    {
//        for (int j = 0; j < size[i]; ++j)
//        {
//            map[nowy][nowx] = temp[idx++];
//            nowy += dir[i][0];
//            nowx += dir[i][1];
//        }
//    }
//
//    return output;
//}
//
//
//
//vector<int> solution(int rows, int columns, vector<vector<int>> queries)
//{
//    int number = 1;
//    vector<int> answer;
//
//    for (int i = 0; i < rows; ++i)
//    {
//        for (int j = 0; j < columns; ++j)
//        {
//            map[i][j] = number++;
//        }
//    }
//
//    for (auto query : queries)
//    {
//        answer.push_back(rotation(query[0] - 1, query[1] - 1, query[2] - 1, query[3] - 1));
//    }
//
//    return answer;
//}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    int temp;
    int minVal;
    int number = 1;
    vector<int> answer;

    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= columns; ++j)
        {
            map[i][j] = number++;
        }
    }

for (auto query : queries)
{
    temp = map[query[0]][query[1]];
    minVal = temp;

    for (int i = query[0]; i < query[2]; ++i)
    {
        minVal = min(minVal, map[i + 1][query[1]]);
        map[i][query[1]] = map[i + 1][query[1]];
    }

    for (int i = query[1]; i < query[3]; ++i)
    {
        minVal = min(minVal, map[query[2]][i + 1]);
        map[query[2]][i] = map[query[2]][i + 1];
    }

    for (int i = query[2]; i > query[0]; --i)
    {
        minVal = min(minVal, map[i - 1][query[3]]);
        map[i][query[3]] = map[i - 1][query[3]];
    }

    for (int i = query[3]; i < query[1]; --i)
    {
        minVal = min(minVal, map[query[0]][i - 1]);
        map[query[0]][i] = map[query[0]][i - 1];
    }

    map[query[0]][query[1] + 1] = temp;
    answer.push_back(minVal);
}

    return answer;
}

int main()
{
    solution(6, 6, {{2, 2, 5, 4},
                    {3, 3, 6, 6},
                    {5, 1, 6, 3}});


    return 0;
}