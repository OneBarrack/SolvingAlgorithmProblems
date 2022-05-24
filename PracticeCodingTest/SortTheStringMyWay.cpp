//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv 1. 문자열 내 마음대로 정렬하기
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
//
//using namespace std;
//
//vector<string> solution(vector<string> strings, int n)
//{
//    vector<string> answer;
//
//    map<char, multiset<string>> sMap;
//    for ( string& s : strings )
//        sMap[s[n]].insert(s);
//
//    for ( auto& val : sMap )
//        for ( string s : val.second )
//            answer.push_back(s);
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> strings = { "sun", "bed", "car" };
//    vector<string> result = solution(strings, 1);
//    for ( string res : result )
//        cout << res << endl;
//
//    return 0;
//}