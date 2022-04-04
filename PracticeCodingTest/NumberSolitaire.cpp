//#include <iostream>
//// Codility 코딩테스트 연습 
//// Lv.Medium - Number Solitaire
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
//int solution(vector<int>& A)
//{
//    vector<int> dp(A.size());
//
//    int sum = A[0];
//    dp[0] = sum;
//    for ( int i = 1; i <= 6, i < A.size(); ++i )
//    {
//        dp[i] = sum + A[i];
//
//        if ( A[i] > 0 )
//            sum += A[i];
//    }
//
//    for ( int i = 7; i < A.size(); ++i )
//    {
//        priority_queue<int> pq;
//
//        for ( int j = i - 6; j < i; ++j )
//        {
//            pq.push(dp[j]);
//        }
//
//        dp[i] = pq.top() + A[i];
//    }
//
//    return dp[A.size() - 1];
//}
//
//int main()
//{
//    vector<int> A = { 1, -2, 0, 9, -1, -2 };
//    cout << solution(A) << endl;
//
//    return 0;
//}