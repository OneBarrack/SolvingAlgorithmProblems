#include <iostream>
// 프로그래머스 월간 코드 챌린지 시즌3 : 공 이동 시뮬레이션
// 3

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

struct Rect
{
    int left;
    int top;
    int right;
    int bottom;
};

bool ForwardTracing(int n, int m, vector<vector<int>>& queries, int goalX, int goalY, int x, int y)
{
    for (vector<int>& query : queries)
    {
        int dx = query[1];
        switch (query[0])
        {
            case 0: y = max(y - dx, 0);     break;
            case 1: y = min(y + dx, m - 1); break;
            case 2: x = max(x - dx, 0);     break;
            case 3: x = min(x + dx, n - 1); break;
        }
    }

    return x == goalX && y == goalY;
}

bool BackwardTracing(int n, int m, vector<int> query, Rect& rect)
{
    int dx = query[1];
    switch (query[0])
    {
        case 0:
            if (rect.left == m - 1) return false;
            
            if (rect.left > 0) rect.left += dx;
            rect.right = min(rect.right + dx, m - 1);
            break;
        case 1:
            if (rect.right == 0) return false;

            if (rect.right < m - 1) rect.right -= dx;
            rect.left = max(rect.left - dx, 0);
            break;
        case 2:
            if (rect.top == n - 1) return false;
            
            if (rect.top > 0) rect.top += dx;
            rect.bottom = min(rect.bottom + dx, n - 1);
            break;
        case 3:
            if (rect.bottom == 0) return false;

            if (rect.bottom < n - 1) rect.bottom -= dx;
            rect.top = max(rect.top - dx, 0);
            break;
    }

    return true;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    Rect rect = {y, x, y, x};
    for (int i = queries.size() - 1; i >= 0; i--)
    {
        if (!BackwardTracing(n, m, queries[i], rect))
            return 0;
    }

    return ForwardTracing(n, m, queries, x, y, rect.top, rect.left) ? (long long)(rect.right - rect.left + 1) * (rect.bottom - rect.top + 1) : 0;
}

int main(void) {
    //int n = 2;
    //int m = 5;
    //int x = 0;
    //int y = 0;
    //vector<vector<int>> queries = {{3,1} ,{2,2}, {1,1}, {2,3}, {2,1}};

    //int n = 2;
    //int m = 2;
    //int x = 0;
    //int y = 0;
    //vector<vector<int>> queries = {{2,1} ,{0,1}, {1,1}, {0,1}, {2,1}};

    int n = 2;
    int m = 5;
    int x = 0;
    int y = 1;
    vector<vector<int>> queries = {{3,1} ,{2,2}, {1,1}, {2,3}, {0,1}, {2,1}};
    
    cout << solution(n, m, x, y, queries) << endl;

    return 0;
}
