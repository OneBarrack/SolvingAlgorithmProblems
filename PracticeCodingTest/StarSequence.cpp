//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.4 - 스타 수열
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
//#include <unordered_set>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
//int solution(std::vector<int> a)
//{
//    if ( a.size() < 2 )
//        return 0;
//
//    int answer = 0;
//    unordered_map<int, int> subSequenceCounts;
//    unordered_map<int, int> prevIndices;
//
//    prevIndices[a[1]] = -1;
//    for ( int i = 0; i < a.size(); ++i )
//    {
//        if ( 0 < i && prevIndices[a[i]] != i - 1 && a[i - 1] != a[i] )
//        {
//            subSequenceCounts[a[i]] += 2;
//            prevIndices[a[i]] = i;
//        }
//        else if ( i < a.size() - 1 && a[i] != a[i + 1] )
//        {
//            subSequenceCounts[a[i]] += 2;
//            prevIndices[a[i]] = i + 1;
//        }
//    }
//
//    for ( auto iter = subSequenceCounts.begin(); iter != subSequenceCounts.end(); ++iter )
//        answer = max(answer, iter->second);
//    return answer;
//}
//
//int main()
//{
//    vector<int> a = { 0,3,3,0,7,2,0,2,2,0 };
//
//    cout << solution(a) << endl;
//
//    return 0;
//}