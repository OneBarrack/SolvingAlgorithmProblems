//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.3 - 양과 늑대
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
//void SearchSheeps(vector<int>& nodeInfo, unordered_map<int, vector<int>>& graph, list<int> nextNodes, int node, int sheepCount, int wolfCount, int& answer)
//{
//    (nodeInfo[node] == 0) ? ++sheepCount : ++wolfCount;
//
//    if ( sheepCount == wolfCount )
//        return;
//
//    answer = max(sheepCount, answer);
//
//    for ( int linkedNode : graph[node] )
//        nextNodes.push_back(linkedNode);
//
//    for ( auto iter = nextNodes.begin(); iter != nextNodes.end(); )
//    {
//        int nextNode = *iter;
//
//        iter = nextNodes.erase(iter);
//        SearchSheeps(nodeInfo, graph, nextNodes, nextNode, sheepCount, wolfCount, answer);
//        nextNodes.insert(iter, nextNode);
//    }
//}
//
//int solution(vector<int> info, vector<vector<int>> edges)
//{
//    int answer = 0;
//
//    unordered_map<int, vector<int>> graph;
//    for ( vector<int>& edge : edges )
//    {
//        graph[edge[0]].push_back(edge[1]);
//    }
//
//    SearchSheeps(info, graph, list<int>(), 0, 0, 0, answer);
//
//    return answer;
//}
//
//int main()
//{
//    vector<int> info = { 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 };
//    vector<vector<int>> edges = { {0, 1},{1, 2},{1, 4},{0, 8},{8, 7},{9, 10},{9, 11},{4, 3},{6, 5},{4, 6},{8, 9} };
//
//    cout << solution(info, edges) << endl;
//
//    return 0;
//}