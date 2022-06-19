//#include <iostream>
//// 백준 코딩테스트 연습 
//// Lv.Silver4 - Treasure
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
//예제 입력 3
//9
//5 15 100 31 39 0 0 3 26
//11 12 13 2 3 4 5 9 1
//예제 출력 3
//528
//*/
//int main()
//{
//    int N;
//    cin >> N;
//
//    vector<int> A(N), B(N);
//    for ( int i = 0; i < N; ++i ) cin >> A[i];
//    for ( int i = 0; i < N; ++i ) cin >> B[i];
//        
//    sort(A.begin(), A.end());
//    sort(B.begin(), B.end());
//
//    int answer = 0;
//    auto iterA = A.begin();
//    auto iterB = B.rbegin();
//    while ( iterA != A.end() )
//    {
//        answer += (*iterA) * (*iterB);
//        ++iterA;
//        ++iterB;
//    }
//
//    cout << answer;
//
//    return 0;
//}