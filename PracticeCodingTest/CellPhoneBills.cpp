//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Bronze3 - Cell Phone Bills
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
//3
//40 40 40
//예제 출력 1 
//M 45
//영식: 20 + 20 + 20 = 60
//민식: 15 + 15 + 15 = 45
//예제 입력 2 
//3
//61 61 61
//예제 출력 2 
//Y M 90
//예제 입력 3 
//2
//61 10
//예제 출력 3 
//Y 40
//*/
//
//int main()
//{
//    int N;
//    cin >> N;
//
//    vector<int> callingTimes(N);
//    for ( int i = 0; i < N; ++i )
//        cin >> callingTimes[i];
//
//    int FeeByYSPlan = 0;
//    int FeeByMSPlan = 0;
//    for ( int callingTime : callingTimes )
//    {         
//        FeeByYSPlan += 10 + callingTime / 30 * 10;
//        FeeByMSPlan += 15 + callingTime / 60 * 15;
//    }
//
//    if ( FeeByYSPlan < FeeByMSPlan )
//        cout << "Y " << FeeByYSPlan;
//    else if ( FeeByYSPlan > FeeByMSPlan )
//        cout << "M " << FeeByMSPlan;
//    else // ( FeeByYSPlan == FeeByMSPlan )
//        cout << "Y M " << FeeByYSPlan;
//
//    return 0;
//}