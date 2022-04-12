//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.2 - 양궁 대회
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
//vector<int> GetMoreLowerScores(vector<int> v1, vector<int> v2)
//{
//    vector<int> result = v1;
//    for ( int i = v1.size() - 1; i >= 0; --i )
//    {
//        if ( v1[i] == v2[i] )
//            continue;
//
//        result = (v1[i] > v2[i]) ? v1 : v2;
//        break;
//    }
//
//    return result;
//}
//
//void DFS(vector<int> info, int index, int scoreGap, int& maxScoreGap, int arrowCount, vector<int> result, vector<int>& answer)
//{
//    if ( index == 10 )
//    {
//        result[10] = arrowCount;
//        if ( maxScoreGap < scoreGap )
//        {
//            answer = result;
//            maxScoreGap = scoreGap;
//        }
//        else if ( maxScoreGap == scoreGap )
//        {
//            answer = GetMoreLowerScores(answer, result);
//        }
//        return;
//    }
//
//    result[index] = 0;
//    DFS(info, index + 1, scoreGap, maxScoreGap, arrowCount, result, answer);
//
//    if ( arrowCount > info[index] )
//    {
//        int score = 10 - index;
//        scoreGap += (info[index] > 0) ? score * 2 : score;
//        result[index] = info[index] + 1;
//        DFS(info, index + 1, scoreGap, maxScoreGap, arrowCount - result[index], result, answer);
//    }
//}
//
//vector<int> solution(int n, vector<int> info)
//{
//    vector<int> answer;
//    int maxScoreGap = 0;
//    for ( int i = 0; i < info.size(); ++i )
//    {
//        if ( info[i] > 0 )
//        {
//            maxScoreGap -= (10 - i);
//        }
//    }
//
//    DFS(info, 0, maxScoreGap, maxScoreGap, n, vector<int>(11), answer);
//    return (maxScoreGap > 0) ? answer : vector<int>(1, -1);
//}
//
//int main()
//{
//    int n = 5;
//    vector<int> info = { 2,1,1,1,0,0,0,0,0,0,0 };
//    vector<int> result = solution(n, info);
//
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}