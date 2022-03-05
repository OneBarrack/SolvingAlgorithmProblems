//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv3 추석 트래픽
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
//int ConvertStrTimeToMilliseconds(string time)
//{
//	int seconds = stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
//	return (seconds * 1000) + stoi(time.substr(9, 3));
//}
//
//int solution(vector<string> lines)
//{
//	int maxProcessingVolume = 1;
//
//	// Milliseconds 단위로 프로세스들의 Start, End Time 적재
//	multimap<int, int> processingTimes;
//
//	// 문자열 파싱
//	for ( string line : lines )
//	{
//		istringstream ss(line);
//		string strCopyLine;
//
//		int startMilliseconds;
//		int endMilliseconds;
//		int processingMilliseconds;
//
//		getline(ss, strCopyLine, ' ');
//		getline(ss, strCopyLine, ' ');
//		endMilliseconds = ConvertStrTimeToMilliseconds(strCopyLine);
//		
//		getline(ss, strCopyLine, 's');
//		if ( size_t pos = strCopyLine.find('.') != string::npos )
//		{
//			string stringTemp = strCopyLine.substr(0, pos);
//			processingMilliseconds = stoi(stringTemp) * 1000;
//			string strDecimal = strCopyLine.substr(pos + 1);
//			processingMilliseconds += stoi(strDecimal) * 100 / pow(10, strDecimal.size() - 1);
//		}
//		else
//		{
//			processingMilliseconds = stoi(strCopyLine) * 1000;
//		}
//		startMilliseconds = endMilliseconds - processingMilliseconds;
//
//		processingTimes.insert(make_pair(startMilliseconds, endMilliseconds));
//	}
//
//	// Process들의 시작시간 기준으로 정렬된 map을 돌며 
//	// 해당 Process의 시작시간과 이전 Process들의 끝시간의 갭이 1초인지 체크하며 처리량 계산
//	map<int, int>::iterator frontProcessIter, backProcessIter;
//	backProcessIter = ++processingTimes.begin();
//	for ( ; backProcessIter != processingTimes.end(); ++backProcessIter )
//	{
//		frontProcessIter = processingTimes.begin();
//		int processingVolume = 1;
//
//		for ( auto processIter = frontProcessIter; processIter != backProcessIter; )
//		{
//			// 처리시간은 시작시간과 끝시간을 포함하므로 갭은 -1000 + 1 = 999로 계산
//			if ( processIter->second < backProcessIter->first - 999 )
//			{
//				processingTimes.erase(processIter++);
//				if ( processIter == backProcessIter )
//				{
//					break;
//				}
//			}
//			else
//			{
//				++processingVolume;
//				++processIter;
//			}
//		}
//
//		if ( maxProcessingVolume < processingVolume )
//		{
//			maxProcessingVolume = processingVolume;
//		}
//	}
//
//	return maxProcessingVolume;
//}
//
//int main()
//{
//	//vector<string> lines = { "2016-09-15 20:59:57.421 0.351s",
//	//	"2016-09-15 20:59:58.233 1.181s",
//	//	"2016-09-15 20:59:58.299 0.8s",
//	//	"2016-09-15 20:59:58.688 1.041s",
//	//	"2016-09-15 20:59:59.591 1.412s",
//	//	"2016-09-15 21:00:00.464 1.466s",
//	//	"2016-09-15 21:00:00.741 1.581s",
//	//	"2016-09-15 21:00:00.748 2.31s",
//	//	"2016-09-15 21:00:00.966 0.381s",
//	//	"2016-09-15 21:00:02.066 2.62s" };
//
//	//vector<string> lines = { "2016-09-15 01:00:04.01 2.0s", "2016-09-15 01:00:07.000 2s" };
//
//	vector<string> lines = { 
//		"2016-09-15 01:00:04.01 2.0s", 
//	"2016-09-15 01:00:04.01 2.0s",
//	"2016-09-15 01:00:04.01 2.0s" ,
//	"2016-09-15 01:00:04.01 2.0s" };
//	
//
//	cout << solution(lines) << endl;
//
//	return 0;
//}