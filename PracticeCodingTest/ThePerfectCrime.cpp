//#include <iostream>
//// 프로그래머스 코드챌린지 2차 예선 : 완전범죄
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
//void DFS(vector<vector<int>>& info, vector<vector<int>>& sumInfo, int n, int m, int index, int sumA, int sumB, int& answer)
//{
//    if (index >= info.size())
//    {
//        answer = min(sumA, answer);
//        return;
//    }
//
//    if (answer <= sumA)
//        return;
//
//    if (sumInfo[index][0] > -1 && sumInfo[index][1] > -1)
//    {
//        if (sumInfo[index - 1][0] == sumA && sumInfo[index - 1][1] == sumB)
//        {
//            return;
//        }
//    }
//
//    if (sumA + info[index][0] < n)
//    {
//        sumInfo[index][0] = sumA + info[index][0];
//        DFS(info, sumInfo, n, m, index + 1, sumA + info[index][0], sumB, answer);
//    }
//
//    if (sumB + info[index][1] < m)
//    {
//        sumInfo[index][1] = sumB + info[index][1];
//        DFS(info, sumInfo, n, m, index + 1, sumA, sumB + info[index][1], answer);
//    }
//}
//
//int solution(vector<vector<int>> info, int n, int m) {
//    int answer = INT_MAX;
//    vector<vector<int>> sumInfo(info.size(), vector<int>(2, -1));
//
//    sort(info.begin(), info.end(), [](const vector<int>& a, const vector<int>& b) {
//        return a[0] < b[0];
//        });
//
//    DFS(info, sumInfo, n, m, 0, 0, 0, answer);
//
//    return (answer == INT_MAX) ? -1 : answer;
//}
//
//int main(void) {
//    vector<vector<int>> info = {{1, 3}, {1, 3}, {1, 1}, {1, 1}, {1, 1}, {2, 3}, {2, 3}};
//    int n = 6;
//    int m = 7;
//
//    cout << solution(info, n, m) << endl;
//
//    return 0;
//}
