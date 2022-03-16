//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1 신규 아이디 추천
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
//string solution(string new_id)
//{
//	// 1단계
//	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
//
//	// 2단계
//	for ( string::iterator it = new_id.begin(); it != new_id.end(); )
//	{
//		if ( !(isalpha(*it) || isdigit(*it) || *it == '-' || *it == '_' || *it == '.') )
//		{
//			new_id.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}
//
//	// 3단계
//	for ( string::iterator it = new_id.begin(); it != new_id.end(); )
//	{
//		if ( *it == '.' )
//		{
//			string::iterator rearIter = it + 1;
//			while ( rearIter != new_id.end() && *rearIter == '.' )
//			{
//				new_id.erase(rearIter);
//			}
//		}
//
//		++it;
//	}
//
//	// 4단계
//	if ( !new_id.empty() && (new_id.front() == '.') )
//	{
//		new_id.erase(new_id.begin());
//	}
//	if ( !new_id.empty() && (new_id.back() == '.') )
//	{
//		new_id.pop_back();
//	}
//
//	// 5단계
//	if ( new_id.empty() )
//	{
//		new_id = "a";
//	}
//
//	// 6단계
//	if ( new_id.size() >= 16 )
//	{
//		new_id.erase(new_id.begin() + 15, new_id.end());
//		if ( new_id.back() == '.' )
//		{
//			new_id.pop_back();
//		}
//	}
//
//	// 7단계
//	if ( new_id.size() <= 2 )
//	{
//		while ( new_id.size() < 3 )
//		{
//			new_id.push_back(new_id.back());
//		}
//	}
//
//	return new_id;
//}
//
//int main()
//{
//	string new_id = "...!@BaT#*..y.abcdefghijklm";
//    cout << solution(new_id) << endl;
//
//    return 0;
//}