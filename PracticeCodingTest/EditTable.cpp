//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv3 표 편집
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
//string solution(int n, int k, vector<string> cmd)
//{
//    string answer = "";
//
//    list<int> table;
//    for ( int i = 0; i < n; ++i )
//        table.push_back(i);
//
//    auto iter = table.begin();
//    advance(iter, k);
//
//    stack<pair<list<int>::iterator, int>> erasedRowStack;
//    int prevRow = k;
//    int curRow = k;
//    for ( string cmdLine : cmd )
//    {
//        char operation = cmdLine[0];
//        switch ( operation )
//        {
//            case 'U':
//            {
//                int num = stoi(cmdLine.substr(2));
//                for ( int i = 0; i < num; ++i, ++iter )
//                {
//                    if ( iter == table.begin() )
//                        break;
//                }
//            }
//            break;
//            case 'D':
//            {
//                int num = stoi(cmdLine.substr(2));
//                for ( int i = 0; i < num; ++i, ++iter )
//                {
//                    if ( next(iter) == table.end() )
//                        break;
//                }
//            }
//            break;
//            case 'C':
//            {
//                erasedRowStack.push(make_pair(next(iter), *iter));
//
//                iter = table.erase(iter);
//                if ( iter == table.end() )
//                    iter = prev(table.end());
//            }
//            break;
//            case 'Z':
//            {
//                if ( !erasedRowStack.empty() )
//                {
//                    auto insertIter = erasedRowStack.top().first;
//                    int insertNum = erasedRowStack.top().second;
//
//                    table.insert(insertIter, insertNum);
//                    erasedRowStack.pop();
//                }
//            }
//            break;
//            default: // Error case
//                break;
//        }
//    }
//
//    iter = table.begin();
//    for ( int i = 0; i < n; ++i )
//    {
//        if ( *iter == i )
//        {
//            answer += "O";
//            ++iter;
//        }
//        else
//        {
//            answer += "X";
//        }
//    }
//
//    return answer;
//}
//
//int main()
//{
//	int n = 8;
//	int k = 2;
//	vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z", "U 1", "C" };
//	cout << solution(n, k, cmd) << endl;
//
//	return 0;
//}