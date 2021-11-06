#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv3 N으로 표현

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

int GetAttachedNum(int n, int digit)
{
    int num = 0;
    for ( int i = 0; i < digit; ++i )
    {
        num = (num * 10) + n;
    }
    return num;
}

int DP(vector<set<int>>& dpSetArr, int N, int number, int count)
{
    if ( count > 8 )
        return -1;

    set<int> resultSet;
    for ( int i = 1; i <= count / 2; ++i )
    {
        for ( int a : dpSetArr[i] )
        {
            for ( int b : dpSetArr[count - i] )
            {
                resultSet.insert(GetAttachedNum(N, count));
                resultSet.insert(a + b);
                resultSet.insert(a - b);
                resultSet.insert(b - a);
                resultSet.insert(a * b);
                if ( a != 0 ) resultSet.insert(b / a);
                if ( b != 0 ) resultSet.insert(a / b);                
            }
        }
    }

    if ( resultSet.find(number) != resultSet.end() )
        return count;
    
    dpSetArr.push_back(resultSet);
    return DP(dpSetArr, N, number, count + 1);
}

int solution(int N, int number)
{
    if ( N == number )
        return 1;

    int answer = 0;

    vector<set<int>> dp;
    
    // dp[0]
    set<int> numSet;
    numSet.insert(0);
    dp.push_back(numSet);
    
    // dp[1]
    numSet.clear();
    numSet.insert(N);
    dp.push_back(numSet);

    return DP(dp, N, number, 2);
}

int main()
{
    int N = 8;
    int number = 53;

    cout << solution(N, number) << endl;

    return 0;
}