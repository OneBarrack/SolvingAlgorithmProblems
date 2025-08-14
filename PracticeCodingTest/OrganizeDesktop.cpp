#include <iostream>
// 프로그래머스 연습문제 : 바탕화면 정리
// 1

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <numeric>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {INT_MAX, INT_MAX, -1, -1}; // {top, left, bottom, right}

    for (int row = 0; row < wallpaper.size(); row++)
    {
        for (int col = 0; col < wallpaper[0].size(); col++)
        {
            if (wallpaper[row][col] == '#')
            {
                answer[0] = min(answer[0], row);
                answer[1] = min(answer[1], col);
                answer[2] = max(answer[2], row + 1);
                answer[3] = max(answer[3], col + 1);
            }
        }
    }

    return answer;
}

int main(void)
{
    //vector<string> wallpaper = {".#...", "..#..", "...#."};
    vector<string> wallpaper = {".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...."};

    vector<int> result = solution(wallpaper);
    for (int res : result)
        cout << res << endl;

    return 0;
}
