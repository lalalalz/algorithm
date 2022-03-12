#include <iostream>
#include <string>
using namespace std;

void func(int n, int m, string str)
{
    if (n == 0 && m == 0)
    {
        cout << str << endl;
        return;
    }

    if(n > 0)  func(n - 1, m, str + "a");
    if(m > 0)  func(n, m - 1, str + "b");
}

int main()
{
    func(2, 3, "");

    return 0;
}