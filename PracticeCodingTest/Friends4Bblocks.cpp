//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2. [1차] 프렌즈 4블록
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
//unordered_set<char*> GetRemoveTargets(int m, int n, vector<string>& board)
//{
//    unordered_set<char*> removeTargets;
//
//    for ( int row = 0; row < m - 1; ++row )
//    {
//        for ( int col = 0; col < n - 1; ++col )
//        {
//            char& c = board[row][col]; // current
//            if ( c == '-' )
//                continue;
//
//            char& r = board[row][col + 1]; // right
//            char& b = board[row + 1][col]; // bottom
//            char& rb = board[row + 1][col + 1]; // right bottom
//            if ( c == r && c == b && c == rb )
//            {
//                if ( removeTargets.find(&c)  == removeTargets.end() ) removeTargets.insert(&c);
//                if ( removeTargets.find(&r)  == removeTargets.end() ) removeTargets.insert(&r);
//                if ( removeTargets.find(&b)  == removeTargets.end() ) removeTargets.insert(&b);
//                if ( removeTargets.find(&rb) == removeTargets.end() ) removeTargets.insert(&rb);
//            }
//        }
//    }
//
//    return removeTargets;
//}
//
//void RemoveTargetsInBoard(unordered_set<char*> removeTargets, int m, int n, vector<string>& board)
//{
//    // Remove targets
//    for ( char* removeTarget : removeTargets )
//    {
//        *removeTarget = '-';
//    }
//
//    // Drop blocks
//    for ( int col = 0; col < n; ++col )
//    {
//        for ( int row = m - 1; row > 0; --row )
//        {
//            if ( board[row][col] == '-' )
//            {
//                for ( int searchRow = row - 1; searchRow >= 0; --searchRow )
//                {
//                    if ( board[searchRow][col] != '-' )
//                    {
//                        board[row][col] = board[searchRow][col];
//                        board[searchRow][col] = '-';
//                        break;
//                    }
//                }
//            }
//        }
//    }
//}
//
//int solution(int m, int n, vector<string> board)
//{
//    int answer = 0;
//
//    unordered_set<char*> removeTargets;
//    removeTargets = GetRemoveTargets(m, n, board);
//    while ( !removeTargets.empty() )
//    {
//        answer += removeTargets.size();
//        RemoveTargetsInBoard(removeTargets, m, n, board);
//        removeTargets = GetRemoveTargets(m, n, board);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    //int m = 6;
//    //int n = 6;
//    //vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
//
//    int m = 8;
//    int n = 5;
//    vector<string> board = { "HGNHU", "CRSHV", "UKHVL", "MJHQB", "GSHOT", "MQMJJ", "AGJKK", "QULKK" };
//    
//    cout << solution(m, n, board) << endl;
//
//    return 0;
//}