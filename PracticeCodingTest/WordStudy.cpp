//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Bronze1 - Word Study
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
//Mississipi
//예제 출력 1
//?
//예제 입력 2
//zZa
//예제 출력 2
//Z
//예제 입력 3
//z
//예제 출력 3
//Z
//예제 입력 4
//baaa
//예제 출력 4
//A
//*/
//
//int main()
//{
//    string s;
//    getline(cin, s);
//
//    unordered_map<char, int> wordCounts;
//    for ( char& c : s )
//        ++wordCounts[tolower(c)];
//
//    multimap<int, char> orderedWordForCount;
//    for ( auto& wordInfo : wordCounts )
//        orderedWordForCount.insert(make_pair(wordInfo.second, wordInfo.first));
//     
//    char answer;
//    if ( orderedWordForCount.count(orderedWordForCount.rbegin()->first) == 1 )
//        answer = toupper(orderedWordForCount.rbegin()->second);
//    else
//        answer = '?';
//        
//    cout << answer;
//
//    return 0;
//}