#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2 게임 맵 최단거리

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;

    vector<vector<int> > visit = maps;

    queue<pair<pair<int, int>, int> > pointQueue;
    pointQueue.push(make_pair(make_pair(0, 0), 1));

    // BFS    
    while ( !pointQueue.empty() )
    {
        int x = pointQueue.front().first.first;
        int y = pointQueue.front().first.second;
        int depth = pointQueue.front().second;
        pointQueue.pop();

        if ( x == maps.size() - 1 && y == maps[0].size() - 1 )
        {
            answer = depth;
            break;
        }        

        // Left
        if ( y > 0 && visit[x][y - 1] == 1 )
        {
            visit[x][y - 1] = 2;
            pointQueue.push(make_pair(make_pair(x, y - 1), depth + 1));
        }

        // Top
        if ( x > 0 && visit[x - 1][y] == 1 )
        {
            visit[x - 1][y] = 2;
            pointQueue.push(make_pair(make_pair(x - 1, y), depth + 1));
        }

        // Right
        if ( y < maps[0].size() - 1 && visit[x][y + 1] == 1 )
        {
            visit[x][y + 1] = 2;
            pointQueue.push(make_pair(make_pair(x, y + 1), depth + 1));
        }

        // Bottom
        if ( x < maps.size() - 1 && visit[x + 1][y] == 1 )
        {
            visit[x + 1][y] = 2;
            pointQueue.push(make_pair(make_pair(x + 1, y), depth + 1));
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> maps = { {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} };
    //vector<vector<int>> maps = { {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1} };
    cout << solution(maps) << endl;

    return 0;
}