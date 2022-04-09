#include <string>
#include <vector>
using namespace std;

int func(int index, vector<int>& numbers, int number, int target)
{
    int ret = 0;

    if(index == numbers.size())
    {
        return target == number ? 1 : 0;
    }

    ret += func(index + 1, numbers, number + numbers[index], target);
    ret += func(index + 1, numbers, number - numbers[index], target);

    return ret;
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    answer = func(0, numbers, 0, target);

    return answer;
}