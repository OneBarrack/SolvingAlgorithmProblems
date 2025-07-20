#include <iostream>
// 프로그래머스 연습 문제 : 미로 탈출
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

// BFS
int ShortestPathSearch(vector<string>& maps, vector<int> startPos, vector<int> endPos)
{
    int resultDepth = 0;
        
    queue<pair<vector<int>, int>> q;
    vector<vector<bool>> visits(maps.size(), vector<bool>(maps[0].size()));

    q.push(make_pair(startPos, 0));
    visits[startPos[0]][startPos[1]] = true;

    while (!q.empty())
    {
        vector<int> pos = q.front().first;
        int depth = q.front().second;
        q.pop();

        int row = pos[0];
        int col = pos[1];        

        if (pos == endPos)
        {
            resultDepth = depth;
            break;
        }

        if (row > 0 && maps[row - 1][col] != 'X' && !visits[row - 1][col])
        {
            visits[row - 1][col] = true;
            q.push(make_pair(vector<int>{row - 1, col}, depth + 1)); 
        }

        if (row < maps.size() - 1 && maps[row + 1][col] != 'X' && !visits[row + 1][col])
        {
            visits[row + 1][col] = true;
            q.push(make_pair(vector<int>{row + 1, col}, depth + 1));
        }

        if (col > 0 && maps[row][col - 1] != 'X' && !visits[row][col - 1])
        {
            visits[row][col - 1] = true;
            q.push(make_pair(vector<int>{row, col - 1}, depth + 1)); 
        }
        if (col < maps[0].size() - 1 && maps[row][col + 1] != 'X' && !visits[row][col + 1])
        {
            visits[row][col + 1] = true;
            q.push(make_pair(vector<int>{row, col + 1}, depth + 1));
        }
    }

    return resultDepth;
}

int solution(vector<string> maps) {
    int answer = -1;
    vector<int> startPos, leverPos, exitPos;

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            switch (maps[i][j])
            {
            case 'S': startPos = vector<int>{i, j}; break;
            case 'L': leverPos = vector<int>{i, j}; break;
            case 'E': exitPos  = vector<int>{i, j}; break;
            }

            if (!startPos.empty() && !leverPos.empty() && !exitPos.empty())
                break;
        }

        if (!startPos.empty() && !leverPos.empty() && !exitPos.empty())
            break;
    }

    if (int moveCountFromStartToLever = ShortestPathSearch(maps, startPos, leverPos); moveCountFromStartToLever > 0)
    {
        if (int moveCountFromLeverToExit = ShortestPathSearch(maps, leverPos, exitPos); moveCountFromLeverToExit > 0)
        {
            answer = moveCountFromStartToLever + moveCountFromLeverToExit;
        }
    }

    return answer;
}

int main(void) {
    vector<string> maps = {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
    //vector<string> maps = {"LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"};
    
    cout << solution(maps) << endl;

    return 0;
}
