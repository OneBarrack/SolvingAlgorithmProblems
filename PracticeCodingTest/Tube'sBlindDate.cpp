#include <iostream>
// 프로그래머스 2017 카카오코드 본선 : 튜브의 소개팅
// 4

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
#include <numeric>

using namespace std;

void PushPointWithValid(int m, int n, long long s, vector<vector<int>>& time_map, vector<vector<long long>>& minSumTimes, set<int>& nextPoints, long long time, int x, int y)
{
    if (x < 0 || m - 1 < x || y < 0 || n - 1 < y) return;
    if (time_map[x][y] == -1) return;

    long long curTime = time + time_map[x][y];
    if (curTime <= s && curTime < minSumTimes[x][y])
    {
        minSumTimes[x][y] = curTime;
        nextPoints.insert(n * x + y);
    }
}

void Search(int m, int n, long long s, vector<vector<int>>& time_map, vector<vector<long long>>& minSumTimes, set<int>& nextPoints, int x, int y)
{
    PushPointWithValid(m, n, s, time_map, minSumTimes, nextPoints, minSumTimes[x][y], x - 1, y);
    PushPointWithValid(m, n, s, time_map, minSumTimes, nextPoints, minSumTimes[x][y], x + 1, y);
    PushPointWithValid(m, n, s, time_map, minSumTimes, nextPoints, minSumTimes[x][y], x, y - 1);
    PushPointWithValid(m, n, s, time_map, minSumTimes, nextPoints, minSumTimes[x][y], x, y + 1);
}

vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    vector<int> answer(2);
    vector<vector<long long>> minSumTimes(m, vector<long long>(n, INT_MAX));
    set<int> points;

    minSumTimes[0][0] = 0;
    points.insert(0);

    int depth = 0;
    while (!points.empty())
    {
        if (points.find(m * n - 1) != points.end())
            break;

        set<int> nextPoints;
        for (int point : points)
        {
            Search(m, n, s, time_map, minSumTimes, nextPoints, point / n, point % n);
        }

        points = nextPoints;
        depth++;
    }

    answer[0] = depth;
    answer[1] = minSumTimes[m - 1][n - 1];
    return answer;
}

int main(void) {
    //int m = 3;
    //int n = 3;
    //int s = 150;
    //vector<vector<int>> time_map = {{0, 2, 99}, {100, 100, 4}, {1, 2, 0}};

    int m = 4;
    int n = 6;
    int s = 25;
    vector<vector<int>> time_map = {{0, 1, 1, -1, 2, 4} ,{-1, 7, 2, 1, 5, 7},{-1, 1, -1, 1, 6, 3},{-1, 1, -1, -1, 7, 0}};

    vector<int> result = solution(m, n, s, time_map);
    for (int& res : result)
        cout << res << endl;

    //cout << solution(nodes, edges) << endl;

    return 0;
}
