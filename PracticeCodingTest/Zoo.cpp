//#include <iostream>
//// 백준 코딩테스트 연습 
//// Lv.Silver1 - Zoo
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
//5 4
//3 1
//3 2
//4 3
//5 3
//예제 출력 1
//1 2
//*/
//enum class ESettingCase
//{
//	EMPTY,
//	LEFT,
//	RIGHT
//};
//
//int main()
//{
//	int N;
//	cin >> N;
//
//	map<ESettingCase, int> m1;
//	m1[ESettingCase::EMPTY] = m1[ESettingCase::LEFT] = m1[ESettingCase::RIGHT] = 1;
//
//	for ( int i = 1; i < N; ++i )
//	{
//		map<ESettingCase, int> m2;
//		m2[ESettingCase::EMPTY] = (m1[ESettingCase::EMPTY] + m1[ESettingCase::LEFT] + m1[ESettingCase::RIGHT]) % 9901;
//		m2[ESettingCase::LEFT]  = (m1[ESettingCase::EMPTY] + m1[ESettingCase::RIGHT]) % 9901;
//		m2[ESettingCase::RIGHT] = (m1[ESettingCase::EMPTY] + m1[ESettingCase::LEFT]) % 9901;
//		m1 = m2;
//	}
//
//	cout << (m1[ESettingCase::EMPTY] + m1[ESettingCase::LEFT] + m1[ESettingCase::RIGHT]) % 9901;
//
//	return 0;
//}