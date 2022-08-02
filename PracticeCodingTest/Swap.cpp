//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.Gold3 - 1039. Swap
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
///*
//예제 입력 1
//16375 1
//예제 출력 1
//76315
//예제 입력 2
//132 3
//예제 출력 2
//312
//예제 입력 3
//432 1
//예제 출력 3
//423
//예제 입력 4
//90 4
//예제 출력 4
//-1
//예제 입력 5
//5 2
//예제 출력 5
//-1
//예제 입력 6
//436659 2
//예제 출력 6
//966354
//*/
//
//int main()
//{
//    int num, K;
//    cin >> num >> K;
//
//    int answer = -1;
//    int depth = 0;
//    vector<string> nums;
//    nums.push_back(to_string(num));
//
//    while ( !nums.empty() && depth < K )
//    {
//        vector<string> nextNums;
//        set<string> numSet;
//
//        while ( !nums.empty() )
//        {
//            string strNum = nums.back();
//            nums.pop_back();
//
//            for ( int i = 0; i < strNum.length() - 1; ++i )
//            {
//                for ( int j = i + 1; j < strNum.length(); ++j )
//                {
//                    if ( (i == 0 && strNum[j] == '0') )
//                        continue;
//
//                    string swappedStrNum = strNum;
//                    swap(swappedStrNum[i], swappedStrNum[j]);
//
//                    if ( numSet.find(swappedStrNum) == numSet.end() )
//                    {
//                        nextNums.push_back(swappedStrNum);
//                        numSet.insert(swappedStrNum);
//                    }
//                }
//            }
//        }
//
//        nums = nextNums;
//        ++depth;
//    }
//
//    if ( nums.empty() )
//        cout << answer;
//    else
//        cout << *max_element(nums.begin(), nums.end());
//
//    return 0;
//}