//#include <iostream>
//// 백준 코딩테스트 연습 
//// Lv.Silver1 - RGB 거리
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
///*
//예제 입력 5
//8
//71 39 44
//32 83 55
//51 37 63
//89 29 100
//83 58 11
//65 13 15
//47 25 29
//60 66 19
//예제 출력 5
//253
//*/
//int main()
//{
//    int N;
//    cin >> N;
//
//    vector<int> minCosts(3);
//    for ( int i = 0; i < N; ++i )
//    {
//        vector<int> costs(3);
//        cin >> costs[0] >> costs[1] >> costs[2];
//
//        minCosts = { 
//            costs[0] + min(minCosts[1], minCosts[2]),
//            costs[1] + min(minCosts[0], minCosts[2]),
//            costs[2] + min(minCosts[0], minCosts[1])
//        };
//    }
//
//    cout << *min_element(minCosts.begin(), minCosts.end());
//
//    return 0;
//}