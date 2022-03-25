//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2 피로도
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
//void DFS(vector<vector<int>> dungeons, vector<bool> visit, int dungeonIndex, int fatigueLevel, int depth, int& answer)
//{
//    visit[dungeonIndex] = true;
//    fatigueLevel -= dungeons[dungeonIndex][1];
//    
//    if ( answer < depth )
//        answer = depth;
//
//    for ( int i = 0; i < dungeons.size(); ++i )
//        if ( !visit[i] && fatigueLevel >= dungeons[i][0] )
//            DFS(dungeons, visit, i, fatigueLevel, depth + 1, answer);
//
//    return;
//}
//
//int solution(int k, vector<vector<int>> dungeons)
//{
//    int answer = 0;
//    vector<bool> visit(dungeons.size(), false);
//
//    for ( int i = 0; i < dungeons.size(); ++i )
//        if ( k >= dungeons[i][0] )
//            DFS(dungeons, visit, i, k, 1, answer);
//
//    return answer;
//}
//
//int main()
//{
//    int k = 80;
//    vector<vector<int>> dungeons = { {80, 20}, {50, 40}, {30,10} };
//
//    cout << solution(k, dungeons) << endl;
//
//    return 0;
//}