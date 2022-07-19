//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Bronze2 - 1100. White Area
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
//.F.F...F
//F...F.F.
//...F.F.F
//F.F...F.
//.F...F..
//F...F.F.
//.F.F.F.F
//..FF..F.
//예제 출력 1
//1
//*/
//
//int main()
//{
//    int answer = 0;
//
//    for ( int i = 0; i < 8; ++i )
//    {
//        string line;
//        getline(cin, line);
//            
//        int whileAreaIndex = (i & 1) ? 1 : 0;
//
//        for ( ; whileAreaIndex < 8; whileAreaIndex += 2 )
//        {
//            if ( line[whileAreaIndex] == 'F' )
//                ++answer;
//        }
//    }
//
//    cout << answer;
//
//    return 0;
//}