//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2. N 진수 게임
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
//string IntToBaseNString(int num, int base)
//{
//    string baseNString = "";
//
//    while ( num > 0 )
//    {
//        int remainder = num % base;
//
//        if ( remainder < 10 )
//        {
//            baseNString = to_string(remainder) + baseNString;
//        }
//        else
//        {
//            string upperToTen = "";
//            upperToTen += ('A' + remainder - 10);
//            baseNString = upperToTen + baseNString;
//        }
//
//        
//        num /= base;
//    }
//
//    return baseNString;
//}
//
//string solution(int n, int t, int m, int p)
//{
//    string answer = "";
//    string baseNString = "0";    
//    int num = 1;
//
//    while ( t > 0 )
//    {
//        while ( p > baseNString.size() )
//        {
//            baseNString += IntToBaseNString(num++, n);
//        }
//
//        answer += baseNString[p - 1];
//        p += m;
//        --t;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    int n = 2;
//    int t = 4;
//    int m = 2;
//    int p = 1;
//    
//    cout << solution(n, t, m, p) << endl;
//
//    return 0;
//}