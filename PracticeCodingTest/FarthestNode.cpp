//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv3 가장 먼 노드
//
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//const int maxDist = 1000000;
//
//void BFS(queue<int>& vertices, vector<vector<int>> edgeList, vector<int>& dist)
//{
//    int vertex = vertices.front();
//    vertices.pop();    
//        
//    for ( int v : edgeList[vertex] )
//    {
//        if ( dist[v] == maxDist )
//            vertices.push(v);
//
//        dist[v] = min(dist[vertex] + 1, dist[v]);
//    }    
//}
//
//int solution(int n, vector<vector<int>> edge)
//{
//    queue<int> vertices;
//    vector<vector<int>> edgeList(n, vector<int>());
//    vector<int> dist(n, maxDist);
//        
//    for ( vector<int> e : edge )
//    {
//        edgeList[e[0] - 1].push_back(e[1] - 1);
//        edgeList[e[1] - 1].push_back(e[0] - 1);
//    }
//
//    vertices.push(0);
//    dist[0] = 0;
//
//    while ( !vertices.empty() )
//        BFS(vertices, edgeList, dist);
//
//    return count(dist.begin(), dist.end(), *max_element(dist.begin(), dist.end()));
//}
//
//int main()
//{
//    int n = 6;
//    vector<vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };
//
//    cout << solution(n, edge) << endl;
//
//	return 0;
//}