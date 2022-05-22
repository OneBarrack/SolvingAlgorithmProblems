//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv3 리틀 프렌즈 사천성
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_map>
//
//using namespace std;
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
//void DFS(vector<vector<bool>> visit, vector<string> board, map<char, pair<int, int>> tileList, char targetTile, Direction dir, int depth, int x, int y, vector<char> result, string& answer)
//{
//    if ( !answer.empty() || board[x][y] == '*' || depth > 2 )
//        return;
//
//    visit[x][y] = true;
//    if ( dir == Direction::NONE )
//        board[x][y] = '.';
//
//    char tile = board[x][y];
//    if ( tile == targetTile )
//    {
//        board[x][y] = '.';
//
//        auto nextTileList = tileList;
//        nextTileList.erase(tile);
//        result.push_back(tile);
//
//        if ( nextTileList.empty() )
//        {
//            string s(result.begin(), result.end());
//            answer = s;
//            return;
//        }
//
//        for ( auto iter = nextTileList.begin(); iter != nextTileList.end(); ++iter )
//        {
//            char nextTargetTile = iter->first;
//            auto nextTargetCoods = iter->second;
//
//            fill(visit.begin(), visit.end(), vector<bool>(visit[0].size(), false));
//            DFS(visit, board, nextTileList, nextTargetTile, Direction::NONE, 0, nextTargetCoods.first, nextTargetCoods.second, result, answer);
//        }
//    }
//    else if ( tile == '.' )
//    {
//        Direction nextDir;
//        int nextDepth;
//
//        // left
//        if ( y > 0 && !visit[x][y - 1] )
//        {
//            nextDir = Direction::LEFT;
//            nextDepth = (dir == Direction::LEFT) ? depth : depth + 1;
//            DFS(visit, board, tileList, targetTile, nextDir, nextDepth, x, y - 1, result, answer);
//        }
//
//        // top
//        if ( x > 0 && !visit[x - 1][y] )
//        {
//            nextDir = Direction::TOP;
//            nextDepth = (dir == Direction::TOP) ? depth : depth + 1;
//            DFS(visit, board, tileList, targetTile, nextDir, nextDepth, x - 1, y, result, answer);
//        }
//
//        // right
//        if ( y < board[0].size() - 1 && !visit[x][y + 1] )
//        {
//            nextDir = Direction::RIGHT;
//            nextDepth = (dir == Direction::RIGHT) ? depth : depth + 1;
//            DFS(visit, board, tileList, targetTile, nextDir, nextDepth, x, y + 1, result, answer);
//        }
//
//        // bottom
//        if ( x < board.size() - 1 && !visit[x + 1][y] )
//        {
//            nextDir = Direction::BOTTOM;
//            nextDepth = (dir == Direction::BOTTOM) ? depth : depth + 1;
//            DFS(visit, board, tileList, targetTile, nextDir, nextDepth, x + 1, y, result, answer);
//        }
//    }
//}
//
//string solution(int m, int n, vector<string> board)
//{
//    string answer = "";
//
//    map<char, pair<int, int>> tileList;
//    vector<vector<bool>> visit(m, vector<bool>(n, false));
//
//    for ( int i = 0; i < m; ++i )
//        for ( int j = 0; j < n; ++j )
//            if ( isalpha(board[i][j]) )
//                tileList[board[i][j]] = make_pair(i, j);
//
//    for ( auto iter = tileList.begin(); iter != tileList.end(); ++iter )
//    {
//        char targetTile = iter->first;
//        auto targetCoods = iter->second;
//
//        DFS(visit, board, tileList, targetTile, Direction::NONE, 0, targetCoods.first, targetCoods.second, vector<char>(), answer);
//    }
//
//    return answer.empty() ? "IMPOSSIBLE" : answer;
//}
//
//int main()
//{
//    //m	n	board	                            answer
//    //3	3   ["DBA", "C*A", "CDB"]	            "ABCD"
//    //2	4   ["NRYN", "ARYA"]	                "RYAN"
//    //4	4   [".ZI.", "M.**", "MZU.", ".IU."]	"MUZI"
//    //2	2   ["AB", "BA"]	                    "IMPOSSIBLE"
//
//    int m = 3, n = 3;
//    vector<string> board = { "DBA", "C*A" , "CDB" };
//    cout << solution(m, n, board) << endl;
//
//    m = 2, n = 4;
//    board = { "NRYN", "ARYA" };
//    cout << solution(m, n, board) << endl;
//
//    m = 4, n = 4;
//    board = { ".ZI.", "M.**", "MZU.", ".IU." };
//    cout << solution(m, n, board) << endl;
//
//    m = 2, n = 2;
//    board = { "AB", "BA" };
//    cout << solution(m, n, board) << endl;
//
//    m = 5, n = 5;
//    board = { "FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE" };
//    cout << solution(m, n, board) << endl;
//
//    return 0;
//}