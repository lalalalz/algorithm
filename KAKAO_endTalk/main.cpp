// 끝말잇기
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    string now, prev;
    unordered_map<string, int> isNew;

    answer.push_back(0);
    answer.push_back(0);

    prev = words[0];
    isNew[prev]++;

    for (int i = 1; i < words.size(); ++i)
    {
        now = words[i];

        // 중복 인지, 이어지지 않는 단어인지 확인
        if (isNew[now] > 0 || now.front() != prev.back())
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }

        // 중복 x, 이어지는 단어
        isNew[now]++;
        prev = now;
    }

    return answer;
}