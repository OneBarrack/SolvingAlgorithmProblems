#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv.3 - 스티커 모으기 2

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>

using namespace std;

int solution(vector<int> sticker)
{
    if ( sticker.size() == 1 ) return sticker[0];
    if ( sticker.size() == 1 ) return max(sticker[0], sticker[1]);

    vector<pair<int, int>> dp(sticker.size());
    dp[0] = make_pair(sticker[0], 0);
    dp[1] = make_pair(0, sticker[1]);
    dp[2] = make_pair(dp[0].first + sticker[2], dp[0].second + sticker[2]);

    for ( int i = 3; i < sticker.size(); ++i )
    {
        dp[i] = make_pair(max(dp[i - 3].first + sticker[i], dp[i - 2].first + sticker[i]),
            max(dp[i - 3].second + sticker[i], dp[i - 2].second + sticker[i]));
    }

    return max(dp[sticker.size() - 3].first,
            max(dp[sticker.size() - 2].first,
             max(dp[sticker.size() - 2].second, dp[sticker.size() - 1].second)));
}

int main()
{
    vector<int> sticker = { 14, 6, 5, 11, 3, 9, 2, 10 };

    cout << solution(sticker) << endl;

    return 0;
}