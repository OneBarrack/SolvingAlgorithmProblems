//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv.Medium - Extra Long Factorials
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
//void extraLongFactorials(int n)
//{
//    vector<int> answer;
//    answer.push_back(1);
//
//    for ( int i = 2; i <= n; ++i )
//    {
//        int carryNum = 0;
//
//        for ( int& num : answer )
//        {
//            int resultNum = (num * i) + (carryNum % 10);
//            carryNum /= 10;
//            num = resultNum % 10;
//            carryNum += resultNum / 10;
//        }
//
//        while ( carryNum > 0 )
//        {
//            answer.push_back(carryNum % 10);
//            carryNum /= 10;
//        }
//    }
//
//    for ( auto iter = answer.rbegin(); iter != answer.rend(); ++iter )
//        cout << *iter;
//}
//
//int main()
//{
//    int n = 30;
//    extraLongFactorials(n);
//
//    return 0;
//}