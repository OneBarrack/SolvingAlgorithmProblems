//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1 크레인 인형뽑기 게임
//
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//
//using namespace std;
//
//int solution(vector<vector<int>> board, vector<int> moves)
//{
//    int answer = 0;
//    stack<int> basket;
//
//    for ( int move : moves )
//    {
//        for ( int row = 0; row < board.size(); row++ )
//        {
//            if ( board[row][move - 1] > 0 )
//            {
//                if ( basket.empty() || basket.top() != board[row][move - 1] )
//                {
//                    basket.push(board[row][move - 1]);
//                }
//                else
//                {
//                    basket.pop();                    
//                    answer += 2;
//                }
//
//                board[row][move - 1] = 0;
//                break;
//            }
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<vector<int>> board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
//    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
//
//    cout << solution(board, moves) << endl;
//
//    return 0;
//}