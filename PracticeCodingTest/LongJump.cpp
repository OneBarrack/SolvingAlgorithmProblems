#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 멀리 뛰기

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <numeric>

using namespace std;

long long solution(int n)
{
    vector<int> dp(n);
    dp[0] = 1;
    dp[1] = 2;
    for ( int i = 2; i < n; ++i )
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1234567;
    }

    return static_cast<long long>(dp[n - 1]);
}

int main()
{
    int n = 4;
    cout << solution(4) << endl;

    return 0;
}