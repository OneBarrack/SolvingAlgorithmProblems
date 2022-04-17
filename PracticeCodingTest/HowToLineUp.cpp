//#include <iostream>
//// 프로그래머스 코딩테스트 연습 
//// Lv.3 - 줄 서는 방법
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
//vector<int> solution(int n, long long k)
//{
//    vector<int> answer;
//    vector<int> num(n);
//    vector<long long> factorials(n);
//
//    num[0] = 1;
//    factorials[0] = 1;
//    for ( int i = 1; i < n; ++i )
//    {
//        num[i] = i + 1;
//        factorials[i] = i * factorials[i - 1];
//    }
//
//    --k;
//    for ( int i = n - 1; i > 0; --i )
//    {
//        int order = k / factorials[i];
//        k %= factorials[i];
//        answer.push_back(num[order]);
//        num.erase(num.begin() + order);
//    }
//    answer.push_back(num.front());
//
//    return answer;
//}
//
//int main()
//{
//    int n = 3;
//    long long k = 5;
//    
//    vector<int> result = solution(n, k);
//    for ( int res : result )
//        cout << res << endl;
//
//    return 0;
//}