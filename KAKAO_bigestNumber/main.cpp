#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 두 수를 합치는 순서는 실제로 합쳐서 이득이 되는 순서를 선택하고, 이를 통해 정렬한다.
bool compare(string& a, string& b)
{
    string ab = a + b;
    string ba = b + a;

    if(ab > ba) return true;
    return false;
}
// numbers를 가장 큰 수를 만드는 순서대로 정렬하기
string solution(vector<int> numbers)
{
    string maxNumber = "";
    vector<string> converted;

    for (auto number : numbers)
    {
        converted.push_back(to_string(number));
    }

    sort(converted.begin(), converted.end(), compare);

    for (auto number : converted)
    {
        maxNumber += number;
    }

    // 만약, 0이 여러개 합쳐져 가장 큰 수가 0이 될 때를 처리하기 위한 조건문
    // 0이 여러개가 합쳐지는 경우에는 정렬을 한 후에 가장 앞에 있는 값이 0일 때이다.
    if(converted[0] == "0") maxNumber = "0";
    return maxNumber;
}


// 해결전략
// 모든 수를 가장 큰 수를 만들 때 이득(가장 큰 수를 만드는 것을 의미한다)이 되는 순서대로 정렬한다.
// 그리고 정렬된 순서대로 가장 큰 수를 만든다.

// 정렬
// 두 수를 합쳐본다. 이때, 순서를 바꿔서도 합쳐본다.
// 그리고 합친 두 결과를 비교한다.
// 결과에 따라 정렬한다.
// 만약, AB보다 BA가 더 큰 수라면, B가 A보다 먼저 오는 것이 이득이다.

// 가장 큰 수 만들기
// 정렬된 결과에서 가장 맨 앞에 있는 수는 다른 어떤 수랑 합쳐도 먼저 오는 것이 이득이 되는 수다.
// 따라서, 가장 맨 앞에 있는 수가 가장 큰 수를 만드는데 가장 이득이 되는(가장 큰 수를 만들 수 있는) 수다.
// 정렬된 순서대로 합쳐서 가장 큰 수를 구하면 된다.