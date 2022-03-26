//#include <iostream>
//// Codility 코딩테스트 연습 
//// Medium level - Number of disc intersections
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
//int solution(vector<int>& A)
//{
//    if ( A.size() < 2 )
//        return 0;
//
//    int intersectCounts = 0;
//    map<long long, int> rightRadiusPoints;
//
//    ++rightRadiusPoints[A[0]];
//    for ( int i = 1; i < A.size(); ++i )
//    {
//        long long leftRadiusPoint = i - (long long)A[i];
//        long long rightRadiusPoint = i + (long long)A[i];
//
//        for ( auto iter = rightRadiusPoints.lower_bound(leftRadiusPoint); iter != rightRadiusPoints.end(); ++iter )
//        {
//            if ( leftRadiusPoint <= iter->first )
//            {
//                intersectCounts += iter->second;
//                if ( intersectCounts > 10000000 )
//                {
//                    return -1;
//                }
//            }
//        }
//        ++rightRadiusPoints[rightRadiusPoint];
//    }
//
//    return intersectCounts;
//}
//
//int main()
//{
//    vector<int> A = { 1, 2147483647, 0 };
//
//    cout << solution(A) << endl;
//
//    return 0;
//}