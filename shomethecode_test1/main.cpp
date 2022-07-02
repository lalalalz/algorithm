#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


int N;
int K;
int SUM;
int monster[21]; // i번째 마을의 괴물을 물리칠 때 필요한 체력
int people[21]; // i번째 마을의 백성의 수
int cache[21][100001];

vector<pair<int, int>> monsterAndPeople;

int getMax(int town, int k)
{
    if(k == 0 || town >= N) return 0;

    int& result = cache[town][k];
    if(result > -1) return result;

    result = getMax(town + 1, k); // town번째 마을 안구함
    if(k - (monsterAndPeople[town].first + SUM) >= 0)
    {
        SUM += monsterAndPeople[town].first;
        result = max(result, getMax(town + 1, k - SUM) + monsterAndPeople[town].second);
        SUM -= monsterAndPeople[town].first;
    }

    return result;
}
int main()
{
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> monster[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> people[i];
    }

    for (int i = 0; i < N; ++i)
    {
        monsterAndPeople.push_back(make_pair(monster[i], people[i]));
    }

    sort(monsterAndPeople.begin(), monsterAndPeople.end());

    memset(cache, -1, sizeof(cache));

    cout << getMax(0, K);

    return 0;
}

