//#include <iostream>
//// 해커랭크 코딩테스트 연습 
//// Lv.Medium - The Full Counting Sort
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
//void countSort(vector<vector<string>> arr)
//{
//    map<int, vector<string>> strMap;
//
//    for ( int i = 0; i < arr.size(); ++i )
//    {
//        int num = stoi(arr[i][0]);
//        string str = arr[i][1];
//
//        if ( i < arr.size() / 2 )
//            str = "-";
//
//        strMap[num].push_back(str);
//    }
//
//    for ( auto& val : strMap )
//        for ( string s : val.second )
//            cout << s << " ";
//}
//
//int main()
//{
//    vector<vector<string>> arr = {
//        {"0", "ab"},
//        {"6", "cd"},
//        {"0", "ef"},
//        {"6", "gh"},
//        {"4", "ij"},
//        {"0", "ab"},
//        {"6", "cd"},
//        {"0", "ef"},
//        {"6", "gh"},
//        {"0", "ij"},
//        {"4", "that"},
//        {"3", "be"},
//        {"0", "to"},
//        {"1", "be"},
//        {"5", "question"},
//        {"1", "or"},
//        {"2", "not"},
//        {"4", "is"},
//        {"2", "to"},
//        {"4", "the"}
//    };
//
//    countSort(arr);
//
//	return 0;
//}