//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2 배달
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
//#include <sstream>
//
//using namespace std;
//
//void DFS(bool* visit, vector<vector<pair<int, int>>>& townNodes, int town, int K, set<int>& result)
//{
//    result.insert(town);
//    visit[town] = true;
//
//    for ( pair<int, int>& townNode : townNodes[town] )
//    {
//        if ( visit[townNode.first] )
//            continue;
//
//        if ( townNode.second <= K )
//        {
//            DFS(visit, townNodes, townNode.first, K - townNode.second, result);
//        }
//    }
//
//    visit[town] = false;
//}
//
//int solution(int N, vector<vector<int>> road, int K)
//{
//    set<int> result;
//    vector<vector<pair<int, int>>> townNodes(51);
//    bool visit[51] = { false, };
//
//    for ( vector<int> node : road )
//    {
//        townNodes[node[0]].emplace_back(make_pair(node[1], node[2]));
//        townNodes[node[1]].emplace_back(make_pair(node[0], node[2]));
//    }
//
//    DFS(visit, townNodes, 1, K, result);
//
//    return result.size();
//}
//
//int main()
//{
//    int N = 6;
//    //vector<vector<int>> road = { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} };
//    vector<vector<int>> road = { {1,2,1} ,{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} };
//    int K = 4;
//    
//    cout << solution(N, road, K) << endl;
//
//    return 0;
//}