//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1. 나누어 떨어지는 숫자 배열
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
//#include <unordered_map>
//#include <sstream>
//#include <numeric>
//#include <cmath>
//#include <cfloat>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr, int divisor)
//{
//    vector<int> answer;
//    for ( int n : arr ) if ( n % divisor == 0 ) answer.push_back(n);
//    sort(answer.begin(), answer.end());
//    return answer.empty() ? vector<int>(1, -1) : answer;
//}
//
//int main()
//{
//    vector<int> arr = { 5, 9, 7, 10 };
//    int divisor = 5;
//
//    vector<int> result = solution(arr, divisor);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}