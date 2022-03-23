//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv3 이중 우선순위 큐
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
//vector<int> solution(vector<string> operations)
//{
//    vector<int> answer(2);
//    multimap<int, int> numMap;
//    
//    for ( string operation : operations )
//    {
//        string operStr;
//        int num;
//
//        stringstream ss(operation);        
//        getline(ss, operStr, ' ');
//
//        string numStr;
//        getline(ss, numStr, ' ');
//        num = stoi(numStr);
//
//        if ( operStr == "I" )
//        {
//            numMap.insert(make_pair(num, 0));
//        }
//        else if ( !numMap.empty() ) // operStr == "D"
//        {
//            if ( num == 1 )
//            {
//                numMap.erase(prev(numMap.end()));
//            }
//            else
//            {
//                numMap.erase(numMap.begin());
//            }
//        }
//    }
//
//    if ( !numMap.empty() )
//    {
//        answer[0] = prev(numMap.end())->first;
//        answer[1] = numMap.begin()->first;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    vector<string> operations = { "I 16","I -5643","D -1","D 1", "D 1", "I 123", "D -1" };
//    vector<int> result = solution(operations);
//
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}