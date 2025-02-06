//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// 원하는 문자열 찾기
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
//
//using namespace std;
//
//int solution(string myString, string pat) {
//    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
//    transform(pat.begin(), pat.end(), pat.begin(), ::tolower);
//
//    return myString.find(pat) != string::npos;
//}
//
//int main(void) {
//    string myString = "AbCdEfG";
//    string pat = "aBc";
//
//    cout << solution(myString, pat) << endl;
//
//    return 0;
//}