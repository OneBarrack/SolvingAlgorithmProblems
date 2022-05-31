//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv Easy. Diagonal Difference
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
//int diagonalDifference(vector<vector<int>> arr)
//{
//    int leftToRightSum = 0;
//    int rightToLeftSum = 0;
//
//    int leftToRightIndex = 0;
//    int rightToLeftIndex = arr.size() - 1;
//    for ( int i = 0; i < arr.size(); ++i )
//    {
//        leftToRightSum += arr[i][leftToRightIndex++];
//        rightToLeftSum += arr[i][rightToLeftIndex--];
//    }
//
//    return abs(leftToRightSum - rightToLeftSum);
//}
//
//int main()
//{
//    vector<vector<int>> arr = {
//        {11, 2, 4},
//        {4, 5, 6},
//        {10, 8, -12}
//    };
//
//    cout << diagonalDifference(arr) << endl;
//
//    return 0;
//}