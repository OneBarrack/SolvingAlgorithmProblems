//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1. 크기가 작은 부분문자열
//
//#include <string>
//#include <vector>
//#include <queue>
//#include <set>
//#include <algorithm>
//#include <unordered_map>
//#include <numeric>
//#include <stack>
//#include <map>
//
//using namespace std;
//
//int solution(string t, string p) {
//    int answer = 0;
//
//    long long numP = stoll(p);
//    for (int i = 0; i <= t.length() - p.length(); i++)
//    {
//        string str = t.substr(i, p.length());
//        if (stoll(str) <= numP)
//        {
//            ++answer;
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//    string t = "3141592";
//    string p = "271";
//
//    cout << solution(t, p) << endl;
//
//    return 0;
//}
