//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1 실패율
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
//bool CompareFailureRate(pair<float, int>& a, pair<float, int>& b)
//{
//    bool result = false;
//
//    if ( a.first > b.first )
//    {
//        result = true;
//    }
//    else if ( a.first < b.first )
//    {
//        result = false;
//    }
//    else
//    {
//        if ( a.second < b.second )
//        {
//            result = true;
//        }
//        else
//        {
//            result = false;
//        }
//    }
//
//    return result;
//}
//
//vector<int> solution(int N, vector<int> stages)
//{
//    vector<int> answer;
//
//    vector<pair<float, int>> failureRates;
//    map<int, int> challengerCounts;
//
//    int totalChallengerCount = stages.size();
//
//    for ( int stage : stages )
//    {
//        ++challengerCounts[stage];
//    }
//
//    for ( int i = 1; i <= N; ++i )
//    {
//        int challengerCount = challengerCounts[i];
//        float failureRate = challengerCount / static_cast<float>(totalChallengerCount);
//        failureRates.emplace_back(make_pair(failureRate, i));
//
//        totalChallengerCount -= challengerCount;
//    }
//
//    sort(failureRates.begin(), failureRates.end(), CompareFailureRate);
//
//    for ( auto failureRateInfo : failureRates )
//    {
//        answer.emplace_back(failureRateInfo.second);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int N = 5;
//    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
//
//    vector<int> result = solution(N, stages);
//
//    for ( int res : result )
//	    cout << res << endl;
//
//	return 0;
//}