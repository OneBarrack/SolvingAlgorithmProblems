//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1 2016년
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
//string solution(int a, int b)
//{
//    vector<string> days = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
//    vector<int> months = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//    int dayCount = -1;
//    for ( int i = 0; i < a - 1; i++ )
//    {
//        dayCount += months[i];
//    }
//    dayCount += b;
//
//    return days[dayCount % 7];
//}
//
//int main()
//{
//    int a = 5;
//    int b = 24;
//    cout << solution(a, b) << endl;
//
//    return 0;
//}