//#include <iostream>
//// 백준 코딩테스트 연습 
//// Lv.Silver2 - Editor
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
//#include <numeric>
//#include <deque>
//
//using namespace std;
///*
//예제 입력 1
//abcd
//3
//P x
//L
//P y
//예제 출력 1
//abcdyx
//*/
//int main()
//{
//	string str;
//	cin >> str;
//
//	list<char> chars(str.begin(), str.end());
//	auto cursor = chars.end();
//
//	int M;
//	cin >> M;
//
//	while ( M > 0 )
//	{
//		char command;
//		cin >> command;
//
//		switch ( command )
//		{
//			case 'L':
//			{
//				if ( cursor != chars.begin() )
//					--cursor;
//
//				break;
//			}				
//			case 'D':
//			{
//				if ( cursor != chars.end() )
//					++cursor;
//
//				break;
//			}
//			case 'B':
//			{
//				if ( cursor != chars.begin() )
//					cursor = chars.erase(--cursor);
//
//				break;
//			}
//			case 'P':
//			{
//				char c;
//				cin >> c;
//
//				if ( cursor == chars.end() )
//					chars.push_back(c);
//				else
//					chars.insert(cursor, c);
//
//				break;
//			}
//		}
//
//		--M;
//	}
//
//	for ( char c : chars )
//		cout << c;
//
//	return 0;
//}