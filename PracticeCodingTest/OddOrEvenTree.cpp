#include <iostream>
// 프로그래머스 2025 프로그래머스 코드챌린지 1차 예선 : 홀짝트리
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

void MakeTreeNodes(unordered_map<int, vector<int>>& nodeInfos, unordered_map<int, bool>& visit, int node, vector<int>& treeNodes)
{
    if (visit[node]) return;

    visit[node] = true;
    treeNodes.push_back(node);

    for (int& childNode : nodeInfos[node])
    {
        MakeTreeNodes(nodeInfos, visit, childNode, treeNodes);
    }
}

bool IsOddEvenTree(unordered_map<int, vector<int>>& nodeInfos, int parentNode, int currentNode, bool bReverse, bool bIsRootNode = false)
{
    if (!bIsRootNode)
    {
        bool bIsReverseOddEven = (currentNode % 2) != ((nodeInfos[currentNode].size() - 1) % 2);
        if (bIsReverseOddEven != bReverse)
            return false;
    }

    for (int& childNode : nodeInfos[currentNode])
    {
        if (childNode == parentNode) continue;

        bool bIsReverseOddEven = (currentNode % 2) != (nodeInfos[currentNode].size() % 2);
        if (!IsOddEvenTree(nodeInfos, currentNode, childNode, bReverse))
            return false;
    }

    return true;
}

void CheckOddEvenTree(unordered_map<int, vector<int>>& nodeInfos, unordered_map<int, bool>& visit, int node, vector<int>& answer)
{
    vector<int> treeNodes;
    MakeTreeNodes(nodeInfos, visit, node, treeNodes);

    for (int& rootNode : treeNodes)
    {
        bool bIsReverseOddEven = (rootNode % 2) != (nodeInfos[rootNode].size() % 2);
        if (IsOddEvenTree(nodeInfos, 0, rootNode, bIsReverseOddEven, true))
        {
            answer[bIsReverseOddEven ? 1 : 0]++;
        }
    }
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2);

    unordered_map<int, vector<int>> nodeInfos;
    for (vector<int>& edge : edges)
    {
        nodeInfos[edge[0]].push_back(edge[1]);
        nodeInfos[edge[1]].push_back(edge[0]);
    }

    unordered_map<int, bool> visit;
    for (int& node : nodes)
    {
        if (visit[node]) continue;

        CheckOddEvenTree(nodeInfos, visit, node, answer);
    }

    return answer;
}

int main(void) {
    //vector<int> nodes = {11, 9, 3, 2, 4, 6};
    //vector<vector<int>> edges = {{9, 11} ,{2, 3}, {6, 3}, {3, 4}};

    vector<int> nodes = {9, 15, 14, 7, 6, 1, 2, 4, 5, 11, 8, 10};
    vector<vector<int>> edges = {{5, 14} ,{1, 4}, {9, 11}, {2, 15}, {2, 5}, {9, 7}, {8, 1}, {6, 4}};

    vector<int> result = solution(nodes, edges);
    for (int& res : result)
        cout << res << endl;

    //cout << solution(nodes, edges) << endl;

    return 0;
}
