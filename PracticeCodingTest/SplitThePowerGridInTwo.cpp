#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.2 - 전력망을 둘로 나누기

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

void DFS(vector<vector<int>> graph, vector<bool> visit, vector<int> parentList, int curNode, vector<int>& connCounts)
{
    visit[curNode] = true;
    parentList.emplace_back(curNode);

    int childCount = 0;
    for ( int node : graph[curNode] )
    {
        if ( !visit[node] )
        {
            DFS(graph, visit, parentList, node, connCounts);
            childCount++;
        }
    }

    for ( int parent : parentList )
    {
        connCounts[parent] += childCount;
    }
}

int solution(int n, vector<vector<int>> wires)
{
    int N = wires.size() + 1;
    int answer = N;

    vector<int> connCounts(N + 1);
    vector<vector<int>> graph(N + 1);
    vector<bool> visit(graph.size(), false);

    for ( vector<int> wire : wires )
    {
        graph[wire[0]].emplace_back(wire[1]);
        graph[wire[1]].emplace_back(wire[0]);
    }

    DFS(graph, visit, vector<int>(), 1, connCounts);

    for ( int connCount : connCounts )
    {
        answer = min(answer, abs(N - ((connCount + 1) * 2)));
    }

    return answer;
}