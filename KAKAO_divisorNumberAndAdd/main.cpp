#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for(int i = left; i <= right; ++i)
    {
        double j = sqrt((double)i);

        if(j - (int)j == 0)  answer += i;
        else                 answer -= i;
    }

    return answer;
}