#include <iostream>
// 프로그래머스 연습 문제 : 당구 연습
// 2

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    for (vector<int>& ball : balls)
    {
        double minDist = DBL_MAX;

        if (startX != ball[0] || startY > ball[1]) minDist = min(minDist, sqrt(pow(ball[0] - startX, 2) + pow((n - startY) + (n - ball[1]), 2))); // 상
        if (startX != ball[0] || startY < ball[1]) minDist = min(minDist, sqrt(pow(ball[0] - startX, 2) + pow(startY + ball[1], 2))); // 하
        if (startY != ball[1] || startX < ball[0]) minDist = min(minDist, sqrt(pow(startX + ball[0], 2) + pow(ball[1] - startY, 2))); // 좌
        if (startY != ball[1] || startX > ball[0]) minDist = min(minDist, sqrt(pow((m - startX) + (m - ball[0]), 2) + pow(ball[1] - startY, 2))); // 우

        answer.push_back(static_cast<int>(round(pow(minDist, 2))));
    }

    return answer;
}

int main(void) {
    int m = 10;
    int n = 10;
    int startX = 3;
    int startY = 7;
    vector<vector<int>> balls = {{7, 7}, {2, 7}, {7, 3}, {3, 5}};

    vector<int> results = solution(m, n, startX, startY, balls);
    for (int& res : results)
        cout << res << endl;

    //cout << solution(maps) << endl;

    return 0;
}
