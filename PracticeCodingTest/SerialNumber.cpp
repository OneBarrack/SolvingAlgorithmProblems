//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Silver3 - 1431. Serial Number
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
//5
//ABCD
//145C
//A
//A910
//Z321
//예제 출력 1
//A
//ABCD
//Z321
//145C
//A910
//예제 입력 2
//2
//Z19
//Z20
//예제 출력 2
//Z20
//Z19
//*/
//
//bool compare(string& a, string& b)
//{
//    // condition 1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
//    if ( a.length() != b.length() )
//        return a.length() < b.length();
//    
//    // condition 2. 만약 서로 길이가 같다면, A의 모든 자리수의 합과 
//    // B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. 
//    // (숫자인 것만 더한다)
//    int sumA = 0;
//    int sumB = 0;
//    for ( char& c : a ) if ( isdigit(c) ) sumA += (int)(c - '0');
//    for ( char& c : b ) if ( isdigit(c) ) sumB += (int)(c - '0');
//
//    if ( sumA != sumB )
//        return sumA < sumB;
//
//    // condition 3. 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 
//    // 비교한다. 숫자가 알파벳보다 사전순으로 작다.
//    return a < b;
//}
//
//int main()
//{
//    int N;
//    cin >> N;
//    cin.ignore();
//
//    vector<string> serialNumbers(N);
//    for ( int i = 0; i < N; ++i )
//        getline(cin, serialNumbers[i]);
//
//    sort(serialNumbers.begin(), serialNumbers.end(), compare);
//    for ( string& s : serialNumbers )
//        cout << s << "\n";
//
//    return 0;
//}