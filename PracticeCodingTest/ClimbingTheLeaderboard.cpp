//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv.Medium - Climbing the Leaderboard
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
//vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
//{
//    vector<int> answer;
//    ranked.erase(unique(ranked.begin(), ranked.end()), ranked.end());
//
//    int rankedIndex = 0;
//    for ( int i = player.size() - 1; i >= 0; --i )
//    {
//        while ( rankedIndex < ranked.size() && player[i] < ranked[rankedIndex] )
//        {
//            ++rankedIndex;
//        }
//
//        answer.push_back(rankedIndex + 1);
//    }
//
//    reverse(answer.begin(), answer.end());
//    return answer;
//}
//
//int main()
//{
//    vector<int> ranked = { 100, 90, 90, 80, 75, 60 };
//    vector<int> player = { 50, 65, 77, 90, 102 };
//
//    vector<int> result = climbingLeaderboard(ranked, player);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}