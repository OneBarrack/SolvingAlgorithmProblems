//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.2 - 최솟값 만들기
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
//int solution(vector<int> A, vector<int> B)
//{
//    int answer = 0;
//    sort(A.begin(), A.end());
//    sort(B.rbegin(), B.rend());
//    for ( int i = 0; i < A.size(); ++i )
//        answer += A[i] * B[i];
//    return answer;
//}
//
//int main()
//{
//    vector<int> A = { 1, 4, 2 };
//    vector<int> B = { 5, 4, 4 };
//
//    cout << solution(A, B) << endl;
//
//    return 0;
//}