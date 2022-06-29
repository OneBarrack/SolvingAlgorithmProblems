//#include <iostream>
//// 백준 코딩테스트 연습 
//// Lv.Silver3 - Printer Queue
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
//
//int main()
//{
//	int T;
//	cin >> T;
//		
//	while ( T > 0 )
//	{
//		int printCount = 0;
//
//		int N, M;
//		cin >> N >> M;
//
//		vector<pair<int, int>> dataQueue(N);
//		for ( int i = 0; i < N; ++i )
//		{
//			cin >> dataQueue[i].first;
//			dataQueue[i].second = i;
//		}
//		
//		while ( !dataQueue.empty() )
//		{
//			++printCount;
//			int maxPriority = (*max_element(dataQueue.begin(), dataQueue.end())).first;
//			auto printDataIter = find_if(dataQueue.begin(), dataQueue.end(), 
//				[&maxPriority](const pair<int, int>& element) { return element.first == maxPriority; });
//			if ( (*printDataIter).second == M )
//			{
//				cout << printCount << "\n";
//				break;
//			}
//
//			vector<pair<int, int>> frontSubArr(dataQueue.begin(), printDataIter);
//			vector<pair<int, int>> backSubArr(printDataIter + 1, dataQueue.end());
//
//			backSubArr.insert(backSubArr.end(), frontSubArr.begin(), frontSubArr.end());
//			dataQueue = backSubArr;
//		}
//
//		--T;
//	}
//		
//	return 0;
//}