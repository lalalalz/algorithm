// 예상 대진

int solution(int n, int a, int b)
{
    int A = a - 1;
    int B = b - 1;
    int answer = 1;

    while(A/2 != B/2)
    {
        A /= 2;
        B /= 2;
        answer++;
    }

    return answer;
}
