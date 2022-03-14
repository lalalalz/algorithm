#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int compress(string source, string target, int position)
{
    if(position >= source.length())  return 0;

    if (source.substr(position, target.length()) == target)
    {
        return compress(source, target, position + target.length()) + 1;
    }
    // else
    return 0;
}

int getSize(int number)
{
    int size = 0;

    while (number > 0)
    {
        number = number / 10;
        size++;
    }

    return size;
}
int solution(string str)
{
    int answer = str.length();

    int count;
    int length;
    int position;
    string pivotString;

    for (int i = 1; i <= str.length()/2; ++i)
    {
        length = 0;
        position = 0;
        count = 0;

        while(position < str.length())
        {
            pivotString = str.substr(position, i);
            count  = compress(str, pivotString, position);

            length += pivotString.length();
            if(count > 1)  length += getSize(count);

            position += count * pivotString.length();
        }

        answer = min(answer, length);
    }

    return answer;
}
int main()
{

//    cout << compress("aabbaaacc", "aa", 4);
    cout << solution("xababcdcdababcdcd");

    return 0;
}
