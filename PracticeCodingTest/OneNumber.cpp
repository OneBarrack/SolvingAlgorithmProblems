//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Silver4 - 1165. One Number
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
///*
//예제 입력 1
//110
//예제 출력 1
//99
//예제 입력 2
//1
//예제 출력 2
//1
//예제 입력 3
//210
//예제 출력 3
//105
//예제 입력 4
//1000
//예제 출력 4
//144
//예제 입력 5
//500
//예제 출력 5
//119
//*/
//
//bool IsOneNumber(int n)
//{
//    if ( n < 100 )
//        return true;
//
//    int prevNum = n % 10; n /= 10;
//    int curNum = n % 10; n /= 10;
//    int fixedGapSize = curNum - prevNum;
//    
//    while ( n > 0 )
//    {
//        prevNum = curNum;
//        curNum = n % 10;
//
//        int gap = curNum - prevNum;
//        if ( gap != fixedGapSize )
//            return false;
//
//        n /= 10;
//    }
//
//    return true;
//}
//
//int main()
//{
//    int N;
//    cin >> N;
//
//    int answer = 0;
//    for ( int i = 1; i <= N; ++i )
//        if ( IsOneNumber(i) )
//            ++answer;
//
//    cout << answer;
//
//    return 0;
//}