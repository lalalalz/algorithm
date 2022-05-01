#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// 시작점 0, 0   출발점 5, 5
bool visited[11][11][11][11];
unordered_map<char, int> d;
int direction[4][2] = {{-1, 0},
                 {1,  0},
                 {0,  1},
                 {0,  -1}};

int solution(string dirs)
{
    int nowx   = 5;
    int nowy   = 5;
    int answer = 0;

    d['U'] = 0; d['D'] = 1;
    d['R'] = 2; d['L'] = 3;

    for (auto dir : dirs)
    {
        int nexty = nowy + direction[d[dir]][0];
        int nextx = nowx + direction[d[dir]][1];

        if (nexty <= 10 && nextx <= 10 && nexty >= 0 && nextx >= 0)
        {
            if(!visited[nowy][nowx][nexty][nextx])
            {
                answer++;
                visited[nowy][nowx][nexty][nextx] = true;
                visited[nexty][nextx][nowy][nowx] = true;
            }

            nowy = nexty;
            nowx = nextx;
        }
    }

    return answer;
}