//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv.Easy - Missing Numbers
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
//vector<int> missingNumbers(vector<int> arr, vector<int> brr)
//{
//    unordered_map<int, int> numCounts;
//    for ( int& num : arr )
//        ++numCounts[num];
//
//    for ( int& num : brr )
//        --numCounts[num];
//
//    vector<int> result;
//    for ( auto& val : numCounts )
//        if ( val.second < 0 )
//            result.push_back(val.first);
//
//    sort(result.begin(), result.end());
//    return result;
//}
//
//int main()
//{
//    vector<int> arr = { 203, 204, 205, 206, 207, 208, 203, 204, 205, 206 };
//    vector<int> brr = { 203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204 };
//
//    vector<int> result = missingNumbers(arr, brr);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}