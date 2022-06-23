#include <iostream>
// 백준 코딩테스트 연습 
// Lv.Silver2 - DFS and BFS

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

/*
예제 입력 1
3
1
1
1
예제 출력 1
1
예제 입력 2
2
5
8
예제 출력 2
12
*/

void DFS(int N, unordered_map<int, set<int>>& graph, vector<bool>& visit, int edge, vector<int>& result)
{
    visit[edge] = true;
    result.push_back(edge);

    if ( result.size() == N )
        return;

    for ( int nextEdge : graph[edge] )
        if ( !visit[nextEdge] )
            DFS(N, graph, visit, nextEdge, result);

    return;
}

void BFS(int N, unordered_map<int, set<int>>& graph, vector<bool>& visit, queue<int> q, vector<int>& result)
{
    while ( !q.empty() )
    {
        int edge = q.front();
        q.pop();

        if ( visit[edge] )
            continue;

        visit[edge] = true;
        result.push_back(edge);

        for ( int nextEdge : graph[edge] )
            q.push(nextEdge);
    }

    return;
}
int main()
{
    int N, M, V;
    cin >> N >> M >> V;

    unordered_map<int, set<int>> graph;
    for ( int i = 0; i < M; ++i )
    {
        int edge1, edge2;
        cin >> edge1 >> edge2;
        graph[edge1].insert(edge2);
        graph[edge2].insert(edge1);
    }

    // DFS
    vector<bool> visit(N + 1, false);
    vector<int> DFSResult;
    DFS(N, graph, visit, V, DFSResult);
    for ( int res : DFSResult )
        cout << res << " ";
    cout << "\n";

    // BFS
    visit.clear();
    visit.resize(N + 1, false);
    vector<int> BFSResult;
    queue<int> q;
    q.push(V);
    BFS(N, graph, visit, q, BFSResult);
    for ( int res : BFSResult )
        cout << res << " ";

    return 0;
}