#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv3 리틀 프렌즈 사천성

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;
//
//struct Point
//{
//    int x, y;
//};
//
//enum class Direction
//{
//    NONE,
//    LEFT,
//    TOP,
//    RIGHT,
//    BOTTOM,
//};
//
//bool SearchTile(vector<string> board, int x, int y, char target, Direction dir, int depth)
//{   
//    char curTile = board[x][y];
//    if ( curTile == '*' )
//        return false;
//
//    if ( depth > 2 )
//        return false;
//
//    if ( depth > 0 && curTile != '.' )
//    {
//        if ( curTile == target )
//            return true;
//
//        return false;
//    }
//
//    bool bResult = false;
//
//    int curDepth;
//    // Left
//    if ( !bResult && y > 0 && dir != Direction::RIGHT )
//    {
//        curDepth = dir == Direction::LEFT ? depth : depth + 1;
//        bResult = SearchTile(board, x, y - 1, target, Direction::LEFT, curDepth);
//    }
//
//    // Top
//    if ( !bResult && x > 0 && dir != Direction::BOTTOM )
//    {
//        curDepth = dir == Direction::TOP ? depth : depth + 1;
//        bResult = SearchTile(board, x - 1, y, target, Direction::TOP, curDepth);
//    }
//
//    // Right
//    if ( !bResult && y < board[0].size() - 1 && dir != Direction::LEFT )
//    {
//        curDepth = dir == Direction::RIGHT ? depth : depth + 1;
//        bResult = SearchTile(board, x, y + 1, target, Direction::RIGHT, curDepth);
//    }
//
//    // Bottom
//    if ( !bResult && x < board.size() - 1 && dir != Direction::TOP )
//    {
//        curDepth = dir == Direction::BOTTOM ? depth : depth + 1;
//        bResult = SearchTile(board, x + 1, y, target, Direction::BOTTOM, curDepth);
//    }
//
//    return bResult;
//}
//
//void CheckTile(vector<string> board, map<char, vector<Point>> targetPoints, vector<char> targetTiles, string tileOrderStr, string& answer)
//{     
//    if ( targetTiles.empty() )
//    {
//        answer = tileOrderStr < answer ? tileOrderStr : answer;
//        return;
//    }
//
//    for ( char tile : targetTiles )
//    {
//        if ( SearchTile(board, targetPoints[tile][0].x, targetPoints[tile][0].y, tile, Direction::NONE, 0) )
//        {
//            vector<string> tempBoard = board;
//            vector<char> tempTargetTiles = targetTiles;
//            string tempTileOrderStr = tileOrderStr;
//
//            tempBoard[targetPoints[tile][0].x][targetPoints[tile][0].y] = '.';
//            tempBoard[targetPoints[tile][1].x][targetPoints[tile][1].y] = '.';
//            tempTargetTiles.erase(find(tempTargetTiles.begin(), tempTargetTiles.end(), tile));
//            tempTileOrderStr += tile;
//
//            CheckTile(tempBoard, targetPoints, tempTargetTiles, tempTileOrderStr, answer);
//        }       
//    }
//}
//
//string solution(int m, int n, vector<string> board)
//{    
//    string answer = "ZZ";
//
//    map<char, vector<Point>> targetPoints;
//    vector<char> targetTiles;
//    
//    for ( int i = 0; i < m; ++i )
//    {
//        for ( int j = 0; j < n; ++j )
//        {
//            char tile = board[i][j];
//            if ( isalpha(tile) )
//            {
//                if ( find(targetTiles.begin(), targetTiles.end(), tile) == targetTiles.end() )
//                    targetTiles.push_back(tile);
//                                
//                if ( targetPoints.find(tile) == targetPoints.end() )
//                    targetPoints.insert(make_pair(tile, vector<Point>()));
//
//                Point tilePos = { i, j };
//                targetPoints[tile].push_back(tilePos);
//            }
//        }
//    }
//
//    sort(targetTiles.begin(), targetTiles.end());
//
//    CheckTile(board, targetPoints, targetTiles, "", answer);
//
//    if ( answer == "ZZ" )
//        return "IMPOSSIBLE";
//
//    return answer;
//}

struct Point
{
    int x, y;
    Point(int px, int py) : x(px), y(py) {}
};

void DFS(vector<string> board, vector<char> tileList, unordered_map<char, vector<Point>> tilePoints, string tileOrder, set<string>& tileOrderList)
{
    if ( tileList.empty() )
    {
        tileOrderList.insert(tileOrder);
        return;
    }

    for ( char tile : tileList )
    {
        Point tilePoint1 = tilePoints[tile][0];
        Point tilePoint2 = tilePoints[tile][1];

        bool bPossible = true;

        // Check Order = Horizontal -> Vertical{
        // Check for Horizontal
        int sign = (tilePoint1.y - tilePoint2.y) > 0 ? -1 : 1;
        for ( int i = tilePoint1.y; i != tilePoint2.y; i += sign )
        {
            char targetTile = board[tilePoint1.x][i];
            if ( !(targetTile == '.' || targetTile == tile) )
            {
                bPossible = false;
                break;
            }
        }

        // Check for Vertical
        if ( bPossible )
        {
            int sign = (tilePoint1.x - tilePoint2.x) > 0 ? -1 : 1;
            for ( int i = tilePoint1.x; i != tilePoint2.x; i += sign )
            {
                char targetTile = board[i][tilePoint2.y];
                if ( !(targetTile == '.' || targetTile == tile) )
                {
                    bPossible = false;
                    break;
                }
            }
        }

        // Check Order = Vertical -> Horizontal
        if ( !bPossible )
        {
            bPossible = true;

            // Check for Vertical
            int sign = (tilePoint1.x - tilePoint2.x) > 0 ? -1 : 1;
            for ( int i = tilePoint1.x; i != tilePoint2.x; i += sign )
            {
                char targetTile = board[i][tilePoint1.y];
                if ( !(targetTile == '.' || targetTile == tile) )
                {
                    bPossible = false;
                    break;
                }
            }

            // Check for Horizontal
            if ( bPossible )
            {
                int sign = (tilePoint1.y - tilePoint2.y) > 0 ? -1 : 1;
                for ( int i = tilePoint1.y; i != tilePoint2.y; i += sign )
                {
                    char targetTile = board[tilePoint2.x][i];
                    if ( !(targetTile == '.' || targetTile == tile) )
                    {
                        bPossible = false;
                        break;
                    }
                }
            }
        }

        if ( bPossible )
        {
            vector<string> tempBoard = board;
            vector<char> temptileList = tileList;
            string tempTileOrder = tileOrder;

            tempBoard[tilePoint1.x][tilePoint1.y] = '.';
            tempBoard[tilePoint2.x][tilePoint2.y] = '.';
            temptileList.erase(remove(temptileList.begin(), temptileList.end(), tile), temptileList.end());
            tempTileOrder += tile;

            DFS(tempBoard, temptileList, tilePoints, tempTileOrder, tileOrderList);
        }
    }
}

string solution(int m, int n, vector<string> board)
{    
    string answer = "ZZ";

    vector<char> tileList;
    unordered_map<char, vector<Point>> tilePoints;

    set<char> tileListSet;
    for ( int i = 0; i < m; ++i )
    {
        string tiles = board[i];
        for ( int j = 0; j < n; ++j )
        {
            char tile = tiles[j];

            if ( isalpha(tile) )
            {
                tilePoints[tile].emplace_back(Point(i, j));
                tileListSet.insert(tile);
            }
        }
    }

    tileList.resize(tileListSet.size());
    copy(tileListSet.begin(), tileListSet.end(), tileList.begin());

    set<string> tileOrderList;
    string tileOrder = "";
    DFS(board, tileList, tilePoints, tileOrder, tileOrderList);

    answer = tileOrderList.empty() ? "IMPOSSIBLE" : *tileOrderList.begin();
    return answer;
}

int main()
{
    //m	n	board	                            answer
    //3	3   ["DBA", "C*A", "CDB"]	            "ABCD"
    //2	4   ["NRYN", "ARYA"]	                "RYAN"
    //4	4   [".ZI.", "M.**", "MZU.", ".IU."]	"MUZI"
    //2	2   ["AB", "BA"]	                    "IMPOSSIBLE"

    int m = 3, n = 3;
    vector<string> board = { "DBA", "C*A" , "CDB" };
    cout << solution(m, n, board) << endl;

    m = 2, n = 4;
    board = { "NRYN", "ARYA" };
    cout << solution(m, n, board) << endl;

    m = 4, n = 4;
    board = { ".ZI.", "M.**", "MZU.", ".IU." };
    cout << solution(m, n, board) << endl;

    m = 2, n = 2;
    board = { "AB", "BA" };
    cout << solution(m, n, board) << endl;

    m = 5, n = 5;
    board = { "FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE" };
    cout << solution(m, n, board) << endl;

    return 0;
}