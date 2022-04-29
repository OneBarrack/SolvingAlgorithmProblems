//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.1 - 부족한 금액 계산하기
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
//long long solution(int price, int money, int count)
//{
//    long long resultPrice = -money;
//
//    for ( int i = 1; i <= count; ++i )
//    {
//        resultPrice += (long long)price * i;
//    }
//
//    return (resultPrice > 0) ? resultPrice : 0;
//}
//
//int main()
//{
//    int price = 3;
//    int money = 20;
//    int count = 4;
//    cout << solution(price, money, count) << endl;
//
//    return 0;
//}