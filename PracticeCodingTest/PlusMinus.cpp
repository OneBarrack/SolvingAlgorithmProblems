//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv Easy. Plus Minus
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
//#include <numeric>
//
//using namespace std;
//
//void plusMinus(vector<int> arr)
//{
//    int positiveCount = 0;
//    int negativeCount = 0;
//    int zeroCount = 0;
//
//    for ( int& num : arr )
//    {
//        if ( num > 0 )
//            ++positiveCount;
//        else if ( num < 0 )
//            ++negativeCount;
//        else
//            ++zeroCount;
//    }
//
//    cout << (float)positiveCount / arr.size() << endl << (float)negativeCount / arr.size() << endl << (float)zeroCount / arr.size();
//}
//
//int main()
//{
//    vector<int> arr = { -4, 3, -9, 0, 4, 1 };
//    plusMinus(arr);
//
//    return 0;
//}