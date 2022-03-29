#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv1 최소 직사각형

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

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = INT_MAX;

    map<int, int> wallets;
    wallets.insert(make_pair(sizes[0][0], sizes[0][1]));
    wallets.insert(make_pair(sizes[0][1], sizes[0][0]));

    for ( int i = 1; i < sizes.size(); ++i )
    {
        map<int, int> curWallets;

        for ( auto iter = wallets.begin(); iter != wallets.end(); ++iter )
        {
            pair<int, int> walletSize1, walletSize2;

            walletSize1.first  = max(iter->first, sizes[i][0]);
            walletSize1.second = max(iter->second, sizes[i][1]);
            walletSize2.first  = max(iter->first, sizes[i][1]);
            walletSize2.second = max(iter->second, sizes[i][0]);

            if ( curWallets.find(walletSize1.first) != curWallets.end() )
            {
                curWallets[walletSize1.first] = min(curWallets[walletSize1.first], walletSize1.second);
            }
            else
            {
                curWallets.insert(walletSize1);
            }

            if ( curWallets.find(walletSize2.first) != curWallets.end() )
            {
                curWallets[walletSize2.first] = min(curWallets[walletSize2.first], walletSize2.second);
            }
            else
            {
                curWallets.insert(walletSize2);
            }
        }

        wallets = curWallets;
    }

    for ( auto iter = wallets.begin(); iter != wallets.end(); ++iter )
    {
        answer = min(answer, iter->first * iter->second);
    }

    return answer;
}

int main()
{
    vector<vector<int>> sizes = { {60, 50}, {30, 70}, {60, 30}, {80, 40} };
    
    cout << solution(sizes) << endl;

    //vector<int> result = solution(sizes);
    //for ( int res : result )
    //    cout << res << endl;

    return 0;
}