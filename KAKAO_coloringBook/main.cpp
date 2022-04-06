#include <queue>
#include <vector>
using namespace std;

int dir[4][2] = {{0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};

int bfs(int i, int j, int color, vector<vector<int>>& picture)
{
    int sum    = 0;
    int width  = picture.size();
    int height = picture.size();
    queue<pair<int, int>> q;

    q.push(make_pair(i, j));
    picture[i][j] = 0;
    sum++;

    while (!q.empty())
    {
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int nexty = nowy + dir[k][0];
            int nextx = nowx + dir[k][1];

            if (nexty >= 0 && nextx >= 0 && nexty < height && nextx < width && picture[nexty][nextx] == color)
            {
                q.push(make_pair(nexty, nextx));
                picture[nexty][nextx] = 0;
                sum++;
            }
        }
    }

    return sum;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    int colors = 0;
    int max = 0;
    vector<int> answer;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int color = picture[i][j];
            if (color == 0)  continue;

            colors++;
            int count = bfs(i, j, color, picture);
            if(max < count)  max = count;
        }
    }

    answer.push_back(colors);
    answer.push_back(max);

    return answer;
}
int main()
{

    solution(6, 4, {{1, 1, 1, 0},
              {1, 2, 2, 0},
              {1, 0, 0, 1},
              {0, 0, 0, 1},
              {0, 0, 0, 3},
              {0, 0, 0, 3}});
}