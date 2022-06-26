//#include <iostream>
//// 백준 코딩테스트 연습 
//// Lv.Silver4 - Rotating Queue
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
//	int answer = 0;
//
//	int N, M;
//	cin >> N >> M;
//		
//	vector<int> arr(N);
//	for ( int i = 0; i < N; ++i )
//		arr[i] = i + 1;
//
//	for ( int i = 0; i < M; ++i )
//	{
//		int num;
//		cin >> num;
//
//		auto iter = find(arr.begin(), arr.end(), num);
//		vector<int> frontSubArr(arr.begin(), iter);
//		vector<int> backSubArr(iter + 1, arr.end());
//
//		answer += min(frontSubArr.size(), backSubArr.size() + 1);
//		backSubArr.insert(backSubArr.end(), frontSubArr.begin(), frontSubArr.end());
//		arr = backSubArr;
//	}
//	
//	cout << answer;
//
//	return 0;
//}