#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> counts;
map<string, vector<pair<int, int>>> lists;
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first == b.first)  return a.second < b.second;
    return a.first > b.first;
}
bool compare_counts(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    for (int i = 0; i < genres.size(); ++i)
    {
        counts[genres[i]] += plays[i];
        lists[genres[i]].push_back(make_pair(plays[i], i));
    }

    for (auto &genre: lists)
    {
        vector<pair<int, int>> &list = genre.second;
        sort(list.begin(), list.end(), compare);
    }

    vector<pair<string, int>> vec(counts.begin(), counts.end());
    sort(vec.begin(), vec.end(), compare_counts);

    for (auto &genre: vec)
    {
        answer.push_back(lists[genre.first][0].second);
        if(lists[genre.first].size() > 1) answer.push_back(lists[genre.first][1].second);
    }

    return answer;
}
int main()
{

    solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500});
    return 0;
}