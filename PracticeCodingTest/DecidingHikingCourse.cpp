//#include <iostream>
//// 프로그래머스 2022 KAKAO TECH INTERNSHIP : 등산코스 정하기
//// 3
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
//const inline bool IsGate(const vector<int>& gates, const int point) { return binary_search(gates.begin(), gates.end(), point); }
//const inline bool IsPeak(const vector<int>& summits, const  int point) { return binary_search(summits.begin(), summits.end(), point); }
//const inline bool IsShelter(const vector<int>& gates, const vector<int>& summits, const  int point){ return !IsGate(gates, point) && !IsPeak(summits, point); }
//
//void PathFindingToPeak(const unordered_map<int, unordered_map<int, int>>& links, const vector<int>& gates, const vector<int>& summits, unordered_map<int, int>& intensities, vector<int> points)
//{
//    set<int> nextPointsSet;
//    for (const int& point : points)
//    {
//        if (links.find(point) == links.end())
//            continue;
//
//        for (const auto link : links.at(point))
//        {
//            const int nextPoint = link.first;
//            const int intensity = link.second;
//
//            if (intensities[nextPoint] > 0)
//            {
//                if (intensity < intensities[nextPoint] && intensities[point] < intensities[nextPoint])
//                {
//                    intensities[nextPoint] = max(intensity, intensities[point]);
//                    if (IsShelter(gates, summits, nextPoint)) nextPointsSet.insert(nextPoint);
//                }
//            }
//            else
//            {
//                intensities[nextPoint] = max(intensity, intensities[point]);
//                if (IsShelter(gates, summits, nextPoint)) nextPointsSet.insert(nextPoint);
//            }
//        }
//    }
//
//    if (!nextPointsSet.empty())
//    {
//        points = vector<int>(nextPointsSet.begin(), nextPointsSet.end());
//        sort(points.begin(), points.end(), [&intensities](const int& pointA, const int& pointB) {
//            return intensities[pointA] < intensities[pointB];
//            });
//
//        PathFindingToPeak(links, gates, summits, intensities, points);
//    }
//}
//
//vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
//    vector<int> answer(2, INT_MAX);
//    unordered_map<int, unordered_map<int, int>> links;
//    unordered_map<int, int> intensities;
//    
//    sort(gates.begin(), gates.end());
//    sort(summits.begin(), summits.end());
//
//    for (const vector<int>& path : paths)
//    {
//        links[path[0]][path[1]] = path[2];
//        links[path[1]][path[0]] = path[2];
//    }
//        
//    PathFindingToPeak(links, gates, summits, intensities, gates);
//
//    for (const int& summit : summits)
//    {
//        const int intensity = intensities[summit];
//        if (intensity > 0 && intensity < answer[1])
//        {
//            answer[0] = summit;
//            answer[1] = intensity;
//        }
//    }
//
//    return answer;
//}
//
//int main(void) {
//    if (1)
//    {
//        vector<vector<int>> results;
//
//        int n = 6;
//        vector<vector<int>> paths = {{1, 2, 3} ,{2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1}};
//        vector<int> gates = {1, 3};
//        vector<int> summits = {5};
//        results.push_back(solution(n, paths, gates, summits));
//        // result = [5, 3]
//
//        n = 9;
//        paths = {{1, 2, 3} ,{2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1}, {7, 6, 2}, {7, 8, 2}, {8, 9, 1}};
//        gates = {1, 3, 9};
//        summits = {5};
//        results.push_back(solution(n, paths, gates, summits));
//        // result = [5, 2]
//
//        n = 10;
//        paths = {{1, 2, 3} ,{2, 3, 5}, {2, 4, 2}, {2, 5, 1}, {3, 4, 4},{3, 6, 2}, {4, 6, 2}, {7, 6, 2}, {7, 8, 2}, {8, 9, 1}, {9, 10, 1}};
//        gates = {1, 3, 10};
//        summits = {5};
//        results.push_back(solution(n, paths, gates, summits));
//        // result = [5, 2]
//
//        n = 7;
//        paths = {{1, 4, 4} ,{1, 6, 1}, {1, 7, 3}, {2, 5, 2}, {3, 7, 4}, {5, 6, 6}};
//        gates = {1};
//        summits = {2, 3, 4};
//        results.push_back(solution(n, paths, gates, summits));
//        // result = [3, 4]
//
//        n = 10;
//        paths = {{1, 4, 4} ,{1, 6, 1}, {1, 7, 3}, {2, 5, 2}, {3, 7, 4}, {5, 6, 6}, {6, 8, 2}, {9, 8, 1}, {10, 9, 2}, {10, 2, 2}};
//        gates = {1};
//        summits = {2, 3, 4};
//        results.push_back(solution(n, paths, gates, summits));
//        // result = [2, 2]
//
//        n = 7;
//        paths = {{1, 2, 5} ,{1, 4, 1}, {2, 3, 1}, {2, 6, 7}, {4, 5, 1}, {5, 6, 1}, {6, 7, 1}};
//        gates = {3, 7};
//        summits = {1, 5};
//        results.push_back(solution(n, paths, gates, summits));
//        // result = [5, 1]
//
//        n = 7;
//        paths = {{1, 6, 5} ,{1, 4, 1}, {2, 3, 1}, {2, 6, 7}, {4, 5, 1}, {5, 2, 1}, {6, 7, 1}};
//        gates = {3, 7};
//        summits = {1, 5};
//        results.push_back(solution(n, paths, gates, summits));
//        // result = [5, 1]
//
//        n = 5;
//        paths = {{1, 3, 10} ,{1, 4, 20}, {2, 3, 4}, {2, 4, 6}, {3, 5, 20}, {4, 5, 6}};
//        gates = {1, 2};
//        summits = {5};
//        results.push_back(solution(n, paths, gates, summits));
//        // result = [5, 6]
//
//        n = 5;
//        paths = {{1, 3, 1}, {2, 4, 1}, {3, 4, 2}, {4, 5, 3}};
//        gates = {5};
//        summits = {1, 2};
//        // result = [1, 3]
//        results.push_back(solution(n, paths, gates, summits));
//
//        n = 7;
//        paths = {{1, 6, 1} ,{1, 4, 1}, {6, 7, 1}, {6, 2, 7}, {4, 5, 1}, {5, 2, 1}, {2, 3, 1}};
//        gates = {3, 7};
//        summits = {1, 5};
//        // result = [1, 1]
//        results.push_back(solution(n, paths, gates, summits));
//
//        n = 4;
//        paths = {{1, 3, 1} ,{1, 4, 1}, {4, 2, 1}};
//        gates = {1};
//        summits = {2, 3, 4};
//        // result = [3, 1]
//        results.push_back(solution(n, paths, gates, summits));
//
//        n = 7;
//        paths = {{1, 4, 4} ,{1, 6, 1}, {1, 7, 3}, {2, 5, 2}, {3, 7, 4}, {5, 6, 6}};
//        gates = {2};
//        summits = {3, 4};
//        // result = [3, 6]
//        results.push_back(solution(n, paths, gates, summits));
//
//        n = 5;
//        paths = {{5, 4, 1} ,{5, 3, 1}, {3, 2, 2}, {4, 2, 1}, {2, 1, 1}};
//        gates = {1};
//        summits = {5};
//        // result = [5, 1]
//        results.push_back(solution(n, paths, gates, summits));
//
//        n = 5;
//        paths = {{1, 4, 3} ,{2, 4, 2}, {3, 4, 1}, {4, 5, 1}};
//        gates = {1, 2, 3};
//        summits = {5};
//        // result = [5, 1]
//        results.push_back(solution(n, paths, gates, summits));
//
//        for (vector<int> result : results)
//        {
//            for (int res : result)
//                cout << res << " ";
//            cout << endl;
//        }
//    }
//    else
//    {
//        /////////////////////////////////////////////// single
//        //int n = 10;
//        //vector<vector<int>> paths = {{1, 2, 4} ,{2, 3, 5}, {2, 4, 2}, {2, 5, 1}, {3, 4, 4},{3, 6, 3}, {4, 6, 2}, {7, 6, 2}, {7, 8, 2}, {8, 9, 1}, {9, 10, 1}};
//        //vector<int> gates = {1, 3, 10};
//        //vector<int> summits = {5};
//        //// result = [5, 2]
//
//        int n = 10;
//        vector<vector<int>> paths = {{1, 2, 3} ,{2, 3, 5}, {2, 4, 2}, {2, 5, 1}, {3, 4, 4},{3, 6, 2}, {4, 6, 2}, {7, 6, 2}, {7, 8, 2}, {8, 9, 1}, {9, 10, 1}};
//        vector<int> gates = {1, 3, 10};
//        vector<int> summits = {5};
//        // result = [5, 1]
//
//        //int n = 7;
//        //vector<vector<int>> paths = {{1, 2, 4}, {2, 4, 2}, {2, 5, 1}, {3, 7, 3}, {4, 6, 2}, {7, 6, 2}};// , {7, 6, 2}, {7, 8, 2}, {8, 9, 1}, {9, 10, 1}};
//        //vector<int> gates = {1, 3};
//        //vector<int> summits = {5};
//        // result = [5, 3]
//
//        //int n = 6;
//        //vector<vector<int>> paths = {{1, 2, 4}, {2, 4, 2}, {2, 5, 1}, {3, 6, 3}, {4, 6, 2}};// , {7, 6, 2}, {7, 8, 2}, {8, 9, 1}, {9, 10, 1}};
//        //vector<int> gates = {1, 3};
//        //vector<int> summits = {5};
//        //// result = [5, 3]
//
//        vector<int> result = solution(n, paths, gates, summits);
//        for (int res : result)
//            cout << res << " ";
//    }
//    return 0;
//}
