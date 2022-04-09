#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//vector<int> getArray(int startSetNumber, int endSetNumber, int n)
//{
//    int k;
//    int count;
//    vector<int> ary;
//
//    for (int i = startSetNumber; i <= endSetNumber; ++i)
//    {
//        k     = 1;
//        count = 0;
//        for (int j = 0; j < n; ++j)
//        {
//            count++;
//            if(count <= i) ary.push_back(i);
//            else           ary.push_back(i + k++);
//        }
//    }
//
//    return ary;
//}
//
//vector<int> solution(int n, long long left, long long right)
//{
//    // left ~ right가 포함된 배열을 만든다.
//    int startSetNumber = left  / n + 1;
//    int endSetNumber   = right / n + 1;
//    int numberOfLeft   = left  % n;
//    int numberOfRight  = right % n;
//    int setCount       = endSetNumber - startSetNumber;
//
//    vector<int> ary    = getArray(startSetNumber, endSetNumber, n);
//    // 실제 left ~ right 까지의 배열을 추출
//    vector<int> answer = {ary.begin() + numberOfLeft, ary.begin() + setCount * n + numberOfRight + 1};
//
//    return answer;
//}

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;


    // 몫 : index / n;
    // 나머지 : index % n;
    // 한 세트에서 몫의 값이 index 번째 원소의 값이 된다. (몫 >= 나머지)
    // 한 세트에서 나머지의 값이 index 번째 원소의 값이 된다. (몫 < 나머지)
    for(long long i = left; i <= right; ++i)
    {
        // 몫 + 1을 추가한다. (몫 >= 나머지)
        // 나머지 + 1을 추가한다. (몫 < 나머지)
        answer.push_back(max(i / n, i % n) + 1);
    }


    return answer;
}