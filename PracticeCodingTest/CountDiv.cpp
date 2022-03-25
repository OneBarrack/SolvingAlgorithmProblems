//#include <iostream>
//// Codility 코딩테스트 연습 
//// Medium level - Count div
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
//int solution(int A, int B, int K)
//{
//    int answer = 0;
//    int left = (A % K == 0) ? A : A + (K - (A % K));
//    int right = B - (B % K);
//
//    if ( left <= right )
//    {
//        answer = (right - left) / K + 1;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int A = 6;
//    int B = 11;
//    int K = 2;
//
//    cout << solution(A, B, K) << endl;
//
//    return 0;
//}