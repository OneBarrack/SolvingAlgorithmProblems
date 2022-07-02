#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <map>

using namespace std;

void DFS(int HP, vector<bool> visit, vector<int>& monsters, vector<int>& peoples, int curTown, int prevDamage, int savedPeopleCount, int& maxSavedPeopleCount)
{
    visit[curTown] = true;
    maxSavedPeopleCount = max(savedPeopleCount, maxSavedPeopleCount);

    for ( int nextTown = 0; nextTown < monsters.size(); ++nextTown )
    {
        int damage = prevDamage + monsters[nextTown];
        if ( !visit[nextTown] && damage <= HP )
            DFS(HP - damage, visit, monsters, peoples, nextTown, damage, savedPeopleCount + peoples[nextTown], maxSavedPeopleCount);
    }
}

int Solution1()
{
    int townCount, HP;
    cin >> townCount >> HP;

    vector<int> monsters(townCount);
    vector<int> peoples(townCount);

    for ( int i = 0; i < townCount; ++i ) cin >> monsters[i];
    for ( int i = 0; i < townCount; ++i ) cin >> peoples[i];

    int maxSavedPeopleCount = 0;
    for ( int curTown = 0; curTown < townCount; ++curTown )
    {
        vector<bool> visit(townCount, false);
        int damage = monsters[curTown];
        if ( damage <= HP )
            DFS(HP - damage, visit, monsters, peoples, curTown, damage, peoples[curTown], maxSavedPeopleCount);
    }

    cout << maxSavedPeopleCount;

    return 0;
}
//
class Drop7
{
public:
    Drop7() { board.resize(boardSize, vector<int>(boardSize)); }
    void SetBoard();
    bool OrganizedBoard();
    bool PushBall(int ball, int pos);

    vector<vector<int>> GetBoard() { return board; }
    int GetBoardSize() { return boardSize; }
    int GetBallCount();

    void Print();
private:
    bool RemoveBalls();
    void DropBalls();

private:
    const int boardSize = 7;
    vector<vector<int>> board;
};

void Drop7::SetBoard()
{
    for ( int i = 0; i < boardSize; ++i )
        for ( int j = 0; j < boardSize; ++j )
            cin >> board[i][j];
}

void Drop7::Print()
{
    for ( vector<int> boardRow : board )
    {
        for ( int num : boardRow )
            cout << num << " ";
        cout << "\n";
    }
}

bool Drop7::PushBall(int ball, int pos)
{
    if ( board[0][pos] > 0 )
        return false;

    for ( int i = 0; i < boardSize - 1; ++i )
    {
        if ( board[i + 1][pos] > 0 )
        {
            board[i][pos] = ball;
            return true;
        }
    }

    board[boardSize - 1][pos] = ball;
    return true;
}

bool Drop7::RemoveBalls()
{
    set<pair<int, int>> removeBalls;

    // Horizontal
    for ( int i = 0; i < boardSize; ++i )
    {
        int left = -1;
        for ( int j = 0; j < boardSize + 1; ++j )
        {
            int right = j;
            if ( right == boardSize || board[i][right] == 0 )
            {
                if ( left > -1 )
                {
                    int connectedSize = right - left;
                    for ( int k = left; k < j; ++k )
                        if ( board[i][k] == connectedSize )
                            removeBalls.insert(make_pair(i, k));

                    left = -1;
                }
            }
            else
            {
                if ( left == -1 )
                    left = right;
            }
        }
    }

    // Vertical
    for ( int i = 0; i < boardSize; ++i )
    {
        int up = -1;
        for ( int j = 0; j < boardSize + 1; ++j )
        {
            int down = j;
            if ( down == boardSize || board[down][i] == 0 )
            {
                if ( up > -1 )
                {
                    int connectedSize = down - up;
                    for ( int k = up; k < j; ++k )
                        if ( board[k][i] == connectedSize )
                            removeBalls.insert(make_pair(k, i));

                    up = -1;
                }
            }
            else
            {
                if ( up == -1 )
                    up = down;
            }
        }
    }

    if ( !removeBalls.empty() )
    {
        for ( auto removeBall : removeBalls )
            board[removeBall.first][removeBall.second] = 0;

        return true;
    }

    return false;
}

void Drop7::DropBalls()
{
    for ( int col = 0; col < boardSize; ++col )
    {
        stack<int> rowBalls;
        int row = 0;
        for ( ; row < boardSize; ++row )
        {
            int ball = board[row][col];
            if ( ball > 0 )
                rowBalls.push(ball);

            board[row][col] = 0;
        }

        while ( !rowBalls.empty() )
        {
            board[--row][col] = rowBalls.top();
            rowBalls.pop();
        }
    }
}

bool Drop7::OrganizedBoard()
{
    if ( !RemoveBalls() )
        return false;

    DropBalls();
    return true;
}

int Drop7::GetBallCount()
{
    int ballCount = 0;
    for ( vector<int> boardRow : board )
        ballCount += boardSize - count(boardRow.begin(), boardRow.end(), 0);

    return ballCount;
}

int Solution2()
{
    Drop7 drop7;
    drop7.SetBoard();

    int nextBall;
    cin >> nextBall;

    int answer = drop7.GetBoardSize() * drop7.GetBoardSize() + 1;

    for ( int i = 0; i < drop7.GetBoardSize(); ++i )
    {
        Drop7 tempDrop7 = drop7;
        tempDrop7.PushBall(nextBall, i);

        while ( tempDrop7.OrganizedBoard() );

        answer = min(answer, tempDrop7.GetBallCount());
    }

    cout << answer;

    return 0;
}

//
int Solution3()
{
    return 0;
}
//
int Solution4()
{
    return 0;
}

int main()
{
    Solution3();
    return 0;
}