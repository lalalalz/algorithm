#include <string>
#include <algorithm>
using namespace std;

string arr[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8",
                  "9", "A", "B", "C", "D", "E", "F" };
string convert(int number, int n)
{
    string output = "";

    if(number == 0) return "0";

    while(number > 0)
    {
        output += arr[number % n];
        number /= n;
    }

    reverse(output.begin(), output.end());
    return output;
}
string solution(int n, int t, int m, int p)
{
    int number = 0;
    string answer = "";
    string convertedNumber = "";

    while(answer.size() < t)
    {
        while(convertedNumber.length() < m)
        {
            convertedNumber += convert(number++, n);
        }

        answer += convertedNumber.substr(p - 1, 1);
        convertedNumber = convertedNumber.substr(m);
    }

    return answer;
}