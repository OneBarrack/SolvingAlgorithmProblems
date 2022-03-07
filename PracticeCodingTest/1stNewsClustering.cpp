//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1 [1차] 뉴스 클러스터링
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
//
//using namespace std;
//
//int solution(string str1, string str2)
//{
//	int answer = 65536;
//
//	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
//	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
//
//	vector<string> intersectionJacaardSets;
//	vector<string> sumOfJaccardSets;
//	
//	list<string> str1JaccardList;
//	for ( int i = 0; i < str1.size(); ++i )
//	{
//		char c1 = str1[i];
//		char c2 = str1[i + 1];
//
//		if ( isalpha(c1) && isalpha(c2) )
//		{
//			string tempStr = "";
//			tempStr += c1;
//			tempStr += c2;
//
//			str1JaccardList.push_back(tempStr);
//			sumOfJaccardSets.push_back(tempStr);
//		}
//	}
//
//	for ( int i = 0; i < str2.size(); ++i )
//	{
//		char c1 = str2[i];
//		char c2 = str2[i + 1];
//
//		if ( isalpha(c1) && isalpha(c2) )
//		{
//			string tempStr = "";
//			tempStr += c1;
//			tempStr += c2;
//
//			auto str1JaccardSetIter = find(str1JaccardList.begin(), str1JaccardList.end(), tempStr);
//			if ( str1JaccardSetIter != str1JaccardList.end() )
//			{
//				str1JaccardList.erase(str1JaccardSetIter);
//				intersectionJacaardSets.push_back(tempStr);
//			}
//			else
//			{
//				sumOfJaccardSets.push_back(tempStr);
//			}
//		}
//	}
//
//	if ( !intersectionJacaardSets.empty() || !sumOfJaccardSets.empty() )
//	{
//		answer = (static_cast<double>(intersectionJacaardSets.size()) / sumOfJaccardSets.size()) * 65536;
//	}
//
//	return answer;
//}
//
//int main()
//{
//	//string str1 = "aa1+aa2";
//	//string str2 = "AAAA12";
//	string str1 = "E=M*C^2";
//	string str2 = "e=m*c^2";
//
//	cout << solution(str1, str2) << endl;
//
//	return 0;
//}