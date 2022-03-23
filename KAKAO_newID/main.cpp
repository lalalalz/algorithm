#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id)
{
    for (int i = 0; i < new_id.length(); ++i)
    {
        new_id[i] = tolower(new_id[i]);
    }

    for (int i = 0; i < new_id.length(); ++i)
    {
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
        || new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_')  continue;
        new_id.erase(i, 1);
        i--;
    }


    while(new_id.find("..") != string::npos)
    {
        new_id.replace(new_id.find(".."), 2, ".");
    }

    if(new_id.front() == '.')  new_id.erase(0, 1);
    if(new_id.back() == '.')   new_id.erase(new_id.length() - 1, 1);
    if(new_id == "")           new_id.push_back('a');
    if(new_id.length() >= 16)  new_id = new_id.substr(0, 15);
    if(new_id.front() == '.')  new_id.erase(0, 1);
    if(new_id.back() == '.')   new_id.erase(new_id.length() - 1, 1);

    while(new_id.length() <= 2)
    {
        new_id += new_id.back();
    }

    cout << new_id << endl;

    return new_id;
}

int main()
{
    solution("-.~!@#$%&*()=+[{]}:?,<>/.-");
    solution(".b.");
    solution("a..a");
    solution("/..D.SNA....IDNSAI....N,.,..D1,,...Q21.....41@...@@#$(@_!$($!(#@,...21..");

    return 0;
}