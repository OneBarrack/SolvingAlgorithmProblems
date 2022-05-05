//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2. 가장 큰 정사각형 만들기
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
//#include <cmath>
//#include <cfloat>
//
//using namespace std;
//
//int solution(vector<vector<int>> board)
//{
//    if ( board.size() == 1 || board[0].size() == 1 )
//    {
//        for ( int i = 0; i < board.size(); ++i )
//            for ( int j = 0; j < board[0].size(); ++j )
//                if ( board[i][j] == 1 )
//                    return 1;
//    }
//
//    int maxSideLength = 0;
//
//    for ( int i = 1; i < board.size(); ++i )
//    {
//        for ( int j = 1; j < board[0].size(); ++j )
//        {
//            if ( board[i][j] == 1 )
//            {
//                board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
//                maxSideLength = max(board[i][j], maxSideLength);
//            }
//        }
//    }
//
//    return maxSideLength * maxSideLength;
//}
//
//int main()
//{
//    vector<vector<int>> board = { { 0,1,1,1}, {1, 1, 1,1}, {1, 1, 1,1}, { 0,0,1,0 } };
//    //vector<vector<int>> board = { {0, 0, 1, 1},{1, 1, 1, 1} };
//    cout << solution(board) << endl;
//
//    return 0;
//}