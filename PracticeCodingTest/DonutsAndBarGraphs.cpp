//#include <iostream>
//// 프로그래머스 2024 KAKAO WINTER INTERNSHIP : 도넛과 막대 그래프
//// 2
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
//enum EShapeType
//{
//    None = 0,
//    Donut,
//    Stick,
//    Figure8
//};
//
//void Search(map<int, vector<int>>& nodes, map<int, bool>& visitInfo, int currentNode, int& cycleCount)
//{
//    if (visitInfo[currentNode])
//    {
//        cycleCount++;
//        return;
//    }
//
//    visitInfo[currentNode] = true;
//
//    for (int nextNode : nodes[currentNode])
//    {
//        Search(nodes, visitInfo, nextNode, cycleCount);
//    }
//}
//
//vector<int> solution(vector<vector<int>> edges) {
//    vector<int> answer(4);    
//    map<int, vector<int>> nodes;
//
//    map<int, int> edgeCountsOfStartNodes;
//    set<int> nonOnlyStartNodes;
//    for (vector<int>& edge : edges)
//    {
//        int startNode = edge[0];
//        int endNode = edge[1];
//
//        nodes[startNode].push_back(endNode);
//
//        // 시작 노드와 간선 수 정보 처리
//        if (nonOnlyStartNodes.find(startNode) == nonOnlyStartNodes.end())
//        {
//            edgeCountsOfStartNodes[startNode]++;
//        }
//
//        if (edgeCountsOfStartNodes.find(endNode) != edgeCountsOfStartNodes.end())
//        {
//            edgeCountsOfStartNodes.erase(endNode);
//        }
//
//        nonOnlyStartNodes.insert(endNode);
//    }
//
//    // 생성된 시작 노드 적재
//    for (auto& startNode : edgeCountsOfStartNodes)
//    {
//        if (startNode.second > 1)
//        {
//            answer[EShapeType::None] = startNode.first;
//        }
//    }
//
//    // 시작 노드로부터 탐색
//    for (int node : nodes[answer[EShapeType::None]])
//    {
//        map<int, bool> visitInfo;
//        int cycleCount = 0;
//
//        Search(nodes, visitInfo, node, cycleCount);
//
//        switch (cycleCount)
//        {
//        case 0: answer[EShapeType::Stick]++;   break;
//        case 1: answer[EShapeType::Donut]++;   break;
//        case 2: answer[EShapeType::Figure8]++; break;
//        default:
//            break;
//        }
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<vector<int>> edges = {{2, 3} ,{4, 3}, {1, 1}, {2, 1}};
//    //vector<vector<int>> edges = {{4, 11} ,{1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}};
//
//    vector<int> result = solution(edges);
//    for (int res : result)
//        cout << res << endl;
//    //cout << solution(edges) << endl;
//
//    return 0;
//}
