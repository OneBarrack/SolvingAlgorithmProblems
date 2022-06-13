//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv.Easy - Jim and the Orders
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
//vector<int> jimOrders(vector<vector<int>> orders)
//{
//    map<int, set<int>> sortedOrders;
//    for ( int i = 0; i < orders.size(); ++i )
//        sortedOrders[orders[i][0] + orders[i][1]].insert(i + 1);
//
//    vector<int> result;
//    for ( auto& sortedOrder : sortedOrders )
//    {
//        set<int>& sortedIndices = sortedOrder.second;
//        for ( auto iter = sortedIndices.begin(); iter != sortedIndices.end(); ++iter )
//            result.push_back(*iter);
//    }
//
//    return result;
//}
//
//int main()
//{
//    vector<vector<int>> orders = { {8, 1}, {4, 2}, {5, 6}, {3, 1}, {4, 3} };
//    vector<int> result = jimOrders(orders);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}