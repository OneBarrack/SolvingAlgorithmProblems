//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// 연습문제. 리코쳇 로봇
//
//#include <string>
//#include <vector>
//#include <queue>
//#include <set>
//#include <algorithm>
//#include <unordered_map>
//#include <numeric>
//#include <stack>
//#include <map>
//
//using namespace std;
//
//int solution(vector<string> board) {
//    vector<int> sPos, ePos;
//
//    bool bFoundR = false;
//    bool bFoundG = false;
//    for (int i = 0; i < board.size(); i++)
//    {
//        if (bFoundR && bFoundG)
//            break;
//
//        for (int j = 0; j < board[i].size(); j++)
//        {
//            if (bFoundR && bFoundG)
//                break;
//
//            if (board[i][j] == 'R') sPos = vector<int>{i, j, 0};
//            if (board[i][j] == 'G') ePos = vector<int>{i, j, 0};
//        }
//    }
//
//    bool visit[100][100] = {false,};
//
//    queue<vector<int>> q;
//    q.push(sPos);
//    visit[sPos[0]][sPos[1]] = true;
//
//    while (!q.empty())
//    {
//        vector<int> curPos = q.front();
//        q.pop();
//
//        int row = curPos[0];
//        int col = curPos[1];
//        int depth = curPos[2];
//
//        // goal
//        if (board[row][col] == 'G')
//            return depth;
//
//        // left
//        for (int i = 1; ; i++)
//        {
//            int nextCol = col - i;
//            if (nextCol < 0 || board[row][nextCol] == 'D')
//            {
//                if (!visit[row][nextCol + 1])
//                {
//                    q.push(vector<int>{row, nextCol + 1, depth + 1});
//                    visit[row][nextCol + 1] = true;
//                }
//                break;
//            }
//        }
//
//        // right
//        for (int i = 1; ; i++)
//        {
//            int nextCol = col + i;
//            if (nextCol > board[0].size() - 1 || board[row][nextCol] == 'D')
//            {
//                if (!visit[row][nextCol - 1])
//                {
//                    q.push(vector<int>{row, nextCol - 1, depth + 1});
//                    visit[row][nextCol - 1] = true;
//                }
//                break;
//            }
//        }
//
//        // top
//        for (int i = 1; ; i++)
//        {
//            int nextRow = row - i;
//            if (nextRow < 0 || board[nextRow][col] == 'D')
//            {
//                if (!visit[nextRow + 1][col])
//                {
//                    q.push(vector<int>{nextRow + 1, col, depth + 1});
//                    visit[nextRow + 1][col] = true;
//                }
//                break;
//            }
//        }
//
//        // bottom
//        for (int i = 1; ; i++)
//        {
//            int nextRow = row + i;
//            if (nextRow > board.size() - 1 || board[nextRow][col] == 'D')
//            {
//                if (!visit[nextRow - 1][col])
//                {
//                    q.push(vector<int>{nextRow - 1, col, depth + 1});
//                    visit[nextRow - 1][col] = true;
//                }
//                break;
//            }
//        }
//    }
//
//    return -1;
//}
//
//int main()
//{
//    vector<string> board = {"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."};
//    cout << solution(board) << endl;
//
//    return 0;
//}
