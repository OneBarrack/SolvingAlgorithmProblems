//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.3 - 섬 연결하기
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
//#include <numeric>
//
//using namespace std;
//
//int GetParent(unordered_map<int, int> parents, int isle)
//{
//    while ( parents[isle] != isle )
//    {
//        isle = parents[isle];
//    }
//
//    return isle;
//}
//
//bool IsCycle(unordered_map<int, int> parents, int isle1, int isle2)
//{
//    return (GetParent(parents, isle1) == GetParent(parents, isle2));
//}
//
//int solution(int n, vector<vector<int>> costs)
//{
//    int answer = 0;
//    unordered_map<int, int> parents;
//    for ( int i = 0; i < n; ++i )
//        parents[i] = i;
//
//    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) -> bool { return a[2] < b[2]; });
//    for ( vector<int> isleCostInfo : costs )
//    {
//        int isle1 = min(isleCostInfo[0], isleCostInfo[1]);
//        int isle2 = max(isleCostInfo[0], isleCostInfo[1]);
//        int cost = isleCostInfo[2];
//
//        if ( IsCycle(parents, isle1, isle2) )
//            continue;
//
//        parents[GetParent(parents, isle2)] = GetParent(parents, isle1);
//        answer += cost;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int n = 4;
//    vector<vector<int>> costs = { {0,1,1} ,{0,2,2}, {1,2,5}, {1,3,1}, {2,3,8} };
//    cout << solution(n, costs) << endl;
//
//    return 0;
//}