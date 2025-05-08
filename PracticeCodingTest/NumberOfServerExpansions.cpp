#include <iostream>
// 프로그래머스 코딩테스트 연습 
// 2025 코드챌린지 2차 예선 Lv2. 서버 증설 횟수

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

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    queue<int> expandedServers;
    for (int time = 0; time < players.size(); ++time)
    {
        while (!expandedServers.empty() && expandedServers.front() + k - 1 < time)
        {
            expandedServers.pop();
        }

        const int userCount = players[time];
        const int serverCount = 1 + expandedServers.size();
        const int allowedUserCount = serverCount * m - 1;

        if (allowedUserCount < userCount)
        {
            int nonConnectedUserCount = userCount - allowedUserCount;
            while (nonConnectedUserCount > 0)
            {
                expandedServers.push(time);

                nonConnectedUserCount -= m;
                ++answer;
            }
        }
    }

    return answer;
}

int main(void) {
    vector<int> players = {0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5};
    int m = 3;
    int k = 5;

    //vector<int> players = {0, 0, 0, 10, 0, 12, 0, 15, 0, 1, 0, 1, 0, 0, 0, 5, 0, 0, 11, 0, 8, 0, 0, 0};
    //int m = 5;
    //int k = 1;

    //vector<int> players = {0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 5, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
    //int m = 1;
    //int k = 1;

    cout << solution(players, m, k) << endl;

    return 0;
}