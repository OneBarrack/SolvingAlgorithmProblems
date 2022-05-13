//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// lv.2 - 행렬의 곱셈
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
//#include <unordered_set>
//#include <sstream>
//#include <numeric>
//
//using namespace std;
//
//vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
//{
//    // arr1 matrix size : L * M 
//    // arr2 matrix size : M * N
//    // (arr1 matrix * arr2 matrix) size : L * N
//
//    int L = arr1.size();
//    int M = arr1[0].size();
//    int N = arr2[0].size();
//    vector<vector<int>> answer(L, vector<int>(N));
//
//    for ( int l = 0; l < L; ++l )
//        for ( int m = 0; m < M; ++m )
//            for ( int n = 0; n < N; ++n )
//                answer[l][n] += arr1[l][m] * arr2[m][n];
//
//    return answer;
//}
//
//int main()
//{
//    vector<vector<int>> arr1 = { {2, 3, 2},{4, 2, 4},{3, 1, 4} };
//    vector<vector<int>> arr2 = { {5, 4, 3},{2, 4, 1},{3, 1, 1} };
//    // result [22, 22, 11], [36, 28, 18], [29, 20, 14]
//
//    vector<vector<int>> result = solution(arr1, arr2);
//
//    for ( vector<int> res : result )
//        for ( int r : res )
//            cout << r << endl;
//
//    return 0;
//}