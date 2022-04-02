#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    if(cacheSize == 0)  return cities.size() * 5;

    deque<string> cache;
    deque<string>::iterator it;

    for (auto& city : cities)
    {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        it = find(cache.begin(), cache.end(), city);

        // miss
        if (it == cache.end())
        {
            if(cache.size() >= cacheSize)  cache.pop_front();
            answer += 5;
        }

        // hit
        else
        {
            cache.erase(it);
            answer += 1;
        }

        cache.push_back(city);
    }

    return answer;
}

int main()
{
    solution(3, {"Jeju", "Pangyo", "NewYork", "newyork"});

    return 0;
}