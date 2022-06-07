//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv.Medium - Minimun Loss
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
//int minimumLoss(vector<long> price)
//{
//    long minLoss = INT_MAX;
//
//    set<long> prices;
//    for ( long p : price )
//    {
//        auto iter = prices.insert(p).first;
//        if ( iter == prev(prices.end()) )
//            continue;
//
//        minLoss = min(minLoss, *next(iter) - *iter);
//    }
//
//    return static_cast<int>(minLoss);
//}
//
//int main()
//{
//    vector<long> price = { 20, 7, 8, 2, 5 };
//    cout << minimumLoss(price) << endl;
//
//    return 0;
//}