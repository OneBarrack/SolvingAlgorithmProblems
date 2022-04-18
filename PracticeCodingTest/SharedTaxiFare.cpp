//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.3 - 합승 택시 요금 
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
//int solution(int n, int s, int a, int b, vector<vector<int>> fares)
//{
//    const int INF = 100000000;
//
//    int answer = INF;
//    vector<vector<int>> minDists(n, vector<int>(n, INF));
//
//    // Init
//    for ( int i = 0; i < n; ++i )
//        minDists[i][i] = 0;
//
//    for ( vector<int> fare : fares )
//    {
//        minDists[fare[0] - 1][fare[1] - 1] = fare[2];
//        minDists[fare[1] - 1][fare[0] - 1] = fare[2];
//    }
//
//    // Floid-Washal
//    for ( int k = 0; k < n; ++k )
//        for ( int i = 0; i < n; ++i )
//            for ( int j = 0; j < n; ++j )
//                minDists[i][j] = min(minDists[i][j], minDists[i][k] + minDists[k][j]);
//
//    // Get MinDist
//    for ( int i = 0; i < n; ++i )
//        answer = min(answer, minDists[s - 1][i] + minDists[i][a - 1] + minDists[i][b - 1]);
//
//    return answer;
//}
//
//int main()
//{
//    int n = 6;
//    int s = 4;
//    int a = 6;
//    int b = 2;
//    vector<vector<int>> fares = {
//        {4, 1, 10},
//        {3, 5, 24},
//        {5, 6, 2},
//        {3, 1, 41},
//        {5, 1, 24},
//        {4, 6, 50},
//        {2, 4, 66},
//        {2, 3, 22},
//        {1, 6, 25} };
//    
//    cout << solution(n, s, a, b, fares) << endl;
//
//    return 0;
//}