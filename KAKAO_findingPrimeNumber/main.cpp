#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

set<int> primeNumbers;
bool visited[10];
bool isPrime(int number)
{
    if(number <= 1)  return false;

    for (int i = 2; i * i <= number ; ++i)
    {
        if(number % i == 0)  return false;
    }

    return true;
}

void func(int idx, string number, string numbers)
{
    if (idx == numbers.size())
    {
        if(number == "")                        return;
        if(!isPrime(stoi(number)))  return;

        primeNumbers.insert(stoi(number));
        return;
    }

    for (int i = 0; i < numbers.size(); ++i)
    {
        func(idx + 1, number, numbers);
        if(visited[i])  continue;

        visited[i] = true;
        func(idx + 1, number + numbers[i], numbers);
        visited[i] = false;
    }
}

int solution(string numbers)
{
    func(0, "", numbers);

    for (auto e: primeNumbers)
    {
        cout << e << endl;
    }

    return primeNumbers.size();
}

int main()
{
    cout << solution("17");
    return 0;
}