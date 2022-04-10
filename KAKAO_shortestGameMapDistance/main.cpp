// 게임 맵 최단거리
#include <queue>
#include <vector>
using namespace std;

int dir[4][2] = {{0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int height = maps.size();
    int width  = maps[0].size();

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();

        if(nowy == height - 1 && nowx == width - 1) break;

        for (int i = 0; i < 4; ++i)
        {
            int nexty = nowy + dir[i][0];
            int nextx = nowx + dir[i][1];

            if (nexty >= 0 && nextx >= 0 && nexty < height
            && nextx < width && maps[nexty][nextx] == 1)
            {
                q.push(make_pair(nexty, nextx));
                maps[nexty][nextx] = maps[nowy][nowx] + 1;
            }
        }
    }

    if(maps[height - 1][width - 1] == 1) answer = -1;
    else                                 answer = maps[height - 1][width - 1];

    return answer;
}
