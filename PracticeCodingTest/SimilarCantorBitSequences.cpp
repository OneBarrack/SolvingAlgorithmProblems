//#include <iostream>
//// 프로그래머스 연습문제 : 유사 칸토어 비트열
//// 2
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
//// 11011
//
//// 11011 11011 00000 11011 11011
//
//// 11011 11011 00000 11011 11011    11011 11011 00000 11011 11011   00000 00000 00000 00000 00000   11011 11011 00000 11011 11011   11011 11011 00000 11011 11011
//
////0 : 0                     0        0
////1 : 1 1 0 1 1             4        5
////2 : 4 4 0 4 4             16       25
////3 : 16 16 0 16 16         64       125
////4 : 64 64 0 64 64         128      625
////5 : 128 128 0 128 128     256      3125
//
//int GetLeftSideOneCount(int n, long long inputNum)
//{
//    if (n < 1) return 0;
//
//    int result = 0;
//
//    long long numLength = pow(5, n);
//    long long numOfPiece = pow(4, n - 1);
//    for (int i = 1; i <= 5; i++)
//    {         
//        if (i * numLength / 5 < inputNum)
//        {
//            if (i != 3)
//            {
//                result += numOfPiece;
//            }
//        }
//        else
//        {
//            if (i != 3)
//            {
//                result += GetLeftSideOneCount(n - 1, inputNum - ((i - 1) * numLength / 5));
//            }
//            break;
//        }
//    }
//
//    return result;
//}
//
//int solution(int n, long long l, long long r) {
//    return GetLeftSideOneCount(n, r + 1) - GetLeftSideOneCount(n, l);
//}
//
//int main(void) {
//    int n = 2;
//    long long l = 4;
//    long long r = 17;
//
//    //int n = 3;
//    //long long l = 30;
//    //long long r = 118;
//    ////answer = 39
//     
//    //int n = 3;
//    //long long l = 1;
//    //long long r = 125;
//    ////answer = 64
//
//    //int n = 2;
//    //long long l = 15;
//    //long long r = 15;
//    //answer = 0
//
//    cout << solution(n, l, r) << endl;
//
//    return 0;
//}
