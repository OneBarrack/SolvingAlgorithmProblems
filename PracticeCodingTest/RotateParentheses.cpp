//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2 괄호 회전하기
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
//int solution(string s)
//{
//    int answer = 0;
//
//    unordered_map<char, char> matchedChar;
//    matchedChar['['] = '-';
//    matchedChar['{'] = '-';
//    matchedChar['('] = '-';
//    matchedChar[']'] = '[';
//    matchedChar['}'] = '{';
//    matchedChar[')'] = '(';
//
//    list<char> parenthesesList;
//    for ( char c : s )
//    {
//        parenthesesList.emplace_back(c);
//    }
//
//    for ( int i = 0; i < s.size(); ++i )
//    {
//        bool bValidString = true;
//        stack<char> stackForValidCheck;
//
//        for ( char c : parenthesesList )
//        {
//            if ( matchedChar[c] == '-' )
//            {
//                stackForValidCheck.push(c);
//            }
//            else if ( !stackForValidCheck.empty() && stackForValidCheck.top() == matchedChar[c] )
//            {
//                stackForValidCheck.pop();
//            }
//            else
//            {
//                bValidString = false;
//                break;
//            }            
//        }
//
//        if ( bValidString && stackForValidCheck.empty() )
//        {
//            ++answer;
//        }
//
//        char frontParentheses = parenthesesList.front();
//        parenthesesList.pop_front();
//        parenthesesList.emplace_back(frontParentheses);
//    }
//
//    return answer;
//}
//
//int main()
//{
//    //string s = { "[](){}" };
//    string s = { "(){[()]}][" };
//    cout << solution(s) << endl;
//
//    return 0;
//}