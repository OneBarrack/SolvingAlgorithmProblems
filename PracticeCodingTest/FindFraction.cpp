//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Bronze4 - Basketball Game
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
//1
//예제 출력 1
//1/1
//예제 입력 2
//2
//예제 출력 2
//1/2
//예제 입력 3
//3
//예제 출력 3
//2/1
//예제 입력 4
//4
//예제 출력 4
//3/1
//예제 입력 5
//5
//예제 출력 5
//2/2
//예제 입력 6
//6
//예제 출력 6
//1/3
//예제 입력 7
//7
//예제 출력 7
//1/4
//예제 입력 8
//8
//예제 출력 8
//2/3
//예제 입력 9
//9
//예제 출력 9
//3/2
//예제 입력 10
//14
//예제 출력 10
//2/4
//*/
//
//int main()
//{
//    int X;
//    cin >> X;
//    
//    int n = 1;
//    while ( X > n )
//    {
//        X -= n;
//        ++n;
//    }
//    
//    if ( n & 1 )
//        cout << n + 1 - X << "/" << X;
//    else
//        cout << X << "/" << n + 1 - X;
//
//    return 0;
//}