#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 모두 0으로 만들기

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>

using namespace std;

long long ZeroSumForPostOrder(vector<bool>& visit, vector<int>& a, vector<vector<int>>& graph, int index, long long& answer)
{
    visit[index] = true;
    long long resultSum = 0;

    for ( int nextIndex : graph[index] )
        if ( !visit[nextIndex] )
            resultSum += ZeroSumForPostOrder(visit, a, graph, nextIndex, answer);

    answer += abs(resultSum + a[index]);
    return resultSum + a[index];
}

long long solution(vector<int> a, vector<vector<int>> edges)
{
    long long answer = 0;
    vector<bool> visit(a.size(), false);
    vector<vector<int>> graph(a.size());
    for ( vector<int>& edge : edges )
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    return (ZeroSumForPostOrder(visit, a, graph, 0, answer) == 0) ? answer : -1;
}

int main()
{
    //[-5, 0, 2, 1, 2] [[0, 1], [3, 4], [2, 3], [0, 3]]
    vector<int> a = { -5, 0, 2, 1, 2 };
    vector<vector<int>> edges = { {0,1}, {3,4}, {2,3}, {0,3} };

    cout << solution(a, edges) << endl;

    return 0;
}