#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv3 가장 먼 노드

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    queue<int> edgeQueue;
    vector<vector<int>> edgeLists(n + 1, vector<int>());
    vector<int> dists(n + 1);
    bool visit[20000] = { false, };

    for ( vector<int> e : edge )
    {
        edgeLists[e[0]].push_back(e[1]);
        edgeLists[e[1]].push_back(e[0]);
    }

    edgeQueue.push(1);

    // BFS    
    dists[1] = 0;
    visit[1] = true;
    while ( !edgeQueue.empty() )
    {
        int edge = edgeQueue.front();
        int dist = dists[edge];
        edgeQueue.pop();

        vector<int> edgeList = edgeLists[edge];
        for ( int nextEdge : edgeList )
        {
            if ( !visit[nextEdge] )
            {
                visit[nextEdge] = true;
                edgeQueue.push(nextEdge);
                dists[nextEdge] = dist + 1;
            }
        }
    }

    return count(dists.begin(), dists.end(), *max_element(dists.begin(), dists.end()));
}

int main()
{
    int n = 6;
    vector<vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };

    cout << solution(n, edge) << endl;

	return 0;
}