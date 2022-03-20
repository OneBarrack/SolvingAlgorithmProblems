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
//	string answer;
//	set<int> table;
//	stack<int> deletedRows;
//
//	for ( int i = 0; i < n; ++i )
//	{
//		table.insert(i);
//	}
//
//	set<int>::iterator rowIter = table.find(k);
//
//	for ( string cmdLine : cmd )
//	{
//		stringstream ss(cmdLine);
//		string command;
//		getline(ss, command, ' ');
//
//		if ( command == "U" )
//		{
//			getline(ss, command, ' ');
//			int count = stoi(command);
//			for ( int i = 0; i < count; ++i )
//			{
//				--rowIter;
//			}
//		}
//		else if ( command == "D" )
//		{
//			getline(ss, command, ' ');
//			int count = stoi(command);
//			for ( int i = 0; i < count; ++i )
//			{
//				++rowIter;
//			}
//		}
//		else if ( command == "C" )
//		{
//			deletedRows.push(*rowIter);
//			table.erase(rowIter++);
//
//			if ( rowIter == table.end() )
//			{
//				--rowIter;
//			}
//		}
//		else if ( command == "Z" )
//		{
//			int curRow = deletedRows.top();
//			deletedRows.pop();
//			table.insert(curRow);
//		}
//	}
//
//	answer.resize(n);
//	std::fill(answer.begin(), answer.end(), 'X');
//	for ( int row : table )
//		answer[row] = 'O';
//
//	return answer;
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