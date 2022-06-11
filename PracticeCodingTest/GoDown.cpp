//#include <iostream>
//// 백준 코딩테스트 연습 
//// Lv.Gold5 - 내려가기
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
//3
//1 2 3
//4 5 6
//4 9 0
//*/
//
//int main()
//{
//    int N;
//    cin >> N;
//
//    vector<int> minScore(3);
//    vector<int> maxScore(3);
//    vector<int> prevMinScore(3);
//    vector<int> prevMaxScore(3);
//
//    while ( N-- > 0 )
//    {
//        vector<int> curScore(3);
//        cin >> curScore[0] >> curScore[1] >> curScore[2];
//
//        minScore[0]  = curScore[0] + min(prevMinScore[0], prevMinScore[1]);
//        minScore[1]  = curScore[1] + min({ prevMinScore[0], prevMinScore[1], prevMinScore[2] });
//        minScore[2]  = curScore[2] + min(prevMinScore[1], prevMinScore[2]);
//        prevMinScore = minScore;
//
//        maxScore[0]  = curScore[0] + max(prevMaxScore[0], prevMaxScore[1]);
//        maxScore[1]  = curScore[1] + max({prevMaxScore[0], prevMaxScore[1], prevMaxScore[2]});
//        maxScore[2]  = curScore[2] + max(prevMaxScore[1], prevMaxScore[2]);
//        prevMaxScore = maxScore;
//    }
//
//    cout << max({ maxScore[0] , maxScore[1] , maxScore[2] }) << " " << min({ minScore[0] , minScore[1] , minScore[2]});
//
//    return 0;
//}