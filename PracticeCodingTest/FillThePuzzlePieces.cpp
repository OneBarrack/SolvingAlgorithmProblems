#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 퍼즐 조각 채우기

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>

using namespace std;

enum class Direction
{
    NONE,
    LEFT,
    TOP,
    RIGHT,
    BOTTOM
};

void FindBlocks(vector<vector<bool>>& visit, vector<vector<int>>& board, multiset<set<Direction>>& blocks, Direction prevBlockDirection, int x, int y, int pieceCheckValue)
{
    set<Direction> directions;

    if ( prevBlockDirection != Direction::NONE )
        directions.insert(prevBlockDirection);

    visit[x][y] = true;

    // left
    if ( y > 0 && board[x][y - 1] == pieceCheckValue )
    {
        directions.insert(Direction::LEFT);

        if ( !visit[x][y - 1] )
            FindBlocks(visit, board, blocks, Direction::RIGHT, x, y - 1, pieceCheckValue);
    }

    // top
    if ( x > 0 && board[x - 1][y] == pieceCheckValue )
    {
        directions.insert(Direction::TOP);

        if ( !visit[x - 1][y] )
            FindBlocks(visit, board, blocks, Direction::BOTTOM, x - 1, y, pieceCheckValue);
    }

    // right
    if ( y < board[0].size() - 1 && board[x][y + 1] == pieceCheckValue )
    {
        directions.insert(Direction::RIGHT);

        if ( !visit[x][y + 1] )
            FindBlocks(visit, board, blocks, Direction::LEFT, x, y + 1, pieceCheckValue);
    }

    // bottom
    if ( x < board.size() - 1 && board[x + 1][y] == pieceCheckValue )
    {
        directions.insert(Direction::BOTTOM);

        if ( !visit[x + 1][y] )
            FindBlocks(visit, board, blocks, Direction::TOP, x + 1, y, pieceCheckValue);
    }

    if ( directions.empty() )
        directions.insert(Direction::NONE);

    blocks.insert(directions);
}

void RotateBlocks(multiset<set<Direction>>& blocks)
{
    multiset<set<Direction>> rotatedBlocks;

    for ( set<Direction> block : blocks )
    {
        set<Direction> rotatedBlock;
        for ( Direction dir : block )
        {
            if ( dir == Direction::NONE )
                rotatedBlock.insert(dir);
            else if ( dir == Direction::BOTTOM )
                rotatedBlock.insert(Direction::LEFT);
            else
                rotatedBlock.insert(static_cast<Direction>(static_cast<int>(dir) + 1));
        }

        rotatedBlocks.insert(rotatedBlock);
    }

    blocks = rotatedBlocks;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = 0;

    vector<multiset<set<Direction>>> boardBlocksList;
    vector<multiset<set<Direction>>> tableBlocksList;
    vector<vector<bool>> visit(game_board.size(), vector<bool>(game_board[0].size(), false));

    for ( int boardRow = 0; boardRow < game_board.size(); ++boardRow )
    {
        for ( int boardCol = 0; boardCol < game_board[0].size(); ++boardCol )
        {
            if ( !visit[boardRow][boardCol] && game_board[boardRow][boardCol] == 0 )
            {
                multiset<set<Direction>> blocks;
                FindBlocks(visit, game_board, blocks, Direction::NONE, boardRow, boardCol, 0);
                boardBlocksList.push_back(blocks);
            }
        }
    }

    visit.clear();
    visit.resize(table.size(), vector<bool>(table[0].size(), false));
    for ( int boardRow = 0; boardRow < table.size(); ++boardRow )
    {
        for ( int boardCol = 0; boardCol < table[0].size(); ++boardCol )
        {
            if ( !visit[boardRow][boardCol] && table[boardRow][boardCol] == 1 )
            {
                multiset<set<Direction>> blocks;
                FindBlocks(visit, table, blocks, Direction::NONE, boardRow, boardCol, 1);
                tableBlocksList.push_back(blocks);
            }
        }
    }

    for ( multiset<set<Direction>> boardBlocks : boardBlocksList )
    {
        for ( auto tableBlockIter = tableBlocksList.begin(); tableBlockIter != tableBlocksList.end(); ++tableBlockIter )
        {
            multiset<set<Direction>> tableBlocks = *tableBlockIter;
            bool bFindBlock = false;

            if ( boardBlocks.size() == tableBlocks.size() )
            {
                for ( int i = 0; i < 4; ++i )
                {
                    if ( boardBlocks == tableBlocks )
                    {
                        answer += boardBlocks.size();
                        bFindBlock = true;
                    }

                    if ( bFindBlock || i == 3 )
                        break;

                    RotateBlocks(tableBlocks);
                }
            }

            if ( bFindBlock )
            {
                tableBlocksList.erase(tableBlockIter);
                break;
            }
        }
    }

    return answer;
}

int main()
{
    //vector<vector<int>> game_board = {
    //    {1, 1, 0, 0, 1, 0},
    //    {0, 0, 1, 0, 1, 0},
    //    {0, 1, 1, 0, 0, 1},
    //    {1, 1, 0, 1, 1, 1},
    //    {1, 0, 0, 0, 1, 0},
    //    {0, 1, 1, 1, 0, 0}
    //};

    //vector<vector<int>> table = {
    //    {1, 0, 0, 1, 1, 0},
    //    {1, 0, 1, 0, 1, 0},
    //    {0, 1, 1, 0, 1, 1},
    //    {0, 0, 1, 0, 0, 0},
    //    {1, 1, 0, 1, 1, 0},
    //    {0, 1, 0, 0, 0, 0}
    //};

    vector<vector<int>> game_board = { {0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0}, {1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1}, {0,1,1,1,0,0,1,0,1,0,0,1,1,0,1,0,0,0}, {0,0,0,0,1,1,0,0,1,1,0,1,0,0,1,0,0,0}, {0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1}, {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0}, {0,0,0,1,1,1,0,0,1,1,0,1,1,1,1,0,0,1}, {1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0}, {0,0,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0}, {1,1,0,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1}, {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0}, {1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0,1,0}, {0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,0,0}, {1,0,1,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1}, {1,0,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0}, {0,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0}, {0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0}, {0,1,0,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0} };

    vector<vector<int>> table = { {1,1,1,1,1,1,0,1,0,1,1,0,0,1,0,0,1,0}, {0,0,0,0,0,0,1,1,1,0,1,0,1,1,0,1,1,0}, {1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,1,0,1}, {1,1,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,1}, {1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1}, {0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,0,0}, {1,1,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1}, {0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,0,0,0}, {1,0,1,0,0,0,0,1,0,1,1,0,1,1,0,1,1,1}, {1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,0}, {1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0}, {0,0,1,1,1,1,0,1,1,0,1,0,0,0,1,1,0,1}, {1,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1}, {1,1,0,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1}, {0,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1,0,0}, {1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1}, {0,0,0,0,1,0,1,1,1,0,0,1,0,1,1,0,1,1}, {0,1,1,1,1,0,0,1,0,0,1,1,0,1,0,0,1,1} };

    cout << solution(game_board, table) << endl;

    return 0;
}