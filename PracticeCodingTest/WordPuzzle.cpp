//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv4. Word Puzzle
//
//#include <string>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
//int solution(vector<string> strs, string t)
//{
//    unordered_set<string> strsSet;
//    vector<int> dp(t.size() + 1);
//
//    for ( string str : strs )
//    {
//        strsSet.insert(str);
//    }
//
//
//    // order 1 ~ 5 
//    for ( int i = 1; i <= 5; ++i )
//    {
//        if ( i > t.size() )
//            break;
//
//        int minUseCount = INT_MAX;
//        for ( int j = 1; j <= 5; ++j )
//        {
//            if ( i < j )
//                break;
//
//            if ( (i - j > 0 && dp[i - j] == 0) || strsSet.find(t.substr(i - j, j)) == strsSet.end() )
//                continue;
//
//            minUseCount = min(minUseCount, dp[i - j] + 1);
//        }
//
//        if ( minUseCount < INT_MAX )
//            dp[i] = minUseCount;
//    }
//
//    // order 6 ~ t.size()
//    for ( int i = 6; i <= t.size(); ++i )
//    {
//        int minUseCount = INT_MAX;
//        for ( int j = 1; j <= 5; ++j )
//        {
//            if ( dp[i - j] == 0 || strsSet.find(t.substr(i - j, j)) == strsSet.end() )
//                continue;
//
//            minUseCount = min(minUseCount, dp[i - j] + 1);
//        }
//
//        if ( minUseCount < INT_MAX )
//            dp[i] = minUseCount;
//    }
//
//    return (dp[t.size()] > 0) ? dp[t.size()] : -1;
//}
//
//int main()
//{
//    vector<string> strs = { "ba","na","n","a" };
//    string t = "banana";
//    cout << solution(strs, t) << endl;
//
//    return 0;
//}