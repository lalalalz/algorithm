#include <string>
#include <iostream>
using namespace std;

string map[10] = {"zero", "one", "two", "three", "four", "five",
              "six", "seven", "eight", "nine"};

int solution(string str)
{
    for (int i = 0; i < 10; ++i)
    {
        cout << map[i] << ' ' << str.find(map[i]) << endl;

        while(str.find(map[i]) != string::npos)
        {
            str.replace(str.find(map[i]), map[i].length(), to_string(i));
        }
    }

    return stoi(str);
}

int main()
{

    cout << solution("23four5six7");

    return 0;
}