//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv1 소수 만들기
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
//bool IsPrimeNum(int n)
//{
//    for ( int i = 2; i < n / 2; ++i )
//    {
//        if ( n % i == 0 )
//            return false;
//    }
//    return true;
//}
//
//int solution(vector<int> nums)
//{
//    int answer = 0;
//
//    for ( int i = 0; i < nums.size() - 2; ++i )
//        for ( int j = i + 1; j < nums.size() - 1; ++j )
//            for ( int k = j + 1; k < nums.size(); ++k )
//                if ( IsPrimeNum(nums[i] + nums[j] + nums[k]) )
//                    ++answer;
//
//    return answer;
//}
//
//int main()
//{
//    vector<int> nums = { 1, 2, 3, 4 };
//    cout << endl << solution(nums) << endl;
//
//    return 0;
//}