#include <iostream>
// 프로그래머스 코딩테스트 연습 
// [PCCP 기출문제] 9번 / 이웃한 칸

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

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    string centerColor = board[h][w];
    if (h > 0 && board[h - 1][w] == centerColor) ++answer;
    if (w > 0 && board[h][w - 1] == centerColor) ++answer;
    if (h < board.size() - 1 && board[h + 1][w] == centerColor) ++answer;
    if (w < board.size() - 1 && board[h][w + 1] == centerColor) ++answer;

    return answer;
}

int main()
{
    vector<vector<string>> board = {{"blue", "red", "orange", "red"},{"red", "red", "blue", "orange"},{"blue", "orange", "red", "red"},{"orange", "orange", "red", "blue"}};
    int h = 1;
    int w = 1;

    cout << solution(board, h, w) << endl;

    return 0;
}
