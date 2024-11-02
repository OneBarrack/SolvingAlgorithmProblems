//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv2. 귤 고르기
//
//#include <string>
//#include <vector>
//#include <queue>
//#include <set>
//#include <algorithm>
//#include <unordered_map>
//#include <numeric>
//#include <stack>
//#include <map>
//
//using namespace std;
//
//int solution(int k, vector<int> tangerine) {
//    unordered_map<int, int> countMap;
//    for (int value : tangerine)
//    {
//        countMap[value]++;
//    }
//
//    vector<int> v;
//    for (pair<int, int> value : countMap)
//    {
//        v.push_back(value.second);
//    }
//    sort(v.begin(), v.end());
//
//    int removeCount = tangerine.size() - k;
//    for (int i = 0; i < v.size(); i++)
//    {
//        removeCount -= v[i];
//
//        if (removeCount == 0)
//        {
//            return v.size() - (i + 1);
//        }
//        else if (removeCount < 0)
//        {
//            return v.size() - i;
//        }
//    }
//
//    return 1;
//}
//
//int main()
//{
//    //vector<int> tangerine = { 1, 3, 2, 5, 4, 5, 2, 3 };
//    //int k = 6;
//
//    //vector<string> asdfadsf = { "97674223", "1195524421", "119" };
//    //sort(asdfadsf.begin(), asdfadsf.end());
//
//    vector<int> tangerine = { 1, 3, 2, 5, 4, 5, 2, 3 };
//    int k = 6;
//
//    int result = solution(k, tangerine);
//
//    cout << result << endl;
//
//    return 0;
//}
