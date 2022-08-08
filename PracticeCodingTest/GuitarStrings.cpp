//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Silver4 - 1049. Guitar Strings
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
//4 2
//12 3
//15 4
//예제 출력 1
//12
//예제 입력 2
//10 3
//20 8
//40 7
//60 4
//예제 출력 2
//36
//예제 입력 3
//15 1
//100 40
//예제 출력 3
//300
//예제 입력 4
//17 1
//12 3
//예제 출력 4
//36
//예제 입력 5
//7 2
//10 3
//12 2
//예제 출력 5
//12
//*/
//
//int main()
//{
//    int N, M;
//    cin >> N >> M;
//
//    int totalMinCost = 1000;
//    int minPackagePrice = 1000;
//    int minPerPiecePrice = 1000;
//
//    // 6 piece per package
//    while ( M > 0 )
//    {
//        int packagePrice, perPiecePrice;
//        cin >> packagePrice >> perPiecePrice;
//
//        minPackagePrice = min(minPackagePrice, packagePrice);
//        minPerPiecePrice = min(minPerPiecePrice, perPiecePrice);
//
//        --M;
//    }
//
//    int minCost;
//    if ( minPackagePrice < minPerPiecePrice * 6 )
//    {
//        minCost = ((N / 6) * minPackagePrice);
//        
//        int remainPieceCount = N % 6;
//        if ( minPackagePrice < remainPieceCount * minPerPiecePrice )
//        {
//            minCost += minPackagePrice;
//        }
//        else
//        {
//            minCost += minPerPiecePrice * remainPieceCount;
//        }
//    }
//    else
//    {
//        minCost = N * minPerPiecePrice;
//    }
//
//    cout << minCost;
//
//    return 0;
//}