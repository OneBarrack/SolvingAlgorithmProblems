//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.3 - 최고의 집합
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
//vector<int> solution(int n, int s)
//{
//    vector<int> answer;
//
//    if ( s < n )
//    {
//        answer.push_back(-1);
//    }
//    else
//    {
//        while ( n > 0 )
//        {
//            int element = s / n;
//            answer.push_back(element);
//
//            s -= element;
//            --n;
//        }
//        sort(answer.begin(), answer.end());
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int n = 2;
//    int s = 9;
//
//    vector<int> result = solution(n, s);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}