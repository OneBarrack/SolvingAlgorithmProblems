//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// ad 제거하기.
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
//vector<string> solution(vector<string> strArr) {
//    vector<string> answer;
//
//    for (string& str : strArr)
//    {
//        if (str.find("ad") == string::npos)
//        {
//            answer.push_back(str);
//        }
//    }
//
//    return answer;
//}
//
//int main(void) {
//    vector<string> strArr = {"and", "notad", "abcd"};
//    vector<string> result = solution(strArr);
//
//    for (string& res : result)
//        cout << res << endl;
//
//    return 0;
//}