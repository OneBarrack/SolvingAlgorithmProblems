#include <iostream>
// 프로그래머스 코딩테스트 연습 
// Lv2 삼각 달팽이

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

vector<int> solution(int n)
{
    vector<int> answer((n * (n + 1)) / 2);

    int num = 1;
    int curIndex = 0;
    int loopCount = n - 1;

    stack<int> gaps;
    gaps.push(1);

    while ( true )
    {
        if ( loopCount <= 0 )
        {
            if ( loopCount == 0 )
            {
                answer[curIndex] = num;
            }
            break;
        }

        for ( int i = 0; i < loopCount; ++i )
        {            
            answer[curIndex] = num++;
            curIndex += gaps.top();
            gaps.push(gaps.top() + 1);
        }

        for ( int i = 0; i < loopCount; ++i )
        {
            answer[curIndex] = num++;
            curIndex++;
        }

        for ( int i = 0; i < loopCount; ++i )
        {
            answer[curIndex] = num++;
            if ( i == loopCount - 1 )
                break;

            curIndex -= gaps.top();
            gaps.pop();
        }

        loopCount -= 3;
        curIndex += gaps.top();

        stack<int> nextGaps;
        nextGaps.push(gaps.top() + 1);
        gaps = nextGaps;
    }

    return answer;
}

int main()
{
    //int n = 4;
    //int n = 5;
    int n = 6;

    vector<int> result = solution(n);
    for ( int res : result )
        cout << res << endl;

    return 0;
}