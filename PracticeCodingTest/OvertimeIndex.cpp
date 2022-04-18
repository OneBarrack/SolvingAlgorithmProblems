//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.3 - 야근 지수
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
//long long solution(int n, vector<int> works)
//{
//    long long answer = 0;
//
//    map<int, int> worksCount;
//    set<int, greater<int>> remainWorks;
//
//    for ( int work : works )
//    {
//        remainWorks.insert(work);
//        worksCount[work]++;
//    }
//
//    while ( n > 0 && !remainWorks.empty() )
//    {
//        int curRemainWork = *remainWorks.begin();
//        remainWorks.erase(curRemainWork);
//        if ( worksCount[curRemainWork] <= 0 )
//            continue;
//
//        int nextRemainWork = 0;
//        if ( !remainWorks.empty() )
//            nextRemainWork = *remainWorks.begin();
//
//        if ( (curRemainWork - nextRemainWork) * worksCount[curRemainWork] < n )
//        {
//            n -= (curRemainWork - nextRemainWork) * worksCount[curRemainWork];
//            worksCount[nextRemainWork] += worksCount[curRemainWork];
//            worksCount[curRemainWork] = 0;
//        }
//        else
//        {
//            if ( n / worksCount[curRemainWork] > 0 )
//            {
//                int newRemainWork = curRemainWork - (n / worksCount[curRemainWork]);
//                remainWorks.insert(newRemainWork);
//
//                worksCount[newRemainWork] += worksCount[curRemainWork];
//                n -= worksCount[curRemainWork] * (n / worksCount[curRemainWork]);
//                worksCount[curRemainWork] = 0;
//            }
//            else
//            {
//                worksCount[curRemainWork - 1] += n;
//                worksCount[curRemainWork] -= n;
//                break;
//            }
//        }
//    }
//
//    for ( auto iter = worksCount.begin(); iter != worksCount.end(); ++iter )
//    {
//        long long remainWork = static_cast<long long>(iter->first);
//        int remainWorkCount = iter->second;
//
//        answer += (remainWork * remainWork) * remainWorkCount;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int n = 4;
//    vector<int> works = { 4, 3, 3 };
//    cout << solution(n, works) << endl;
//
//    return 0;
//}