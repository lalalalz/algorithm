#include <vector>
using namespace std;

int get(vector<vector<int>>& board, int move)
{
    int doll = 0;

    for (int i = 0; i < board.size(); ++i)
    {
        if(board[i][move] > 0)
        {
            doll = board[i][move];
            board[i][move] = 0;
            break;
        }
    }

    return doll;
}
int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    vector<int> basket;

    for (auto move : moves)
    {
        int doll = get(board, move - 1);

        if(doll > 0 && !basket.empty() && basket.back() == doll)
        {
            basket.pop_back();
            answer += 2;
        }
        else
        {
            basket.push_back(doll);
        }
    }

    return answer;
}